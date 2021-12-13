/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * client.c
 * Johan Planchon <johan.planchon@cpe.fr>
 */

#include <dirent.h>
#include <linux/limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"
#include "operator.h"
#include "serveur.h"

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

char * envoie_recois_message(int socketfd, char * message) {
  char data[MAX_MESSAGE_LENGTH];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // Demandez à l'utilisateur d'entrer un message
  if (message == NULL) {
    printf("Votre message (max 1000 caracteres): ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
  }

  if (match_operator(message[0]) == 1) {
    strcpy(data, "calcul: ");
    strcat(data, message);
  } else {
    strcpy(data, "message: ");
    strcat(data, message);
  }

  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    exit(EXIT_FAILURE);
  }

  /* printf("Message recu: %s\n", data); */

  if (strstr(data, "calcul:") != NULL) {
    char * result = malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    sscanf(data, "calcul: %s\n", result);
    return result;
  } else {
    return NULL;
  }
}

struct Etu {
  char * id;
  DIR * dir;
  char * path;
  int count_notes;
  double sum_notes;
};

int calculs_etus(int socketfd, char * etus_path) {
  struct Etu etus[MAX_ETUS];
  int last_etu = 0;
  int etu_count = 0;
  DIR * initial_dir = opendir(etus_path);
  struct dirent * entry;
  char message[MAX_MESSAGE_LENGTH];
  char * response;

  if (initial_dir == NULL) {
    perror("Cannot read initial directory");
    exit(EXIT_FAILURE);
  }

  // Find and open students dirs
  while ((entry = readdir(initial_dir))) {
    if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".") != 0 && entry->d_type == DT_DIR) {
      struct Etu etu = { .id = entry->d_name, .path = malloc(PATH_MAX * sizeof(char)), .count_notes = 0, .sum_notes = 0 };
      sprintf(etu.path, "%s/%s", etus_path, entry->d_name);

      etu.dir = opendir(etu.path);

      etus[last_etu] = etu;
      last_etu++;
    }
  }
  etu_count = last_etu - 1;

  // Calculate sums and parse students notes
  last_etu = -1;
  while ((last_etu++) < etu_count) {
    // reset somme
    envoie_recois_message(socketfd, "= 0");

    while ((entry = readdir(etus[last_etu].dir))) {
      if (strstr(entry->d_name, ETU_NOTE_EXTENSION) != NULL) {
        char path[PATH_MAX];
        sprintf(path, "%s/%s", etus[last_etu].path, entry->d_name);

        FILE * fptr = fopen(path, "r");
        char * buffer = malloc(sizeof(char) * MAX_BUFFER_SIZE);
        int buffer_offset = 0;

        if (fptr == NULL) {
            printf("Une erreur est survenue lors de la lecture du fichier (%s)", entry->d_name);
            exit(EXIT_FAILURE);
        }

        // Read line per READ_BUFFER_SIZE bytes chunks
        char * line_buffer = malloc(READ_BUFFER_SIZE);
        while (fgets(line_buffer, READ_BUFFER_SIZE, fptr) != NULL) {
            strcpy(buffer + buffer_offset, line_buffer);
            buffer_offset += strlen(line_buffer);
        }

        fclose(fptr);

        etus[last_etu].count_notes++;
        sprintf(message, "+ 0 %s", buffer);
        envoie_recois_message(socketfd, message);
      }
    }

    response = envoie_recois_message(socketfd, "= somme");
    etus[last_etu].sum_notes = strtof(response, NULL);
  }


  // Calc averages and print results
  last_etu = -1;
  while ((last_etu++) < etu_count) {
    struct Etu etu = etus[last_etu];
    sprintf(message, "/ %f %d", etu.sum_notes, etu.count_notes);
    response = envoie_recois_message(socketfd, message);
    double average = strtof(response, NULL);

    printf("Etu %s:\n- nb notes = %d\n- sum = %f\n- average = %f\n", etu.id, etu.count_notes, etu.sum_notes, average);
  }

  return 0;
}

int main(int argc, char ** argv) {
  int socketfd;

  struct sockaddr_in server_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  //demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if ( connect_status < 0 ) {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  // appeler la fonction pour envoyer un message au serveur
  if (argc >= 2) {
    calculs_etus(socketfd, argv[1]);
  } else {
    envoie_recois_message(socketfd, NULL);
  }

  close(socketfd);
}
