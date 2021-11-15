/**
 * grand_petit.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Codez en C un programme *grand_petit.c* qui créer un tableau de 100
 * entiers et calculer
 *
 * -   a) Le numéro plus grand
 * -   b) Le numéro plus petit
 *
 * N'utilisez pas scanf.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

int main() {
    srand(time(NULL));
    int array[ARRAY_SIZE];
    // Fill array with random numbers
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        array[idx] = rand();
    }

    int smallest = array[0];
    int biggest = array[0];

    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        int current_element = array[idx];

        if (current_element < smallest) {
            smallest = current_element;
        }

        if (current_element > biggest) {
            biggest = current_element;
        }
    }

    printf("The biggest number %d\n", biggest);
    printf("The smallest number %d\n", smallest);

    return 0;
}
