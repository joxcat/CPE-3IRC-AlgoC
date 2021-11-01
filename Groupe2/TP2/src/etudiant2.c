/**
 * etudiant2.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Écrivez un programme *etudiant2.c* pour la gestion de données
 * étudiant.e.es (5 étudiant.e.es) en utilisant struct. Les détails pour
 * chaque étudiant.e restent les mêmes comme pour l'exercice précédente
 * (nom, prénom etc.). Vous pouvez utiliser strcpy pour initialiser les
 * noms, prénoms etc.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Note {
    char matter[32];
    char note[8];
};

struct Etu {
    char name[32];
    char surname[32];
    char address[64];
    struct Note notes[32];
};

int main() {
    struct Etu Etu1;
    struct Etu Etu2;

    strcpy(Etu1.name, "C'est");
    strcpy(Etu1.surname, "Long");
    strcpy(Etu1.address, "CPE");
    struct Note Note1;
    strcpy(Note1.matter, "C");
    strcpy(Note1.note, "0/20");
    Etu1.notes[0] = Note1;

    strcpy(Etu2.name, "Docteur");
    strcpy(Etu2.surname, "Who");
    strcpy(Etu2.address, "Tardis");
    struct Note Note2;
    strcpy(Note2.matter, "Linux");
    strcpy(Note2.note, "1/20");
    Etu2.notes[0] = Note2;


    struct Etu etus[] = { Etu1, Etu2 };

    for (int idx = 0; idx < 2; idx++) {
        struct Etu etu = etus[idx];

        printf("%s %s - %s\n", etu.name, etu.surname, etu.address);

        void ** ptr = (void *)etu.notes;
        while (*ptr != NULL) {
            struct Note note = *(struct Note *)ptr;
            printf("%s: %s\n", note.matter, note.note);
            ptr++;
        }
    }

    return 0;
}
