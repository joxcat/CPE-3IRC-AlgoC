/**
 * chercher.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Écrivez un programme *chercher.c* en créant un tableau de 100 entiers et
 * puis en cherchant un entier dans ce tableau. Si l'entier est présent
 * dans le tableau, affichez le message 'entier présent'.
 * */

#include <stdio.h>

#define ARRAY_SIZE 100

int main() {
    int array[ARRAY_SIZE];
    int number_to_find;
    int number_to_find_pos = -1;

    printf("Please type the number you want to search: ");
    scanf("%d", &number_to_find);

    printf("[");
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        printf("%d,", array[idx]);

        if (array[idx] == number_to_find && number_to_find_pos < 0) {
            number_to_find_pos = idx;
        }
    }
    printf("]\n");

    if (number_to_find_pos >= 0) {
        printf("entier présent (premier index: %d)", number_to_find_pos);
    } else {
        printf("entier non présent");
    }

    return 0;
}
