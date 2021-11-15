/**
 * couleur_compteur.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * En réutilisant le code de *couleurs.c*, écrivez un programme
 * *couleur_compteur.c* avec un tableau de 100 couleurs. Par exemple, si
 * le tableau contient les couleurs suivantes:
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 1000

struct RGB {
    unsigned int red;
    unsigned int blue;
    unsigned int green;
    unsigned int alpha;
};

struct RGBCount {
    struct RGB rgb;
    int count;
};

struct RGB new_rgb(unsigned int r, unsigned int g, unsigned int b, unsigned int a) {
    struct RGB result;
    result.red = r;
    result.blue = b;
    result.green = g;
    result.alpha = a;

    return result;
};

void print_rgb(struct RGB rgb) {
    printf("R:%d G:%d B:%d A:%d", rgb.red, rgb.green, rgb.blue, rgb.alpha);
}

unsigned int rand_color() {
    return rand() % (255 + 1);
}

int main() {
    srand(time(NULL));
    struct RGB colors[ARRAY_SIZE];

    // Generate colors
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        colors[idx] = new_rgb(rand_color(), rand_color(), rand_color(), rand_color());
    }

    struct RGBCount results[ARRAY_SIZE];
    int results_inner_len = 0;

    for (int idx_colors = 0; idx_colors < ARRAY_SIZE; idx_colors++) {
        struct RGB color = colors[idx_colors];
        int results_idx = 0;

        while (results_idx <= results_inner_len) {
            struct RGBCount result = results[results_idx];

            // If the color is not found in results add it at the end
            if (results_idx + 1 > results_inner_len) {
                struct RGBCount rgb_count;
                rgb_count.rgb = color;
                rgb_count.count = 1;

                results[results_inner_len] = rgb_count;
                results_inner_len++;
                break;

            // If same color found increment the counter
            } else if (
                result.rgb.alpha == color.alpha
                && result.rgb.red == color.red
                && result.rgb.green == color.green
                && result.rgb.blue == color.blue
            ) {
                results[results_idx].count++;
                break;

            } else {
                results_idx++;
            }
        }
    }

    for (int idx = 0; idx < results_inner_len; idx++) {
        if (results[idx].count >= 2) {
            print_rgb(results[idx].rgb);
            printf(" %d.\n", results[idx].count);
        }
    }

    return 0;
}
