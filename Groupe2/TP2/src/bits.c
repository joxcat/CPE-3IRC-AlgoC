/**
 * bits.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Considérez un entier d (**int d ;**). Écrivez le code *bits.c* qui
 * vérifie si les 4eme et 20eme bits de **gauche** sont 1 (en binaire). Si
 * les deux bits sont 1, il affiche 1 sinon 0.
 * 1000 1000 0000 0000 0001 = 1
 * */

#include <stdio.h>

const int INT_SIZE = sizeof(int) * 8;

int check_bits(int d) {
    int bin[INT_SIZE];

    for (int idx = INT_SIZE - 1; idx >= 0; idx--) {
        // Less significant bit of to_convert
        bin[idx] = d & 1;
        d >>= 1;
    }

    int one_count = 0;
    int bit_count = 0;
    for (int idx = 0; idx < INT_SIZE; idx++) {
        if (bin[idx] & 1) {
            one_count++;
        }
        // Hide the useless part of the mask
        if (one_count > 0) {
            bit_count++;
            if (bit_count == 4) {
                if (bin[idx] == 0) {
                    return 0;
                }
            } else if (bit_count == 20) {
                if (bin[idx] == 0) {
                    return 0;
                }
            }
        }
    }

    if (bit_count >= 20) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int d = 589825;

    printf("d = %d => %d\n", d, check_bits(d));

    d = 100000;
    printf("d = %d => %d\n", d, check_bits(d));
    return 0;
}
