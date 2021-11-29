/*
 * list.c
 * Johan Planchon <johan.planchon@cpe.fr
 *
 * En réutilisant le fichier couleurs.c (TP 2), écrivez un programme en
 * créant deux fichiers liste.c et liste.h.
 *
 * Ajoutez les déclarations suivantes en liste.h
 *
 * ```
 * struct liste_couleurs {
 *    // Remplissez ça pour gérer une liste (simplement chainée) de couleurs.
 * }
 *
 * void insertion (struct couleur *, struct liste_couleurs *);
 * void parcours (struct liste_couleurs *);
 * ```
 *
 * Implémentez ces fonctions en liste.c. insertion prends deux entrées:
 * pointer d'une couleur RGB et pointeur d'une liste de couleurs et
 * insérez la couleur dans la liste. La fonction parcours prend le pointeur
 * d'une liste de couleurs et affiche les couleurs dans la liste. Créez
 * une liste de 10 couleurs et testez votre code en ajoutant dix couleurs
 * en utilisant insertion(..) et parcourez votre liste en utilisant
 * parcours(..).
 * */

#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

struct RGB {
    unsigned int red;
    unsigned int blue;
    unsigned int green;
    unsigned int alpha;
};

struct RGB * new_rgb(char * r, char * g, char * b, char * a) {
    struct RGB * result = malloc(sizeof(struct RGB));

    char * red = r + sizeof(char) * 2;
    char * blue = b + sizeof(char) * 2;
    char * green = g + sizeof(char) * 2;
    char * alpha = a + sizeof(char) * 2;

    result->red = strtol(red, NULL, 16);
    result->blue = strtol(blue, NULL, 16);
    result->green = strtol(green, NULL, 16);
    result->alpha = strtol(alpha, NULL, 16);

    return result;
};

void print_rgb(struct RGB * rgb) {
    printf("R:%d G:%d B:%d A:%d\n", rgb->red, rgb->green, rgb->blue, rgb->alpha);
}

struct liste_couleurs {
    struct RGB * couleur;
    struct liste_couleurs * next;
};

void insertion(struct RGB * color, struct liste_couleurs * colors_array) {
    struct liste_couleurs * colors_array_ptr = colors_array;

    while (colors_array_ptr != NULL) {
        if (colors_array_ptr->couleur == NULL) {
            colors_array_ptr->couleur = color;
            break;
        } else if (colors_array_ptr->next == NULL) {
            colors_array_ptr->next = malloc(sizeof(struct liste_couleurs));
        }

        colors_array_ptr = colors_array_ptr->next;
    }
};

void parcours(struct liste_couleurs * colors_array) {
    struct liste_couleurs * colors_array_ptr = colors_array;

    while (colors_array_ptr != NULL) {
        if (colors_array_ptr->couleur != NULL) {
            print_rgb(colors_array_ptr->couleur);
        }

        colors_array_ptr = colors_array_ptr->next;
    }
};

int main() {
    struct liste_couleurs * colors = malloc(sizeof(struct liste_couleurs));

    insertion(new_rgb("0xFF", "0x55", "0x04", "0x01"), colors);
    insertion(new_rgb("0x32", "0x00", "0x00", "0x02"), colors);
    insertion(new_rgb("0x02", "0x13", "0x12", "0x99"), colors);
    insertion(new_rgb("0xAA", "0x42", "0x01", "0x01"), colors);
    insertion(new_rgb("0xCC", "0x86", "0x69", "0x01"), colors);
    insertion(new_rgb("0xFF", "0x55", "0x04", "0x01"), colors);
    insertion(new_rgb("0x32", "0x00", "0x00", "0x02"), colors);
    insertion(new_rgb("0x02", "0x13", "0x12", "0x99"), colors);
    insertion(new_rgb("0xAA", "0x42", "0x01", "0x01"), colors);
    insertion(new_rgb("0xCC", "0x86", "0x69", "0x01"), colors);

    parcours(colors);

    return 0;
}
