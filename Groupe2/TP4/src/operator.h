/**
 * operator.h
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

int somme(int, int);
int difference(int, int);
int produit(int, int);
int quotient(int, int);
int modulo(int, int);
int et(int, int);
int ou(int, int);
int neg(int);
