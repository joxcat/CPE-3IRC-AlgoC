/**
 * conditions.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Ecrivez un programme *conditions.c* qui utilise les boucles (**for**,
 * **while** ou **do..while**) et les branchements inconditionnels (break
 * ou continue) pour l'affichage de numéros <= 1000 qui sont divisible par :
 *
 * a.  2 et 15
 * b.  103 ou 107
 * c.  7 ou 5, mais pas par 3
 * */

#include <stdio.h>

const int MAX_NUM = 1000;

int main() {
    // Can be divided by 2 and 15
    for (int current_num = 0; current_num <= MAX_NUM; current_num++) {
        if (current_num % 2 == 0 && current_num % 15 == 0) {
            printf("Can be divided by 2 and 15: %d\n", current_num);
        }
    }

    // Can be divided by 103 or 107
    int current_num = 0;
    while (current_num <= MAX_NUM) {
        if (current_num % 103 == 0 || current_num % 107 == 0) {
            printf("Can be divided by 103 or 107: %d\n", current_num);
        }
        
        current_num++;
    }

    // Can be divided by 7 or 5 but not by 3
    current_num = 0;
    do {
        if ((current_num % 7 == 0 || current_num % 5 == 0) && current_num % 3 != 0) {
            printf("Can be divided by 7 or 5 but not by 3: %d\n", current_num);
        }

        current_num++;
    } while (current_num < MAX_NUM);

    return 0;
}
