/**
 * fichier.h
 * Johan Planchon <johan.planchon@cpe.fr>
 *
 * Écrivez un programme en créant deux fichiers *fichier.c* et fichier.h.
 * Dans fichier.h, déclarez les fonctions lire_fichier(char
 * *nom_de_fichier) et ecrire_dans_fichier(char *nom_de_fichier,
 * char *message). La fonction lire_fichier prend le nom du fichier et
 * affiche son contenu à l'écran. ecrire_dans_fichier prend le nom du
 * fichier et écrire le message saisi par l'utilisateur dans le fichier.
 * */

#ifndef FICHIER_H
#define FICHIER_H

void lire_fichier(char *);
void ecrire_dans_fichier(char *, char *);

#endif
