/**
 * chaine.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Sans utiliser les bibliothèques standards ou externes (par exemple
 * string.h), écrivez le code *chaine.c* qui
 *
 * 1.  calcule le nombre de caractères dans une chaine de caractères
 * 2.  copie une chaine de caractères dans une autre chaine de caractère
 * 3.  concatène deux chaines de caractères
 * */

#include <stdio.h>

int length(char* str) {
    int len = 0;
    char *ptr = str;

    while (*ptr != '\0') {
        len++;
        ptr++;
    }

    return len;
}

void clone_str(char * from, char * to) {
    char *from_ptr = from;
    char *to_ptr = to;

    while (*from_ptr != '\0') {
        *to_ptr=*from_ptr;
        from_ptr++;
        to_ptr++;
    };

    *to_ptr = '\0';
}

void concat_str(char * from1, char * from2, char * to) {
    char *from1_ptr = from1;
    char *from2_ptr = from2;
    char *to_ptr = to;

    while (*from1_ptr != '\0') {
        *to_ptr = *from1_ptr;
        from1_ptr++;
        to_ptr++;
    }

    while (*from2_ptr != '\0') {
        *to_ptr = *from2_ptr;
        from2_ptr++;
        to_ptr++;
    };

    *to_ptr = '\0';
}

int main() {
    char example_str[] = "Hello World!";
    printf("'%s' length: %d\n", example_str, length(example_str));

    char cloned_str [length(example_str)];
    clone_str(example_str, cloned_str);
    printf("Original (%p): %s\n", (void *)example_str, example_str);
    printf("Copy (%p): %s\n", (void *)cloned_str, cloned_str);

    char concatened_str [length(example_str) + length(cloned_str)];
    concat_str(example_str, cloned_str, concatened_str);
    printf("Concatened example_str + cloned_str : %s\n", concatened_str);

    return 0;
}
