/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * serveur.c
 * Johan Planchon <johan.planchon@cpe.fr>
 */

#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "serveur.h"
#include "operator.h"
#include "combinator.h"

/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data) {
  int data_size = write (client_socket_fd, (void *) data, strlen(data));
      
  if (data_size < 0) {
    perror("erreur ecriture");
    return(EXIT_FAILURE);
  }

  return(0);
}

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd, double * total_sum) {
  struct sockaddr_in client_addr;
  char data[MAX_MESSAGE_LENGTH];

  unsigned int client_addr_len = sizeof(client_addr);
  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }

  while (1) {
    // la réinitialisation de l'ensemble des données
    memset(data, 0, sizeof(data));

    int data_size = 0;
    while (data_size == 0) {
      //lecture de données envoyées par un client
      data_size = read (client_socket_fd, (void *) data, sizeof(data));

      if (data_size < 0) {
        perror("erreur lecture");
        return(EXIT_FAILURE);
      }
    }

    /*
    * extraire le code des données envoyées par le client.
    * Les données envoyées par le client peuvent commencer par le mot "message:" ou un autre mot.
    */
    printf ("Données recu: %s\n", data);
    char code[MAX_CODE_LENGTH] = "";
    char * content = "";
    sscanf(data, "%s:", code);
    content = data + strlen(code);

    //Si le message commence par le mot: 'message:'
    if (strcmp(code, "message:") == 0) {
      char server_response[MAX_CONTENT_LENGTH];
      printf("Reponse au client: ");
      scanf("%s", server_response);

      char response[MAX_MESSAGE_LENGTH] = "message: ";
      strcat(response, server_response);

      renvoie_message(client_socket_fd, response);
    } else if (strcmp(code, "calcul:") == 0) {
      char server_response[MAX_MESSAGE_LENGTH] = "calcul: ";
      char * calc = recois_numeros_calcule(content, total_sum);
      strcat(server_response, calc);

      printf("= %s =\n", server_response);
      renvoie_message(client_socket_fd, server_response);
      free(calc);
    }
  }

  //fermer le socket 
  close(socketfd);

  return(0);
}

char * clean_msg(char * msg_start) {
  while (*msg_start == ' ') msg_start++;

  char * msg_end = msg_start + strlen(msg_start) - 1;
  while (msg_end > msg_start && (*msg_end == ' ' || *msg_end == '\n')) msg_end--;

  msg_end[1] = '\0';

  return msg_start;
}

CombinatorResult* take_operator(char * input) {
  return take_is(1, match_operator, input);
}

char * recois_numeros_calcule(char * calc, double * total_sum) {
  calc = clean_msg(calc);

  char * result = malloc(MAX_CONTENT_LENGTH * sizeof(char));

  CombinatorFn combinators[] = { take_operator, while_space, while_alphanumeric, while_space, while_alphanumeric, NULL };
  TupleResult* parse = tuple(combinators, calc);

  if (parse == NULL) {
    printf("ERROR Cannot parse the operation");
    exit(EXIT_FAILURE);
  }

  CombinatorResult* comb_op = parse[0];
  if (comb_op == NULL) {
    printf("OPERATOR NOT SUPPORTED");
    exit(EXIT_FAILURE);
  }
  char op = comb_op->match[0];

  CombinatorResult* comb_unparsed_num1 = parse[2];
  if (comb_unparsed_num1 == NULL) {
    printf("num1 unparsable");
    exit(EXIT_FAILURE);
  }
  char* unparsed_num1 = comb_unparsed_num1->match;
  if (strlen(unparsed_num1) == 0) {
    printf("num1 was not provided");
    exit(EXIT_FAILURE);
  }

  CombinatorResult* comb_unparsed_num2 = parse[4];
  char* unparsed_num2;
  if (comb_unparsed_num2 == NULL) {
    unparsed_num2 = "";
  } else {
    unparsed_num2 = comb_unparsed_num2->match;
  }

  double num1;
  double num2;

  if (strcmp(unparsed_num1, "somme") == 0) {
    num1 = *total_sum;
  } else {
    num1 = strtod(unparsed_num1, NULL);
  }

  if (strcmp(unparsed_num2, "somme") == 0) {
    num2 = *total_sum;
  } else {
    num2 = strtod(unparsed_num2, NULL);
  }

  switch (op) {
    case '+': {
      double calc_result = somme(num1, num2);
      *total_sum += calc_result;
      sprintf(result, "%f", calc_result);
      break;
    }
    case '-': {
      double calc_result = difference(num1, num2);
      *total_sum += calc_result;
      sprintf(result, "%f", calc_result);
      break;
    }
    case '*': {
      double calc_result = produit(num1, num2);
      *total_sum += calc_result;
      sprintf(result, "%f", calc_result);
      break;
    }
    case '/': {
      double calc_result = quotient(num1, num2);
      *total_sum += calc_result;
      sprintf(result, "%f", calc_result);
      break;
    }
    case '%': {
      int calc_result = modulo((int)num1, (int)num2);
      *total_sum += calc_result;
      sprintf(result, "%d", calc_result);
      break;
    }
    case '&': {
      int calc_result = et((int)num1, (int)num2);
      *total_sum += calc_result;
      sprintf(result, "%d", calc_result);
      break;
    }
    case '|': {
      int calc_result = ou((int)num1, (int)num2);
      *total_sum += calc_result;
      sprintf(result, "%d", calc_result);
      break;
    }
    case '~': {
      int calc_result = neg((int)num1);
      *total_sum += calc_result;
      sprintf(result, "%d", calc_result);
      break;
    }
    case '=': {
      sprintf(result, "%f", num1);
      *total_sum = num1;
      break;
    }
  }

  return result;
}

int main() {

  int socketfd;
  int bind_status;

  struct sockaddr_in server_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Relier l'adresse à la socket
  bind_status = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if (bind_status < 0 ) {
    perror("bind");
    return(EXIT_FAILURE);
  }
 
  // Écouter les messages envoyés par le client
  listen(socketfd, 10);

  //Lire et répondre au client
  // NOTE: Sum from the start of the program
  double total_sum = 0;
  recois_envoie_message(socketfd, &total_sum);

  return 0;
}
