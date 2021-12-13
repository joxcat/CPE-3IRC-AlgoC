/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * client.h
 * Johan Planchon <johan.planchon@cpe.fr>
 */

#ifndef __CLIENT_H__
#define __CLIENT_H__

/*
 * port d'ordinateur pour envoyer et recevoir des messages
 */
#define PORT 8089

/*
 * taille max d'un message
 */
#define MAX_MESSAGE_LENGTH 1024

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */
char * envoie_recois_message(int socketfd, char * message);

int envoie_operateur_numeros(char * calc);

struct Etu;

#define MAX_ETUS 10000
#define ETU_NOTE_EXTENSION ".txt"
#define MAX_BUFFER_SIZE 4096
#define READ_BUFFER_SIZE 512

int calculs_etus(int socketfd, char * etus_path);

#endif
