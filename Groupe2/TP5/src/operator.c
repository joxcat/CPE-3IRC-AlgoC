/**
 * operator.c
 * Johan Planchon <johan.planchon@cpe.fr>
 * */

#include "operator.h"
#include <stdio.h>

double somme(double num1, double num2) {
    return num1 + num2;
}

double difference(double num1, double num2) {
    return num1 - num2;
}

double produit(double num1, double num2) {
    return num1 * num2;
}

double quotient(double num1, double num2) {
    return num1 / num2;
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
        || op == '~'
        || op == '=';
}
