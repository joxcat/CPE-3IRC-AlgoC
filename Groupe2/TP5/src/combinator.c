/**
 * combinator.c
 * Johan Planchon <johan.planchon@cpe.fr>
 * version: v0.1.0
 *
 * Inspired by https://github.com/Geal/nom
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "combinator.h"

// NOTE: Need to free `result` and `result[1]`
COMBINATOR_PTR tag(char * input, char * match) {
    char * matched_part = malloc(MAX_MATCH_DEPTH * sizeof(char));
    int matched_count = 0;
    strcpy(matched_part, "");

    int match_depth = 0;
    int is_matching = 1;

    while (match_depth <= MAX_MATCH_DEPTH && is_matching == 1) {
        if (input[match_depth] != match[match_depth]) {
            is_matching = 0;
        } else {
            matched_part[matched_count] = input[match_depth];
            matched_count++;
        }

        match_depth++;
    }

    COMBINATOR_PTR result = malloc(COMBINATOR_PTR_SIZE);

    result[0] = (PTR)(input + matched_count);
    result[1] = (PTR)matched_part;

    return result;
}

// NOTE: Need to free `result` and `result[1]`
COMBINATOR_PTR is_n(char * input, int fn_times, PTR fn) {
    char * matched_part = malloc(MAX_MATCH_DEPTH * sizeof(char));
    int matched_count = 0;
    strcpy(matched_part, "");

    int match_depth = 0;
    int is_matching = 1;

    int (*test_is)(char) = (int (*)(char))fn;

    while (match_depth <= MAX_MATCH_DEPTH && is_matching == 1 && matched_count < fn_times) {
        if (test_is(input[match_depth]) == 0) {
            is_matching = 0;
        } else {
            matched_part[matched_count] = input[match_depth];
            matched_count++;
        }

        match_depth++;
    }

    COMBINATOR_PTR result = malloc(COMBINATOR_PTR_SIZE);

    result[0] = (PTR)(input + matched_count);
    result[1] = (PTR)matched_part;

    return result;

}

// NOTE: Need to free `result` and `result[1]`
COMBINATOR_PTR while_is_0(char * input, PTR fn) {
    char * matched_part = malloc(MAX_MATCH_DEPTH * sizeof(char));
    int matched_count = 0;
    strcpy(matched_part, "");

    int match_depth = 0;
    int is_matching = 1;

    int (*is)(char) = (int (*)(char))fn;

    while (match_depth <= MAX_MATCH_DEPTH && is_matching == 1) {
        if (is(input[match_depth]) == 0) {
            is_matching = 0;
        } else {
            matched_part[matched_count] = input[match_depth];
            matched_count++;
        }

        match_depth++;
    }

    COMBINATOR_PTR result = malloc(COMBINATOR_PTR_SIZE);

    result[0] = (PTR)(input + matched_count);
    result[1] = (PTR)matched_part;

    return result;
}

// NOTE: Need to free `result`, `result[0]` and depending on the combinator `result[1]`
ONE_OF_PTR one_of(char * input, PTR * combinators_to_try) {
    ONE_OF_PTR result = malloc(sizeof(PTR) * 2);
    result[1] = (PTR)NULL;

    int * selected_combinator = malloc(sizeof(int));
    *selected_combinator = 0;

    while (combinators_to_try[*selected_combinator] != (PTR)NULL && result[1] == (PTR)NULL) {
        COMBINATOR_PTR (*combinator)(char *) = (COMBINATOR_FN)combinators_to_try[*selected_combinator];
        COMBINATOR_PTR combinator_result = combinator(input);

        if (strlen((char *)combinator_result[1]) > 0) {
            result[1] = (PTR)combinator_result;
        } else {
            free(combinator_result);
        }

        selected_combinator++;
    }

    if (result[1] == (PTR)NULL) {
        *selected_combinator = -1;
    }

    result[0] = (PTR)selected_combinator;
    return result;
}

// NOTE: Need to free every combinator in `result`
TUPLE_PTR tuple(char * input, PTR * combinators_to_apply) {
    int combinators_count = 0;

    while (combinators_to_apply[combinators_count] != (PTR)NULL) combinators_count++;

    if (combinators_count == 0) {
        return (TUPLE_PTR)NULL;
    } else {
        TUPLE_PTR result = malloc(COMBINATOR_PTR_SIZE * combinators_count);

        char * next = malloc(strlen(input) * sizeof(char));
        strcpy(next, input);

        int selected_combinator = 0;

        while (combinators_to_apply[selected_combinator] != (PTR)NULL) {
            COMBINATOR_PTR (*combinator)(char *) = (COMBINATOR_FN)combinators_to_apply[selected_combinator];
            COMBINATOR_PTR combinator_result = combinator(next);

            if (next == NULL) {
                result[selected_combinator] = NULL;
            } else if (combinator_result == NULL) {
                next = NULL;
                result[selected_combinator] = NULL;
            } else {
                next = (char *)combinator_result[0];
                result[selected_combinator] = combinator_result;
            }

            selected_combinator++;
        }

        return result;
    }
}

int is_number(char c) {
    return is_number(c);
}

int is_whitespace(char c) {
    return isblank(c);
}

COMBINATOR_PTR whitespaces(char * input) {
  return while_is_0(input, (PTR)is_whitespace);
}

int is_alpha(char c) {
    return isalpha(c);
}

int is_alnum(char c) {
    return isalnum(c);
}
