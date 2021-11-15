/**
 * couleurs.c
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Une couleur en format RGBA contient 4 valeurs : rouge (R), vert (G),
 * bleu (B) et alpha (A). Chaque valeur est un octet. Créez un programme
 * *couleurs.c* en utilisant struct. Ensuite, créer et initialiser un
 * tableau de 10 couleurs. Pensez à initialiser les coleurs en notation
 * hexadécimale (r : 0xef, g : 0x78 etc.).
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RGB {
    unsigned int red;
    unsigned int blue;
    unsigned int green;
    unsigned int alpha;
};

struct RGB new_rgb(char * r, char * g, char * b, char * a) {
    struct RGB result;
    char * red = r + sizeof(char) * 2;
    char * blue = b + sizeof(char) * 2;
    char * green = g + sizeof(char) * 2;
    char * alpha = a + sizeof(char) * 2;

    result.red = strtol(red, NULL, 16);
    result.blue = strtol(blue, NULL, 16);
    result.green = strtol(green, NULL, 16);
    result.alpha = strtol(alpha, NULL, 16);

    return result;
};

void print_rgb(struct RGB rgb) {
    printf("R:%d G:%d B:%d A:%d\n", rgb.red, rgb.green, rgb.blue, rgb.alpha);
}

int main() {
    struct RGB colors [5] = {
         new_rgb("0xFF", "0x55", "0x04", "0x01"),
         new_rgb("0x32", "0x00", "0x00", "0x02"),
         new_rgb("0x02", "0x13", "0x12", "0x99"),
         new_rgb("0xAA", "0x42", "0x01", "0x01"),
         new_rgb("0xCC", "0x86", "0x69", "0x01"),
    };

    for (int idx = 0; idx < 5; idx++) {
        struct RGB rgb = colors[idx];
        print_rgb(rgb);
    }

    return 0;
}
