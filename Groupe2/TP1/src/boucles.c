/**
 * boucles.c
 * Johan Planchon <johan.planchon@cpe.fr
 *
 *
 * Ecrivez un programme *boucles.c* qui utilise **for**, # et * et qui
 * affiche un triangle rectangle. La taille du triangle est dependent de la
 * valeur de la variable **compter** (**compter** < 4 inacceptable).
 * Exemple, si **compter** = 5, le programme affiche
 *
 * ```
 * *
 * * *
 * * # *
 * * # # *
 * * * * * *
 * ```
 *
 * Testez le code avec les différentes valeurs de compter. Ecrivez une
 * nouvelle version du code en utilisant **while** ou **do..while**.
 * */

#include <stdio.h>

int while_ver(int compter) {
    if (compter < 4) {
        // NOTE: Must be more than 4, specified in /Groupe2/TP1/TP1.md
        return 1;
    }

    int step = 0;
    while (step < compter) {
        printf("*");

        // NOTE: Last line is only stars
        if (step == compter - 1) {
            int sub_step = 0;
            // -2 => Minus first and last star
            while (sub_step < compter - 2) {
                printf(" *");
                sub_step++;
            }
        } else {
            int sub_step = 0;
            // -1 => Minus last star
            while (sub_step < step - 1) {
                printf(" #");
                sub_step++;
            }
        }

        if (step > 0) {
            printf(" *");
        }

        printf("\n");

        step++;
    }

    return 0;
}

int do_while_ver(int compter) {
    if (compter < 4) {
        // NOTE: Must be more than 4, specified in /Groupe2/TP1/TP1.md
        return 1;
    }

    int step = 0;
    do {
        printf("*");

        // NOTE: Last line is only stars
        if (step == compter - 1) {
            int sub_step = 0;
            // -2 => Minus first and last star
            do {
                printf(" *");
                sub_step++;
            } while (sub_step < compter - 2);
        } else if (step > 1) {
            int sub_step = 0;
            // -1 => Minus last star
            do {
                printf(" #");
                sub_step++;
            } while (sub_step < step - 1);
        }

        if (step > 0) {
            printf(" *");
        }

        printf("\n");

        step++;
    } while (step < compter);


    return 0;
}

int for_ver(int compter) {
    if (compter < 4) {
        // NOTE: Must be more than 4, specified in /Groupe2/TP1/TP1.md
        return 1;
    }

    for (int step = 0; step < compter; step++) {
        printf("*");

        // NOTE: Last line is only stars
        if (step == compter - 1) {
            // -2 => Minus first and last star
            for (int sub_step = 0; sub_step < compter - 2; sub_step++) {
                printf(" *");
            }
        } else {
            // -1 => Minus last star
            for (int sub_step = 0; sub_step < step - 1; sub_step++) {
                printf(" #");
            }
        }

        if (step > 0) {
            printf(" *");
        }

        printf("\n");
    }

    return 0;
}

int main() {
    int compter = 5;

    for_ver(compter);
    while_ver(compter);
    do_while_ver(compter);

    return 0;
}
