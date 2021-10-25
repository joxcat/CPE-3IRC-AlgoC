/*
 * sizeof_types.c
 * Johan Planchon <johan.planchon@cpe.fr
 *
 * Ecrivez un programme *sizeof_types.c* qui affiche la taille des
 * différents types de base (en octets) :
 *
 * i.  char
 * ii. short
 * iii. int
 * iv. long int
 * v.  long long int
 * vi. float
 * vii. double
 * viii. long double
 *
 * Ne pas oubliez d'utiliser les versions signées et non-signées. Testez le
 * programme (compilez et exécuter).
 * */

#include <stdio.h>

int main() {
    printf("=== Sizes of ===\n");
    printf("char: %lu\n", sizeof(char));
    printf("float: %lu\n", sizeof(float));
    printf("double: %lu\n", sizeof(double));
    printf("long double: %lu\n", sizeof(long double));

    printf("\n--- Signed ---\n");
    printf("short: %lu\n", sizeof(signed short));
    printf("int: %lu\n", sizeof(signed int));
    printf("long int: %lu\n", sizeof(signed long int));
    printf("long long int: %lu\n", sizeof(signed long long int));

    printf("\n--- Unsigned ---\n");
    printf("short: %lu\n", sizeof(unsigned short));
    printf("int: %lu\n", sizeof(unsigned int));
    printf("long int: %lu\n", sizeof(unsigned long int));
    printf("long long int: %lu\n", sizeof(unsigned long long int));

    return 0;
}
