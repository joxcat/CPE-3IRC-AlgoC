/**
 * calcule.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * En réutilisant le code de l'*operator.c* (voir ci-dessus), créer une
 * commande calcule (fichier: *calcule.c*) qui utilise l'interface en
 * ligne de commande. Il y a trois options pour cette commande: opérateur
 * (+, -, *, /, %, &, |, ~), numéro un et numéro deux. Par exemple, si
 * l'utilisateur écrit
 * */

#include <stdio.h>
#include <stdlib.h>

int somme(int num1, int num2) {
    return num1 + num2;
}

int difference(int num1, int num2) {
    return num1 - num2;
}

int produit(int num1, int num2) {
    return num1 * num2;
}

float quotient(int num1, int num2) {
    return (float)num1 / num2;
}

int modulo(int num1, int num2) {
    return num1 % num2;
}

int et(int num1, int num2) {
    return num1 & num2;
}

int ou(int num1, int num2) {
    return num1 | num2;
}

int neg(int num) {
    return ~num;
}

int main(int argc, char ** argv) {
    if (argc < 4) {
        printf("Usage: calcule <operateur> <num1> <num2>");
        return 1;
    }

    char op = argv[1][0];
    int num1 = strtol(argv[2], NULL, 10);
    int num2 = strtol(argv[3], NULL, 10);

    switch (op) {
        case '+':
            printf("%d + %d = %d", num1, num2, somme(num1, num2));
            break;
        case '-':
            printf("%d - %d = %d", num1, num2, difference(num1, num2));
            break;
        case '*':
            printf("%d * %d = %d", num1, num2, produit(num1, num2));
            break;
        case '/':
            printf("%d / %d = %.3f", num1, num2, quotient(num1, num2));
            break;
        case '%':
            printf("%d %% %d = %d", num1, num2, modulo(num1, num2));
            break;
        case '&':
            printf("%d & %d = %d", num1, num2, et(num1, num2));
            break;
        case '|':
            printf("%d | %d = %d", num1, num2, ou(num1, num2));
            break;
        case '~':
            printf("~%d = %d, ~%d = %d", num1, neg(num1), num2, neg(num2));
            break;
    }

    return 0;
}
