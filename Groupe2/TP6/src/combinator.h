/**
 * combinator.h
 * Johan Planchon <johan.planchon@cpe.fr>
 * version: v0.2.2
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
CombinatorResult* preceded_by(CombinatorFn, char *);
CombinatorResult* terminated_by(CombinatorFn, const char *, char *);

typedef int (*IsFn)(char);
CombinatorResult* take_is(int, IsFn, char *);
CombinatorResult* while_is(IsFn, char *);

typedef struct {
    int combinator_index;
    CombinatorResult* combinator_result;
} AltResult;
AltResult* alt(CombinatorFn *, char *);

typedef CombinatorResult* TupleResult;
TupleResult* tuple(CombinatorFn *, char *);

CombinatorResult* delimited(CombinatorFn, CombinatorFn, char*);

int is_digit(char);
CombinatorResult* while_digit(char *);
int is_space(char);
CombinatorResult* while_space(char *);
int is_alphabetic(char);
CombinatorResult* while_alphabetic(char *);
int is_alphanumeric(char);
CombinatorResult* while_alphanumeric(char *);

/* JSON Parsing */
#define JSON_TYPE_OBJECT = 0;
#define JSON_TYPE_ARRAY = 1;
#define JSON_TYPE_NUMBER = 2;
#define JSON_TYPE_STRING = 3;

typedef union _Value {
    char * s;
    union _Value * arr;
    long double nb;
} Value;

typedef struct {
    Value* values;
    short type;
} Array;

typedef struct {
    char* key;
    Value value;
} ObjectPart;
typedef ObjectPart* Object;

enum JsonBase { JsonObject = 0, JsonArray = 1 };

CombinatorResult* json_string(char *);
CombinatorResult* json_array(char *);
CombinatorResult* json_object(char *);

CombinatorResult* tag_double_quote(char *);
CombinatorResult* preceded_by_double_quote(char *);
CombinatorResult* terminated_by_double_quote(char *);

CombinatorResult* tag_square_bracket_open(char *);
CombinatorResult* preceded_by_square_bracket_open(char *);
CombinatorResult* terminated_by_square_bracket_open(char *);

CombinatorResult* tag_square_bracket_close(char *);
CombinatorResult* preceded_by_square_bracket_close(char *);
CombinatorResult* terminated_by_square_bracket_close(char *);

CombinatorResult* tag_curly_bracket_open(char *);
CombinatorResult* preceded_by_curly_bracket_open(char *);
CombinatorResult* terminated_by_curly_bracket_open(char *);

CombinatorResult* tag_curly_bracket_close(char *);
CombinatorResult* preceded_by_curly_bracket_close(char *);
CombinatorResult* terminated_by_curly_bracket_close(char *);

#endif
