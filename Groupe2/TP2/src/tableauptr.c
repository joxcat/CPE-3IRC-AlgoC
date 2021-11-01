/**
 * tableauptr.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Créez un programme *tableauptr.c* et écrivez le code pour créer deux
 * tableaux différents : int et float. Remplissez les valeurs aléatoires.
 * Pour les deux tableaux, si l'indice est divisible par 2, multipliez la
 * valeur à cette position par 3. N'utilisez pas la notation indicielle
 * pour parcourir les tableaux (par exemple, i [3], i [5] etc.).
 * Utilisez les pointeurs.
 * */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * gen_rand_int_arr(int size) {
    int * result = malloc(sizeof(int) * (size + 1));

    for (int idx = 0; idx < size; idx++) {
        int rand_num = rand() % 1000;

        printf("%d", rand_num);
        if ((long int)(result + idx * sizeof(int)) % 2 == 0) {
            rand_num *= 3;
        }

        *(result + idx * sizeof(int)) = rand_num % INT_MAX;
    }

    return result;
}

float * gen_rand_float_arr(int size) {
    float * result = malloc(sizeof(float) * (size + 1));

    for (int idx = 0; idx < size; idx++) {
        float rand_num = (float)(rand() % 1000) / 100;

        if ((long int)(result + idx * sizeof(float)) % 2 == 0) {
            rand_num *= 3;
        }

        *(result + idx * sizeof(float)) = rand_num;
    }

    return result;
}

int main() {
    srand(time(NULL));

    int integers_len = 5;
    int boats_len = 3;

    int * intergers = gen_rand_int_arr(integers_len);
    float * boats = gen_rand_float_arr(boats_len);

    for (int idx = 0; idx < integers_len; idx++) {
        printf("%d ", *(intergers + sizeof(int) * idx));
    }

    for (int idx = 0; idx < boats_len; idx++) {
        printf("%f ", *(boats + sizeof(float) * idx));
    }
}
