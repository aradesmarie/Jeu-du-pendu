#ifndef __TP10_H_
#define __TP10_H_
//inclusion des entêtes lirairies
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
/*définition des constantes symboliques*/

#define ERREUR_SAISIE -1
#define ERREUR_SYS -1
#define tailleMax 100



/*! fn void viderBuffer(void)
author Marie Arades
version 0.1
date 4 décembre 2020
brief vide le buffer
*/
void viderBuffer() ;

/*! fn int verifMot(char* mot1, char* mot2)
author Marie Arades
version 0.1
date 4 décembre 2020
brief vérifie si deux mots sont égaux ou non
\param mot1 correspond au premier mot à comparer
\param mot2 correspond au second mot à comparer
\return drap qui vaut 0 si les mots sont égaux et -1 sinon
*/
int verifMot(char* mot1, char* mot2) ;


/*! fn char saisieChar(char* str_message)
author Marie Arades
version 0.1
date 4 décembre 2020
brief permet la saisie d'un caractère
\param str_message correspond à une indication sur le caractère à saisir
*/
char saisieChar(char* str_message) ;

/*! fn char* motAleatoire (char* mots)
author Marie Arades
version 0.1
date 4 décembre 2020
brief prend un mot aléatoirement dans un fichier
\param mots.txt correspond au fichir contenant les mots
\return un mo pris aléatoirement dans le fichier
*/
char* motAleatoire (char* mots) ;

/*! fn int joueLettre (char* motATrouver, char* motMystere, char lettre)
author Marie Arades
version 0.1
date 4 janvier 2021
brief calcule le nombre de fois que la lettre est apparue dans le motMystere
\param motATrouver indique le mot à deviner par le joueur
\param motMystere indique le mot qui est affcihé à l'utilisateur
\param lettre indique la lettre que l'utilisateur veut jouer
\return le nombre de fois que la lettre est apparu dans motMystere
*/
int joueLettre (char* motATrouver, char* motMystere, char lettre) ;


/*! fn int jouePendu(char* motATrouver)
author Marie Arades
version 0.1
date 4 janvier 2021
brief permet le déroulement du jeu
\param motATrouver indique le mot à faire deviner
\return le nombre de coups restant
*/
int jouePendu (char* motATrouver) ;


/*! fn void sauvegarderScore(char* nomFichier, char* nom, int score)
author Marie Arades
version 0.1
date 4 décembre 2020
brief sauvegarde le score pour un joueur
\param nomFichier correspond au fichier où sont sauvegardés les scores
\param nom correspond au nom du joueur
\param score correspond au score du joueur
*/
void sauvegarderScore(char* nomFichier, char* nom, int score) ;


#endif
