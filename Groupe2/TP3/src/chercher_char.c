/**
 * couleur_compteur.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Écrivez un programme *chercher_char.c* qui créer un tableau de 10 phrases (un
 * tableau de tableau de caractères). Sans utilisant les fonctions de
 * bibliothèques standards ou externes, cherchez si une phrase est dans le
 * tableau ou pas.
 * */

#include <stdio.h>

#define DICO_SIZE 10
#define SEARCH_MAX_SIZE 128

int main() {
    char * dico[DICO_SIZE] = {
        "Hello World!",
        "Diamond hands",
        "IUT",
        "C'est long",
        "IUT > CPE",
        "Sinon les worlds c'est bien",
        "Rusty time",
        "Un film a conseiller ?",
        "Avant dernière phrase !",
        ". final",
    };

    char search[SEARCH_MAX_SIZE];
    short found = 1;
    printf("Votre recherche: ");
    scanf("%s", search);

    for (int entry_idx = 0; entry_idx < DICO_SIZE; entry_idx++) {
        int char_idx = 0;
        char * entry = dico[entry_idx];
        found = 1;

        // While not a the end of one string and both string match, continue
        while (found == 1 && (entry[char_idx] != *"\0" || search[char_idx] != *"\0")) {
            if (entry[char_idx] != search[char_idx]) {
                found = 0;
            } else {
                char_idx++;
            }
        }

        // Both strings are the same
        if (found == 1) {
            break;
        }
    }

    if (found == 1) {
        printf("Trouvé");
    } else {
        printf("Pas trouvé");
    }

    return 0;
}
