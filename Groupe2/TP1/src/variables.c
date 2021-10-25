/*
 * variables.c
 * Johan Planchon <johan.planchon@cpe.fr
 *
 * Ecrivez un programme *variables.c* qui affecte et affiches les valeurs des
 * des variables des différents types de base :
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
    printf("=== Values of ===\n");
    char c = 'c';
    printf("char: %c\n", c);
    float f = 1.1;
    printf("float: %f\n", f);
    double d = 1.111;
    printf("double: %f\n", d);
    long double ld = 1.1111111111111;
    printf("long double: %Lf\n", ld);

    printf("\n--- Signed ---\n");
    signed short ss = -5;
    printf("short: %hd\n", ss);
    signed int si = -111;
    printf("int: %d\n", si);
    signed long int sli = -9000;
    printf("long int: %ld\n", sli);
    signed long long int slli = -9999999999;
    printf("long long int: %lld\n", slli);

    printf("\n--- Unsigned ---\n");
    unsigned short us = 5;
    printf("short: %d\n", us);
    unsigned int ui = 111;
    printf("int: %d\n", ui);
    unsigned long int uli = 11111;
    printf("long int: %lu\n", uli);
    unsigned long long int ulli = 11111111111;
    printf("long long int: %llu\n", ulli);

    return 0;
}
