#include "tp10.h"

void viderBuffer(void){
  //déclaration des variables
  int c ;
  do {
    c= getchar();
  }
  while (c != '\n' && c!= EOF);
}

char saisieChar(char* str_message){
  //déclaration des variables
  char lettre ;
  //affiche un message
  printf("%s \n\t", str_message) ;
  //lecture de la saisie
  lettre = (char)getchar() ;
  viderBuffer() ;
  //fin de l'algorithme
  return(lettre) ;
}

char* motAleatoire (char* nomFichier){
  //déclaration des variables
  FILE* fic ;
  char* str ;
  int n ;

  //initialisation des variables
  fic = NULL ;
  //allocation de l'espace nécessaire
  str = malloc(tailleMax * sizeof(char)) ;
  //ouverture du fichier
  fic = fopen(nomFichier, "r");

  //vérification de la bonne ouverture du fichier
  if (fic == NULL){
     //s'il y a un problème, on affice un message d'Erreur
     fprintf(stderr, "problème d'ouverture du fichier\n");
     //on s'arrête
     exit(0) ;
  }

  //on récupère le nombre de mots du fichier
  fgets(str, tailleMax, fic) ;
  //transformation de la chaine de caractères en entier
  n = atof(str) ;

  //affiche un message
  printf("\t Le fichier contient %d lignes \n", n) ;

  srand (time (NULL)) ;
  //on prend un nombre aléatoire
  n = (int)rand() % n + 1 ;
  //affiche un message
  printf("\t ligne : %d\n", n);

  //récupération du mot voulu grace à un compteur
  do{
    //on récupère le mot de la ligne n
    fgets(str, tailleMax, fic) ;
    //affiche un message
    n = n - 1;
  } while(n != 0);
  //fermeture du fichier
  fclose(fic) ;
  return(str) ;
}


int joueLettre (char* motATrouver, char* motMystere, char lettre){
  //déclaration des varaibles
  int count ;
  int longueur ;

  //affectation des valeurs aux variables
  count = 0 ;
  longueur = strlen(motATrouver) ;

  //on parcourt le motATrouver
  for (int i = 0 ; i < longueur; i++) {
    //si la lettre du motATrouver correspond à lettre
    if (motATrouver[i] == lettre){
      //incrémentation du compteur
      count = count + 1 ;
      //modification du motMystere
      motMystere[i] = lettre ;
    }
  }
  //fin de l'algorithme
  return (count) ;

}


int jouePendu (char* motATrouver){
  //déclaration des variables
  int longueur ;
  char  lettre ;
  char* motMystere ;
  int essais ;

  //affectation des valeurs
  essais = 10 ;
  longueur = strlen(motATrouver) ;

  //affiche un message
  printf("\n\tLa taille du mot mystère est : %ld\n", strlen(motATrouver)-1) ;

  //allocation de l'espace nécessaire
  motMystere = malloc(longueur * sizeof(char)) ;
  //copie de motATrouver
  strcpy(motMystere, motATrouver) ;

  //remplacement de tous les caractères
  for (int i = 0; i < longueur-1; i++) {
    motMystere[i] = '_' ;
  }

  //on joue tant que l'on peut
  while ((essais != 0) && (strcmp(motMystere, motATrouver) != 0)){
    //affiche un message
    printf("\tVous avez %d essais\n", essais) ;
    //affiche un message
    printf("\tLe mot mystère est : %s\n", motMystere) ;
    //appel de la fonction saisieChar
    lettre = saisieChar("\tQuelle est la lettre que vous souhaitez jouer ? \n") ;
    //si la lettre n'est pas dans le mot
    if (joueLettre(motATrouver, motMystere, lettre) == 0) {
      //décrémentation de essais
      essais = essais - 1 ;
    }
  }
  //on vérifie si les deux mots sont égaux
  if (strcmp(motMystere, motATrouver) == 0){
    //affiche des messages
    printf("Le mot mystère est : %s\n", motMystere) ;
    printf("\t\t C'est gagné ! \n") ;
  }
  //vérification de la possibilité de jouer
  else {
    //affiche un message
    printf("\t\t\t Perdu !\n \t Le mot secret était : %s\n", motATrouver) ;
  }

  //fin de l'algorithme
  return (essais) ;
}

void sauvegarderScore(char* nomFichier, char* nom, int score){
  //déclaration des variables
  FILE* fic;
  FILE* newFic;
  char* str ;
  char* str2 ;
  char * nomFic;
  int i;

  //alocation de l'espace nécessaire
  str = malloc(tailleMax * sizeof(char));
  str2 = malloc(tailleMax * sizeof(char));
  nomFic = malloc(tailleMax * sizeof(char));
  //initialisation des variables
  fic = NULL ;
  newFic = NULL ;
  //ouverture du fichier
  fic = fopen(nomFichier, "a+") ;
  //vérification du succès de l'ouverture
  if (fic == NULL){
     //s'il y a un problème, on affice un message d'Erreur
     fprintf(stderr, "problème d'ouverture du fichier\n");
     exit(0) ;
  }

  while(fgets(str, tailleMax, fic) != NULL){
    printf("%s\n", str);
    i = 0;
    // Copier le nom contenu dans la ligne
    do{
      nomFic[i] = str[i + 6] ;
      i++ ;
    } while(nomFic[i] != ',') ;
    nomFic[i] = '\0' ;

    //Compare si il est dans le fichier
    if (strcmp(nomFic, nom) == 0) {
      newFic = fopen("./src/newListe.txt", "a+");
      fseek(fic, 0, SEEK_SET) ;
      while(fgets(str2, tailleMax, fic) != NULL){
        printf("%s\n", str2);
        if (strcmp(str, str2) != 0) {
          fprintf(newFic, "%s", str2) ;
        }
        fclose(newFic);
      }
    }
  }
  //ouverture du fichier
  newFic = fopen("./src/newListe.txt", "a+");
  //vérification de l'ouverture du fichier
  if (newFic == NULL){
     //s'il y a un problème, on affice un message d'Erreur
     fprintf(stderr, "problème d'ouverture du fichier\n");
     exit(0) ;
  }
  //écrit dans le fichier
  fprintf(fic, "nom : %s, score : %d\n", nom, score);
  fprintf(newFic, "nom : %s, score : %d\n", nom, score);

  //fermeture du fichier
  fclose(newFic);
  fclose(fic) ;

  printf("aaa\n");
  //on remplace le fichier liste.txt
  remove("./src/liste.txt");
  rename("./src/newListe.txt", "./src/liste.txt");

}
