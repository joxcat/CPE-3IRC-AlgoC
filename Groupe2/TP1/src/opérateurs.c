/**
 * opérateurs.c
 * Johan Planchon <johan.planchon@cpe.fr
 *
 * Ecrivez un programme *opérateurs.c* qui utilise deux variables
 * suivantes:
 *
 * i.  **a** = 16
 * ii. **b** = 3
 *
 * et testez les différents opérateurs arithmétiques et logiques.
 * */

#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;

    printf("a + b = %d\n", a + b);
    printf("b - a = %d\n", b - a);
    printf("a * b = %d\n", a * b);
    printf("a / b = %f\n", (float)a / b);
    printf("a %% b = %d\n", a % b);
    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("~a=%d, ~b=%d\n", ~a, ~b);

    return 0;
}
