/**
 * operator.c
 * Johan Planchon <johan.planchon@cpe.fr>
 * */

#include "operator.h"
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

int match_operator(char op) {
    return op == '+'
        || op == '-'
        || op == '*'
        || op == '/'
        || op == '%'
        || op == '&'
        || op == '|'
        || op == '~';
}
