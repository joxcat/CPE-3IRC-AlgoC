/**
 * combinator.h
 * Johan Planchon <johan.planchon@cpe.fr>
 * version: v0.2.0
 *
 * Inspired by https://github.com/Geal/nom
 * */

#ifndef COMBINATOR_H
#define COMBINATOR_H

#define MAX_MATCH_DEPTH 1000

typedef struct {
    char * next;
    char match[MAX_MATCH_DEPTH];
} CombinatorResult;

typedef CombinatorResult* (*CombinatorFn)(char *);

CombinatorResult* tag(const char *, char *);

typedef int (*IsFn)(char);
CombinatorResult* take_is(int, IsFn, char *);
CombinatorResult* while_is(IsFn, char *);

typedef struct {
    int combinator_index;
    CombinatorResult* combinator_result;
} AltResult;
typedef AltResult (*AltFn)(char *);
AltResult* alt(CombinatorFn *, char *);

typedef CombinatorResult* TupleResult;
typedef TupleResult (*TupleFn)(char *);
TupleResult* tuple(CombinatorFn *, char *);

int is_digit(char);
CombinatorResult* while_digit(char *);
int is_space(char);
CombinatorResult* while_space(char *);
int is_alphabetic(char);
CombinatorResult* while_alphabetic(char *);
int is_alphanumeric(char);
CombinatorResult* while_alphanumeric(char *);

#endif
