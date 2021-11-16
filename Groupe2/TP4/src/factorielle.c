/*
 * factorielle.c
 * Johan Planchon <johan.planchon@cpe.fr
 *
 * Une fonction récursive est une fonction qui s'appelle elle-même. Par
 * exemple, la fonction suivante calcule la factorielle d'un entier
 * naturel.
 * */

#include <stdio.h>

#define FACTO_MAX 10

int factorielle(int num) {
    if (num == 0) {
        return 1;
    } else {
        return (num * factorielle(num - 1));
    }
}

int main() {
    for (int facto = 0; facto < FACTO_MAX; facto++) {
        printf("Facto(%d) = %d\n", facto, factorielle(facto));
    }

    return 0;
}
