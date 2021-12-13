/**
 * combinator.c
 * Johan Planchon <johan.planchon@cpe.fr>
 * version: v0.2.1
 *
 * Inspired by https://github.com/Geal/nom
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "combinator.h"

CombinatorResult* tag(const char* match, char* input) {
    CombinatorResult* result = malloc(sizeof (CombinatorResult));

    int matched_count = 0;
    strcpy(result->match, "");

    int match_depth = 0;
    int is_matching = 1;

    while (match_depth <= MAX_MATCH_DEPTH && is_matching == 1) {
        if (input[match_depth] != match[match_depth]) {
            is_matching = 0;
        } else {
            result->match[matched_count] = input[match_depth];
            matched_count++;
        }

        match_depth++;
    }

    result->next = (input + matched_count);

    return result;
}

CombinatorResult* take_is(int fn_times, IsFn is, char* input) {
    CombinatorResult* result = malloc(sizeof (CombinatorResult));

    int matched_count = 0;
    strcpy(result->match, "");

    int match_depth = 0;
    int is_matching = 1;

    while (match_depth <= MAX_MATCH_DEPTH && is_matching == 1 && matched_count < fn_times) {
        if (is(input[match_depth]) == 0) {
            is_matching = 0;
        } else {
            result->match[matched_count] = input[match_depth];
            matched_count++;
        }

        match_depth++;
    }

    result->next = (input + matched_count);

    return result;

}

CombinatorResult* while_is(IsFn is, char* input) {
    CombinatorResult* result = malloc(sizeof (CombinatorResult));

    int matched_count = 0;
    strcpy(result->match, "");

    int match_depth = 0;
    int is_matching = 1;

    while (match_depth <= MAX_MATCH_DEPTH && is_matching == 1) {
        if (is(input[match_depth]) == 0) {
            is_matching = 0;
        } else {
            result->match[matched_count] = input[match_depth];
            matched_count++;
        }

        match_depth++;
    }

    result->next = (input + matched_count);

    return result;
}

AltResult* alt(CombinatorFn* combinators_to_try, char* input) {
    AltResult* result = malloc(sizeof(AltResult));
    result->combinator_result = NULL;
    result->combinator_index = 0;

    while (combinators_to_try[result->combinator_index] != NULL && result->combinator_result == NULL) {
        CombinatorFn combinator = combinators_to_try[result->combinator_index];
        CombinatorResult* combinator_result = combinator(input);

        if (strlen(combinator_result->match) > 0) {
            result->combinator_result = combinator_result;
        } else {
            free(combinator_result);
        }

        result->combinator_index++;
    }

    if (result->combinator_result == NULL) {
        result->combinator_index = -1;
    }

    return result;
}

TupleResult* tuple(CombinatorFn* combinators_to_apply, char* input) {
    int combinators_count = 0;

    while (combinators_to_apply[combinators_count] != NULL) combinators_count++;

    if (combinators_count == 0) {
        return NULL;
    } else {
        TupleResult* result = malloc(sizeof(CombinatorResult) * combinators_count);

        char * next = malloc(strlen(input) * sizeof(char));
        strcpy(next, input);

        int selected_combinator = 0;

        while (combinators_to_apply[selected_combinator] != NULL) {
            CombinatorFn combinator = combinators_to_apply[selected_combinator];
            CombinatorResult* combinator_result = combinator(next);

            if (next == NULL) {
                result[selected_combinator] = NULL;
            } else if (combinator_result == NULL) {
                next = NULL;
                result[selected_combinator] = NULL;
            } else {
                next = combinator_result->next;
                result[selected_combinator] = combinator_result;
            }

            selected_combinator++;
        }

        return result;
    }
}

int is_digit(char c) {
    return isdigit(c);
}

CombinatorResult* while_digit(char * input) {
    return while_is(is_digit, input);
}

int is_space(char c) {
    return isblank(c);
}

CombinatorResult* while_space(char * input) {
  return while_is(is_space, input);
}

int is_alphabetic(char c) {
    return isalpha(c);
}

CombinatorResult* while_alphabetic(char * input) {
    return while_is(is_alphabetic, input);
}

int is_alphanumeric(char c) {
    return isalnum(c) || c == '.';
}

CombinatorResult* while_alphanumeric(char * input) {
    return while_is(is_alphanumeric, input);
}
