/**
 * puissance.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Écrivez le code *puissance.c* qui prend deux entiers **a** et **b** et
 * qui affiche la valeur du nombre **a** élevé à une puissance **b**. Par
 * exemple, puissance(2,3) affiche la valeur 8. N'utilisez pas la fonction
 * *pow()* (math.h).
 * */

#include <stdio.h>

unsigned long int diy_pow(int base, int power) {
    int powered_num = 1;

    for (int step = 0; step < power; step++) {
        powered_num *= base;
    }

    printf("%d^%d = %d", base, power, powered_num);

    return powered_num;
}

int main() {
    diy_pow(2, 3);
    return 0;
}
