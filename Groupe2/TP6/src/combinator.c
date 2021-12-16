/**
 * combinator.c
 * Johan Planchon <johan.planchon@cpe.fr>
 * version: v0.2.2
 *
 * Inspired by https://github.com/Geal/nom
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "combinator.h"

#define tag_(__name, __match) CombinatorResult* tag_##__name (char* input) { return tag( __match, input ); }
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

#define preceded_by_tag_(__name) CombinatorResult* preceded_by_##__name (char * input) { return preceded_by( tag_##__name, input); }
CombinatorResult* preceded_by(CombinatorFn match_fn, char * input) {
    CombinatorResult* result = match_fn(input);

    if (strlen(result->match) == 0) {
        free(result);
        return NULL;
    } else {
        return result;
    }
}

#define terminated_by_tag_(__name, __escape_seq) CombinatorResult* terminated_by_##__name (char * input) { return terminated_by( tag_##__name, __escape_seq, input); }
CombinatorResult* terminated_by(CombinatorFn match_fn, const char * escape_sequence, char * input) {
    CombinatorResult* result = malloc(sizeof(CombinatorResult));

    int next_is_escaped = 0;
    CombinatorResult* matching_result = match_fn(input);
    do {
        strcat(result->match, matching_result->match);

        if (!next_is_escaped && strlen(matching_result->match) > 0) {
            result->next = matching_result->next;
            return result;
        } else if (next_is_escaped) {
            next_is_escaped = 0;
        }

        if (escape_sequence != NULL && strstr(result->next, escape_sequence) == result->next) {
            next_is_escaped = 1;
        }
    } while ((matching_result = match_fn(result->next)) != NULL);

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

CombinatorResult* delimited(CombinatorFn preceded, CombinatorFn terminated, char* input) {
    CombinatorResult* preceded_result = preceded(input);

    if (strlen(preceded_result->match) == 0) {
        return NULL;
    } else {
        CombinatorResult* terminated_result = terminated(preceded_result->next);
        free(preceded_result);
        return terminated_result;
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

/* Basic JSON Parser */
// Methods used to parse JSON
tag_(double_quote, "\"");
preceded_by_tag_(double_quote);
terminated_by_tag_(double_quote, "\\");

tag_(square_bracket_open, "[");
preceded_by_tag_(square_bracket_open);
terminated_by_tag_(square_bracket_open, NULL);

tag_(square_bracket_close, "]");
preceded_by_tag_(square_bracket_close);
terminated_by_tag_(square_bracket_close, NULL);

tag_(curly_bracket_open, "{");
preceded_by_tag_(curly_bracket_open);
terminated_by_tag_(curly_bracket_open, NULL);

tag_(curly_bracket_close, "}");
preceded_by_tag_(curly_bracket_close);
terminated_by_tag_(curly_bracket_close, NULL);

// Parsing methods
CombinatorResult* json_string(char * input) {
    return delimited(preceded_by_double_quote, terminated_by_double_quote, input);
}

CombinatorResult* json_array(char * input) {
    return delimited(preceded_by_square_bracket_open, terminated_by_square_bracket_close, input);
}

CombinatorResult* json_object(char * input) {
    return delimited(preceded_by_curly_bracket_open, terminated_by_curly_bracket_close, input);
}

CombinatorResult* json(char * input) {
    CombinatorFn combinators[] = { json_object, json_array, NULL };
    AltResult* combinator = alt(combinators, input);

    if (combinator == NULL) {
        return NULL;
    } else if (combinator->combinator_index == 0) {
        // @TODO Is an OBJECT
        return combinator->combinator_result;
    } else if (combinator->combinator_index == 1) {
        // @TODO Is an ARRAY
        return combinator->combinator_result;
    } else {
        return NULL;
    }
}
