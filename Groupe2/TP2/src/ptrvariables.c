/*
 * ptrvariables.c
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
    printf("char(%p): %c\n", &c, c);
    float f = 1.1;
    printf("float(%p): %f\n", &f, f);
    double d = 1.111;
    printf("double(%p): %f\n", &d, d);
    long double ld = 1.1111111111111;
    printf("long double(%p): %Lf\n", &ld, ld);

    printf("\n--- Signed ---\n");
    signed short ss = -5;
    printf("short(%p): %hd\n", &ss, ss);
    signed int si = -111;
    printf("int(%p): %d\n", &si, si);
    signed long int sli = -9000;
    printf("long int(%p): %ld\n", &sli, sli);
    signed long long int slli = -9999999999;
    printf("long long int(%p): %lld\n", &slli, slli);

    printf("\n--- Unsigned ---\n");
    unsigned short us = 5;
    printf("short(%p): %d\n", &us, us);
    unsigned int ui = 111;
    printf("int(%p): %d\n", &ui, ui);
    unsigned long int uli = 11111;
    printf("long int(%p): %lu\n", &uli, uli);
    unsigned long long int ulli = 11111111111;
    printf("long long int(%p): %llu\n", &ulli, ulli);

    return 0;
}
