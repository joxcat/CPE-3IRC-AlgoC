/**
 * combinator.h
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Inspired by https://github.com/Geal/nom
 * */

#ifndef COMBINATOR_H
#define COMBINATOR_H

#define PTR unsigned long int
// [char * next, char * match]
// next => text after the match
// match => text which matched
#define COMBINATOR_PTR PTR *
#define COMBINATOR_PTR_SIZE sizeof(COMBINATOR_PTR) * 2
#define MAX_MATCH_DEPTH 1000
#define COMBINATOR_FN COMBINATOR_PTR(*)(char *)
// (char) => int
#define CHAR_FN PTR

COMBINATOR_PTR tag(char *, char *);
COMBINATOR_PTR is_n(char *, int, CHAR_FN);
COMBINATOR_PTR while_is_0(char *, CHAR_FN);

// [int selected_combinator_index, COMBINATOR_PTR result]
// one_of(input, combinators_to_try)
#define ONE_OF_PTR PTR *
ONE_OF_PTR one_of(char *, PTR *);

// [PTR, ...]
// tuple(input, combinators_to_apply_in_sequence)
#define TUPLE_PTR COMBINATOR_PTR *
TUPLE_PTR tuple(char *, PTR *);

int is_number(char);
int is_whitespace(char);
COMBINATOR_PTR whitespaces(char *);
int is_alpha(char);
int is_alnum(char);
int is_alpha(char);
int is_alpha(char);
int is_alpha(char);

#endif
