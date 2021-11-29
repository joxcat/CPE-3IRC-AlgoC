/*
 * repertoire.h
 * Johan Planchon <johan.planchon@cpe.fr
 *
 * ===== 5.1 =====
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
 * ===== 5.2 =====
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
 *
 * ===== 5.3 =====
 * Ajoutez la déclaration suivante en repertoire.h
 *
 * ```
 * void lire_dossier_iteratif(char *);
 * ```
 *
 * Implémentez cette fonction en repertoire.c qui parcourt le répertoire
 * saisi par l'utilisateur en mode itératif et affiche tous les noms de
 * des fichiers, des répertoires, des sous-répertoires et des fichiers
 * dans les sous-répertoires. Mais cette fois, utilisez for (ou while ou
 * do..while) pour implémenter cette fonction. Testez votre code.
 * */

#ifndef REPERTOIRE_H
#define REPERTOIRE_H

// Exercise 5.1
void lire_dossier(char *);
// Exercise 5.2
void lire_dossier_recursif(char *);
// Exercise 5.3
void lire_dossier_iteratif(char *);

#endif
