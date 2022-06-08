#include "tp10.h"

int main(int argc, char const *argv[]) {
  //déclaration des variables
  char* motATrouver ;
  char* nomFichier1 ;
  char* nomFichier2 ;
  char* nom ;
  int score ;
  //initialisation des variables
  nomFichier1 = "./src/mots.txt" ;
  nomFichier2 = "./src/liste.txt" ;
  //affiche un message
  printf("Quel est votre nom ?\n") ;
  scanf("%s", nom);
  viderBuffer();

  //appel des fonctions utiles
  motATrouver = motAleatoire (nomFichier1) ;
  score = jouePendu(motATrouver) ;
  sauvegarderScore(nomFichier2, nom, score) ;
  //libération de l'espace
  free(motATrouver) ;
  //fin de l'algorithme
  return 0 ;
}
