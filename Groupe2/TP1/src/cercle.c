/*
 * cercle.c
 * Johan Planchon <johan.planchon@cpe.fr
 *
 * Ecrivez un programme *cercle.c* qui calcule l'aire et le périmètre d'un cercle
 * a.  l'aire: Utilisez une variable **rayon** : float ou double
 * b.  le périmètre: Utilisez une variable **rayon** : float ou double
 * c.  Compilez *cercle.c* et créez un fichier éxecutable nommé cercle
 * d.  Exécutez 'cercle'
 * */

#include <stdio.h>

float PI = 3.14;

int main() {
    double rayon = 2;

    printf("Perimeter size: %.3f\n", rayon * 2.0 * PI);
    printf("Area size: %.3f\n", PI * rayon * rayon);

    return 0;
}
