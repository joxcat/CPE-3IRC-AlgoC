/*
 * repertoire.c
 * Johan Planchon <johan.planchon@cpe.fr
 *
 * Écrivez un programme en créant deux fichiers *repertoire.h* et
 * *repertoire.c* qui utilisent l'interface en ligne de commande et prennent
 * le nom du répertoire.
 *
 * Ajoutez la déclaration suivante en repertoire.h
 * ```
 * void lire_dossier(char *);
 * ```
 *
 * Implémentez cette fonction en *repertoire.c* qui parcourt le répertoire
 * saisi par l'utilisateur et affiche les noms des fichiers (et
 * répertoires, si aucun) dans ce répertoire. Vous pouvez utiliser `opendir`,
 * `readdir` pour parcourir un répertoire.
 *
 * Ajoutez la déclaration suivante en *repertoire.h*
 *
 * ```
 * void lire_dossier_recursif(char *);
 * ```
 *
 * Implémentez la fonction en *repertoire.c* qui parcourt le répertoire saisi
 * par l'utilisateur en récursif et affiche tous les noms des
 * fichiers, des répertoires, des sous-répertoires et des fichiers dans les
 * sous-répertoires. Pour mieux comprendre cette question, testez
 *
 * ```
 * $ ls -R
 * ```
 *
 * sur la ligne de commande. Testez votre code. Utilisez le principe de la
 * fonction récursive.
 * */

#include <linux/limits.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

#include "repertoire.h"

#define ERROR_CANNOT_OPEN_DIRECTORY 1
#define ERROR_PATH_IS_TOO_LONG 2

void lire_dossier(char * path) {
    DIR *directory;
    directory = opendir(path);

    if (directory == NULL) {
        printf("Cannot access the directory specified\n");
        exit(ERROR_CANNOT_OPEN_DIRECTORY);
    } else {
        struct dirent * entry;
        while ((entry = readdir(directory))) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(directory);
}

void lire_dossier_recursif(char * initial_path) {
    DIR *directory;
    directory = opendir(initial_path);

    printf("%s:\n", initial_path);

    if (directory == NULL) {
        printf("Cannot access the directory specified\n");
    } else {
        struct dirent * entry;
        while ((entry = readdir(directory))) {
            if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".") != 0) {
                printf("%s  ", entry->d_name);

                if (entry->d_type & DT_DIR) {
                    char new_path[PATH_MAX];
                    int new_path_length = snprintf(new_path, PATH_MAX, "%s/%s", initial_path, entry->d_name);

                    if (new_path_length >= PATH_MAX) {
                        printf("Path length is too long");
                        exit(ERROR_PATH_IS_TOO_LONG);
                    } else {
                        lire_dossier_recursif(new_path);
                    }
                }
            }
        }
    }

    printf("\n");
    closedir(directory);
}

struct Directory {
    char parent_path[PATH_MAX];
    char path[PATH_MAX];
    DIR * dir;
};

struct Directory new_directory(char * parent_path, char * path, DIR * dir) {
    struct Directory new_directory;

    strcpy(new_directory.path, path);
    strcpy(new_directory.parent_path, parent_path);
    new_directory.dir = dir;

    return new_directory;
}

#define MAX_SUBDIRECTORIES 100
void lire_dossier_iteratif(char * initial_path) {
    struct Directory directories[MAX_SUBDIRECTORIES];
    int first_directory = 0;
    int last_directory = 0;

    struct dirent * entry;

    directories[last_directory] = new_directory(initial_path, initial_path, opendir(initial_path));

    do {
        printf("%s:\n", directories[first_directory].path);

        if (directories[first_directory].dir == NULL) {
            printf("Cannot access the directory specified\n");
        } else {
            while ((entry = readdir(directories[first_directory].dir))) {
                if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".") != 0) {
                    printf("%s  ", entry->d_name);

                    if (entry->d_type & DT_DIR) {
                        char new_path[PATH_MAX] = "";

                        strcat(new_path, directories[first_directory].path);
                        strcat(new_path, "/");
                        strcat(new_path, entry->d_name);

                        if (strlen(new_path) >= PATH_MAX) {
                            printf("Path length is too long");
                            exit(ERROR_PATH_IS_TOO_LONG);
                        } else {
                            directories[last_directory + 1] = new_directory(directories[first_directory].path, new_path, opendir(new_path));
                            last_directory++;
                        }
                    }
                }
            }

            printf("\n\n");
            closedir(directories[first_directory].dir);
        }

        first_directory++;
    } while (first_directory <= last_directory);
}

int main() {
    char path[FILENAME_MAX];
    printf("Which folder do you want to list? ");
    scanf("%s", path);

    printf("Exercise 5.1\n");
    lire_dossier(path);

    printf("Exercise 5.2\n");
    lire_dossier_recursif(path);

    printf("Exercise 5.3\n");
    lire_dossier_iteratif(path);
}
