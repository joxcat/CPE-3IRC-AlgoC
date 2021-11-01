/**
 * etudiant.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Imaginez que vous gérez les notes de cinq étudiant.e.es. En utilisant
 * seulement des tableaux, écrivez un programme *etudiant.c* qui déclare,
 * initialise et affiche les détails de ces cinq étudiant.e.es. Pour chaque
 * étudiant.e, on est intéressé par son nom, son prénom, son adresse, et
 * ses notes dans 2 modules (Programmation en C, Système d'exploitation).
 * */

#include <stdio.h>
#include <stdlib.h>

#define PTR unsigned long int
#define SIZE_PTR sizeof(PTR)
#define SIZE_NOTE sizeof(char **) * 2
#define SIZE_ETU SIZE_PTR * 4

char ** create_note(char * matter, char * note) {
    char** new_note = malloc(SIZE_NOTE);

    new_note[0] = matter;
    new_note[1] = note;

    return new_note;
}

PTR * create_etu(char * name, char * surname, char * address, char *** notes) {
    PTR * etu = malloc(SIZE_ETU);

    etu[0] = (PTR)name;
    etu[1] = (PTR)surname;
    etu[2] = (PTR)address;
    etu[3] = (PTR)notes;

    return (PTR *)etu;
}

void print_etu(PTR * etu) {
    printf("%s %s - %s\n", (char *)etu[0], (char *)etu[1], (char *)etu[2]);

    char *** notes = (char ***)etu[3];
    char *** note = notes;
    while (*note != NULL) {
        printf("%s: %s\n", (*note)[0], (*note)[1]);
        note++;
    }
}

int main() {
    // [Nom, Prenom, Adresse, [[Prog C, Note], [System E, Note]]]
    // [char *, char *, char *, char ***]
    char ** notes_example[] = {
        create_note("Programmation en C", "20/20"),
        create_note("Système exploitation", "10/20"),
        NULL
    };
    char ** notes_example2[] = {
        create_note("Programmation en C", "0/20"),
        create_note("Système exploitation", "1/20"),
        NULL
    };

    PTR * etus[] = {
        create_etu("pa", "trick", "CPE", notes_example),
        create_etu("joh", "an", "Savoie", notes_example),
        create_etu("al", "exis", "Feyssine", notes_example),
        create_etu("si", "min", "SHamrock", notes_example2),
        create_etu("so", "mo", "Ici", notes_example2),
        NULL
    };


    PTR ** ptr_etu = etus;
    while (*ptr_etu != NULL) {
        print_etu(*ptr_etu);
        ptr_etu++;
    }

    return 0;
}
