/**
 * sizeof.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Vous êtes sur une machine de 64 bits et vous utilisez également un
 * système d'exploitation 64 bits. Écrivez un programme *sizeof.c* et
 * testez le code suivant. Quelle est la valeur renvoyée par chacune des
 * lignes suivantes ?
 *
 * 1.  sizeof (int)
 * 2.  sizeof (int *)
 * 3.  sizeof (int **)
 * 4.  sizeof (char *)
 * 5.  sizeof (char **)
 * 6.  sizeof (char ***)
 * 7.  sizeof (float *)
 * 8.  sizeof (float **)
 * 9.  sizeof (float ***)
 * */
#include <stdio.h>

int main() {
    printf("%lu", sizeof (int));
    printf("%lu", sizeof (int *));
    printf("%lu", sizeof (int **));
    printf("%lu", sizeof (char *));
    printf("%lu", sizeof (char **));
    printf("%lu", sizeof (char ***));
    printf("%lu", sizeof (float *));
    printf("%lu", sizeof (float **));
    printf("%lu", sizeof (float ***));

    return 0;
}
