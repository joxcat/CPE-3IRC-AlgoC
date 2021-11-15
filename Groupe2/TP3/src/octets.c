/**
 * octets.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Écrivez un programme en créant le fichier *octets.c* et utilisant `char *`
 * et les opérateurs de pointeurs pour voir les octets d'une variable
 * short, int, long int, float, double et long double.
 * */

#include <stdio.h>
#include <string.h>

void print_hex_repr(void * ptr, long int size) {
    for (int idx = 0; idx < size; idx++) {
        printf("0x%02hhx ", *(unsigned char*)(ptr + idx));
    }
    printf("\n");
}

int main() {
    short s = 8;
    printf("short %d (%luB): ", s, sizeof(short));
    print_hex_repr(&s, sizeof(short));

    int i = 99;
    printf("int %d (%luB): ", i, sizeof(int));
    print_hex_repr(&i, sizeof(int));

    long int li = 9000;
    printf("long int %ld (%luB): ", li, sizeof(long int));
    print_hex_repr(&li, sizeof(long int));

    float f = 4.2;
    printf("float %f (%luB): ", f, sizeof(float));
    print_hex_repr(&f, sizeof(float));

    double d = 3.14657;
    printf("double %f (%luB): ", d, sizeof(double));
    print_hex_repr(&d, sizeof(double));

    long double ld = 1.000001;
    printf("long double %Lf (%luB): ", ld, sizeof(long double));
    // Les derniers octets du long double change nt
    print_hex_repr(&ld, sizeof(long double));

    char * c = "Hello World!";
    printf("char * %s (%luB): ", c, strlen(c));
    print_hex_repr(c, strlen(c));

    return 0;
}
