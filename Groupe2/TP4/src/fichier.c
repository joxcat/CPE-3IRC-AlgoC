/**
 * fichier.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Écrivez un programme en créant deux fichiers *fichier.c* et fichier.h.
 * Dans fichier.h, déclarez les fonctions lire_fichier(char
 * *nom_de_fichier) et ecrire_dans_fichier(char *nom_de_fichier,
 * char *message). La fonction lire_fichier prend le nom du fichier et
 * affiche son contenu à l'écran. ecrire_dans_fichier prend le nom du
 * fichier et écrire le message saisi par l'utilisateur dans le fichier.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESSAGE_MAX_LENGTH 140

void lire_fichier(char * nom_de_fichier) {
    FILE * fptr = fopen(nom_de_fichier, "r");
    char content[MESSAGE_MAX_LENGTH];

    if (fptr == NULL) {
        printf("Une erreur est survenue lors de la lecture du fichier (%s)", nom_de_fichier);
        exit(1);
    }

    fscanf(fptr, "%s", content);

    fclose(fptr);
}

void ecrire_dans_fichier(char * nom_de_fichier, char * message) {
    FILE * fptr = fopen(nom_de_fichier, "w");

    if (fptr == NULL) {
        printf("Une erreur est survenue lors de la lecture du fichier (%s)", nom_de_fichier);
        exit(1);
    }

    fputs(message, fptr);

    fclose(fptr);
}

void trim_end(char * str) {
    if ((strlen(str) > 0) && (str[strlen(str) - 1] == '\n')) {
        str[strlen(str) - 1] = '\0';
    }
}

int main() {
    char user_message[MESSAGE_MAX_LENGTH];
    printf("Votre message (tweet) en 140 charactères :\n");
    fgets(user_message, MESSAGE_MAX_LENGTH, stdin);
    trim_end(user_message);

    char filename[FILENAME_MAX];
    printf("Le nom de votre fichier de sauvegarde :\n");
    fgets(filename, FILENAME_MAX, stdin);
    trim_end(filename);

    ecrire_dans_fichier(filename, user_message);
    lire_fichier(filename);

    return 0;
}
