/*
 * chercherfichier.c
 * Johan Planchon <johan.planchon@cpe.fr
 *
 * En réutilisant le code de *chercher.c* (TP3) et *fichier.c*, écrivez un
 * fichier *chercherfichier.c* qui cherche une phrase dans un fichier, les
 * deux sont à saisir par l'utilisateur. *chercherfichier.c* doit afficher
 * toutes les lignes de fichier où les mots sont présents et également le
 * nombre de fois qu'ils sont présents. Par exemple,
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 25565
#define READ_BUFFER_SIZE 512
#define MAX_LINE_NUMBER 10000

struct Match {
    int line;
    int count;
};

// Create an empty match
struct Match * new_match(int line) {
    struct Match * match = malloc(sizeof(struct Match));

    match->line = line;
    match->count = 0;

    return match;
}

char * lire_fichier(char * nom_de_fichier) {
    FILE * fptr = fopen(nom_de_fichier, "r");
    char * buffer = malloc(sizeof(char) * MAX_BUFFER_SIZE);
    int buffer_offset = 0;

    if (fptr == NULL) {
        printf("Une erreur est survenue lors de la lecture du fichier (%s)", nom_de_fichier);
        exit(1);
    }

    // Read line per READ_BUFFER_SIZE bytes chunks
    char * line_buffer = malloc(READ_BUFFER_SIZE);
    while (fgets(line_buffer, READ_BUFFER_SIZE, fptr) != NULL) {
        strcpy(buffer + buffer_offset, line_buffer);
        buffer_offset += strlen(line_buffer);
    }

    fclose(fptr);

    return buffer;
}

int main(int argc, char ** argv) {
    if (argc < 3) {
        printf("Usage: chercherfichier <texte a chercher> <fichier>");
        return 1;
    }

    char * search_query = argv[1];
    char * filename = argv[2];
    char * file_content = lire_fichier(filename);

    int line_number = 1;
    int search_query_idx = 0;
    int matches_idx = 0;
    struct Match ** matches = malloc(sizeof(struct Match) * MAX_LINE_NUMBER);
    struct Match * match = new_match(0);

    for (int file_content_idx = 0; file_content[file_content_idx] != '\0'; file_content_idx++) {
        char file_part = file_content[file_content_idx];

        // On newline
        if (file_part == '\n') {
            // If match in the line add it to the matches
            if (match->count > 0) {
                matches[matches_idx] = match;
                matches_idx++;
                // Prepare for a next match
                match = new_match(line_number);
            }

            line_number++;
        } else {
            // On full match
            if (search_query[search_query_idx] == '\0') {
                // If currently the match havent match anything set the line number
                // because it's an empty match created by a previous line
                if (match->count == 0) {
                    match->line = line_number;
                }

                match->count++;
            }

            if (file_part == search_query[search_query_idx]) {
                search_query_idx++;
            } else {
                search_query_idx = 0;
            }
        }
    }

    int matches_length = matches_idx;
    for (int matches_idx = 0; matches_idx < matches_length; matches_idx++) {
        struct Match * match = matches[matches_idx];
        printf("Ligne %d, %d fois\n", match->line, match->count);
    }

    return 0;
}
