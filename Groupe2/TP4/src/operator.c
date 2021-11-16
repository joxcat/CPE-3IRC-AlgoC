/**
 * operator.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * En réutilisant le code de l'*operators2.c* (TP2), écrivez un programme
 * en créant deux fichiers *operator.h* et *operator.c*. Dans *operator.h*,
 * déclarez les fonctions suivantes : somme, différence, produit, quotient,
 * modulo, 'et', ou et négation qui utilisent deux variables num1
 * (entier), num2 (entier). Implémentez ces fonctions dans *operator.c*.
 * Pour l'opérateur négation, utilisez seulement un numéro. Considérez une
 * variable op qui contient un de ces différents opérateurs. (+, -, *, /,
 * %, &, |, ~). Utilisez switch et réutilisez le code de votre TP2, mais
 * cette fois, si op est égal à '+', le programme doit appeler la fonction
 * 'somme' etc. Testez votre programme avec différentes valeurs de num1,
 * num2, op.
 * */

#include <stdio.h>

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

int main() {
    int num1;
    printf("num1: ");
    scanf("%d", &num1);

    int num2;
    printf("num2: ");
    scanf("%d", &num2);

    char op[1];
    printf("Quel opérateur (+-*/%%&|~) ? ");
    scanf("%s", op);

    switch (op[0]) {
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
