/**
 * recherche_dichotomique.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Regardez l'article sur la recherche dichotomique:
 * <https://fr.wikipedia.org/wiki/Recherche_dichotomique>. Écrivez un
 * programme *recherche_dichotomique.c* en créant un tableau de 100
 * entiers et puis en cherchant un entier dans le tableau déjà tri en ordre
 * croissant. Si l'entier est présent dans le tableau, affichez le message
 * 'entier présent'.
 * */

#include <stdio.h>

#define ARRAY_SIZE 10

int main() {
    int array[ARRAY_SIZE];

    // Sort array
    for (int idx_a = ARRAY_SIZE - 1; idx_a > 0; idx_a--) {
        for (int idx_b = 0; idx_b < idx_a; idx_b++) {
            if (array[idx_b] > array[idx_b + 1]) {
                int tmp = array[idx_b];
                array[idx_b] = array[idx_b + 1];
                array[idx_b + 1] = tmp;
            }
        }
    }

    // Search
    int number_to_find;
    int number_to_find_pos = -1;

    printf("Please type the number you want to search: ");
    scanf("%d", &number_to_find);

    int array_view_start = 0;
    int array_view_stop = ARRAY_SIZE;

    // Break if number found
    while (number_to_find_pos < 0) {
        int central_element_idx = (array_view_stop - array_view_start) / 2 + array_view_start;

        // If the view is a single element and is not the one we search break;
        if (array_view_stop - array_view_start == 1 && array[central_element_idx] != number_to_find) {
            break;
        } else if (array[central_element_idx] < number_to_find) {
            array_view_start = central_element_idx;
        } else if (array[central_element_idx] > number_to_find) {
            array_view_stop = central_element_idx;
        } else {
            number_to_find_pos = central_element_idx;
        }
    }

    // Print array
    printf("[");
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        printf("%d,", array[idx]);
    }
    printf("]\n");

    if (number_to_find_pos >= 0) {
        printf("entier présent (index: %d)", number_to_find_pos);
    } else {
        printf("entier non présent");
    }

    return 0;
}
