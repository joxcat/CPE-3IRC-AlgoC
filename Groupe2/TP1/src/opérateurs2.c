/**
 * opérateurs2.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Ecrivez un programme *opérateurs2.c* qui utilise trois variables
 *
 * 1.  **num1** (entier)
 * 2.  **num2** (entier)
 * 3.  **op** (un caractère)
 *
 * La variable **op** contient un de ces différents opérateurs. (+, -, \*,
 * /, %, &, |, ~). Utilisez **switch** et réutilisez le code de votre
 * premier exercice. Si c est égal à '+', le programme fait l'addition de
 * deux variables **num1** et **num2**, si **op** est égal à '&', le
 * programme fait l'opération ET etc. Rappelez-vous bien que l'on ne peut
 * pas utiliser chaine de caractères comme condition en **switch**. Testez
 * votre programme avec différents valeurs de **num1**, num2, **op**
 * */

#include <stdio.h>

int main() {
    int num1 = 5;
    int num2 = 1;
    char op = '~';

    switch (op) {
        case '+':
            printf("%d + %d = %d", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%d - %d = %d", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%d * %d = %d", num1, num2, num1 * num2);
            break;
        case '/':
            printf("%d / %d = %.3f", num1, num2, (float)num1 / num2);
            break;
        case '%':
            printf("%d %% %d = %d", num1, num2, num1 % num2);
            break;
        case '&':
            printf("%d & %d = %d", num1, num2, num1 & num2);
            break;
        case '|':
            printf("%d | %d = %d", num1, num2, num1 | num2);
            break;
        case '~':
            printf("~%d = %d, ~%d = %d", num1, ~num1, num2, ~num2);
            break;
    }


    return 0;
}
