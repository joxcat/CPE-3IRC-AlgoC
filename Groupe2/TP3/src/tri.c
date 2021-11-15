/**
 * tri.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Écrivez un programme *tri.c* en créant d'abord un tableau de 100
 * entiers, puis en les triant par ordre croissant.
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

    // Deep copy array
    int sorted_array[ARRAY_SIZE];
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        sorted_array[idx] = array[idx];
    }


    // Sort sorted_array
    // idx_a start from the end of the array
    for (int idx_a = ARRAY_SIZE - 1; idx_a > 0; idx_a--) {
        // idx_b go from the start of the array to idx_a
        for (int idx_b = 0; idx_b < idx_a; idx_b++) {
            // if the current element is greater than the next
            if (sorted_array[idx_b] > sorted_array[idx_b + 1]) {
                // swap the two elements
                int tmp = sorted_array[idx_b];
                sorted_array[idx_b] = sorted_array[idx_b + 1];
                sorted_array[idx_b + 1] = tmp;
            }
        }
    }

    printf("[");
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        printf("%d,", array[idx]);
    }
    printf("]\n");

    printf("[");
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        printf("%d,", sorted_array[idx]);
    }
    printf("]\n");
    
    return 0;
}
