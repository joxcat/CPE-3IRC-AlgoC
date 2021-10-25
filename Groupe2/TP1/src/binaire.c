/*
 * binaire.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Ecrivez un programme *binaire.c* qui utilise **for** pour l'affichage
 * d'une variable int en format binaire. Rappelez-vous bien que printf n'a
 * pas de code de conversion comme x (l'affichage d'un numéro en notation
 * hexadécimale) ou o (l'affichage d'un numéro en notation octale) pour
 * l'affichage en notation binaire. Testez votre code avec les 5 numéros
 * suivants : 0, 4096, 65536, 65535, 1024
 * */

#include <stdio.h>

const int INT_SIZE = sizeof(int) * 8;

void to_bin(int to_convert) {
    printf("%d: ", to_convert);
    int bin[INT_SIZE];
    
    for (int idx = INT_SIZE - 1; idx > 0; idx--) {
        // Less significant bit of to_convert
        bin[idx] = to_convert & 1;
        to_convert >>= 1;
    }

    int one_count = 0;
    for (int idx = 0; idx < INT_SIZE; idx++) {
        if (bin[idx] & 1) {
            one_count++;
        }

        // Hide the useless part of the mask
        // And if converting 0 in bin => print 0
        if (one_count > 0 || idx == INT_SIZE - 1) {
            printf("%d", bin[idx]);
        }
    }
    printf("\n");
}

int main() {
    to_bin(0);
    to_bin(4096);
    to_bin(65536);
    to_bin(65535);
    to_bin(1024);

    return 0;
}
