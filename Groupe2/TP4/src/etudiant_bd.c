/*
 * etudiant_bd.c
 * Johan Planchon <johan.planchon@cpe.fr
 *
 * En réutilisant le code de l'*etudiant2.c* (TP2) et *fichier.c*, écrivez
 * un fichier *etudiant_bd.c* qui sauvegarde les noms, prénoms, adresses,
 * et les notes dans un fichier etudiant.txt pour 5 étudiant(e)s (une ligne
 * pour chaque étudiant(e)). Testez votre code. Cette fois, vous demanderez
 * à l'utilisateur en utilisant scanf pour les détails de chaque étudiant.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ETU_NUMBER 5

#define NOTE_MAX_LENGTH 8

#define ETU_NAME_MAX_LENGTH 32
#define ETU_SURNAME_MAX_LENGTH 32
#define ETU_ADDRESS_MAX_LENGTH 64
#define ETU_NOTES_MAX_LENGTH 2

#define DB_LINE_MAX_LENGTH (ETU_NAME_MAX_LENGTH + ETU_SURNAME_MAX_LENGTH + ETU_ADDRESS_MAX_LENGTH + ETU_NOTES_MAX_LENGTH * NOTE_MAX_LENGTH) * sizeof(char)

struct Etu {
    char name[ETU_NAME_MAX_LENGTH];
    char surname[ETU_SURNAME_MAX_LENGTH];
    char address[ETU_ADDRESS_MAX_LENGTH];
    char notes[ETU_NOTES_MAX_LENGTH][NOTE_MAX_LENGTH];
};

char * etu_to_string(struct Etu etu) {
    int offset = 0;
    char * etu_as_string = malloc(DB_LINE_MAX_LENGTH);

    etu_as_string = etu.name;
    offset += strlen(etu.name);
    strcpy(etu_as_string + offset, ", ");
    offset += 2;

    strcpy(etu_as_string + offset, etu.surname);
    offset += strlen(etu.surname);
    strcpy(etu_as_string + offset, ", ");
    offset += 2;

    strcpy(etu_as_string + offset, etu.address);
    offset += strlen(etu.address);
    strcpy(etu_as_string + offset, ", ");
    offset += 2;

    for (int notes_idx = 0; notes_idx < ETU_NOTES_MAX_LENGTH; notes_idx++) {
        strcpy(etu_as_string + offset, etu.notes[notes_idx]);
        offset += strlen(etu.notes[notes_idx]);

        if (notes_idx < ETU_NOTES_MAX_LENGTH - 1) {
            strcpy(etu_as_string + offset, ", ");
            offset += 2;
        }
    }

    return etu_as_string;
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

int main() {
    struct Etu * etus = malloc(sizeof(struct Etu) * ETU_NUMBER);

    char db_name[FILENAME_MAX];
    printf("Nom de la BD : ");
    scanf("%[^\n]", db_name);
    while (getchar() != '\n') {}

    // Create the Etus
    for (int etus_idx = 0; etus_idx < ETU_NUMBER; etus_idx++) {
        printf("=== Etudiant n%d ===\n", etus_idx);

        printf("Nom: ");
        scanf("%[^\n]", etus[etus_idx].name);
        while (getchar() != '\n') {}

        printf("Prénom: ");
        scanf("%[^\n]", etus[etus_idx].surname);
        while (getchar() != '\n') {}

        printf("Adresse: ");
        scanf("%[^\n]", etus[etus_idx].address);
        while (getchar() != '\n') {}

        for (int notes_idx = 0; notes_idx < ETU_NOTES_MAX_LENGTH; notes_idx++) {
            printf("Note (%d): ", notes_idx);
            scanf("%[^\n]", etus[etus_idx].notes[notes_idx]);
            while (getchar() != '\n') {}
        }

        if (etus_idx < ETU_NUMBER - 1) printf("\n");
    }

    // Reserve the max size the DB can take with ETU_NUMBER
    char content[DB_LINE_MAX_LENGTH * ETU_NUMBER];
    int content_offset = 0;

    // Convert the Etus to text
    for (int etus_idx = 0; etus_idx < ETU_NUMBER; etus_idx++) {
        char * etu_as_string = etu_to_string(etus[etus_idx]);

        // Add the etu
        strcpy(content + content_offset, etu_as_string);
        content_offset += strlen(etu_as_string);

        // Add the newline at the end of each etu line
        strcpy(content + content_offset, "\n");
        content_offset += 1;
    }

    // Write the DB
    ecrire_dans_fichier(db_name, content);

    return 0;
}
