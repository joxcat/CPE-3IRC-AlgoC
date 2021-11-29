/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * serveur.h
 * Johan Planchon <johan.planchon@cpe.fr>
 */


#ifndef __SERVER_H__
#define __SERVER_H__

#define PORT 8089
#define MAX_CODE_LENGTH 10
#define MAX_CONTENT_LENGTH 1000
#define MAX_MESSAGE_LENGTH 1024

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd);
char * recois_numeros_calcule(char * calc);

#endif
