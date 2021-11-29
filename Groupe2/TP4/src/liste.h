/*
 * list.h
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

#ifndef LISTE_H
#define LISTE_H

struct RGB;

struct RGB * new_rgb(char *, char *, char *, char *);

struct liste_couleurs;

void insertion(struct RGB *, struct liste_couleurs *);
void parcours(struct liste_couleurs *);

#endif
