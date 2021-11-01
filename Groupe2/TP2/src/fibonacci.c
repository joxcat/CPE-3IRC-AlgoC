/**
 * fibonnacci.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * La suite de Fibonacci est une suite d'entiers définie comme suit :
 *
 * -   U0=1
 * -   U1=1
 * -   Un= Un-1 + Un-2
 *
 * Écrivez le code *fibonacci.c* qui affiche les n termes de la suite de
 * Fibonacci U0, U1, U2,...Un.
 * */

#include <stdio.h>

int fibo(int num) {
    int n_2;
    int n_1;
    int n;

    for (int fibn = 0; fibn <= num; fibn++) {
        if (fibn == 0) {
            n = 1;
        } else if (fibn == 1) {
            n = 1;
            n_1 = 1;
        } else {
            int tmp = n;
            n_2 = n_1;
            n_1 = tmp;
            n = n_1 + n_2;
        }

        printf("U%d = %d\n", fibn, n);
    }

    return n;
}

int main() {
    fibo(20);
    return 0;
}
