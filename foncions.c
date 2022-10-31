#include "bomberman.h"

void placementJoueur(){
    int randomLigne;
    int randomColonne;

    //placer le joueur1 � un endroit al�atoire
    srand(time(NULL));
    randomLigne = rand()%LIGNES;
    randomColonne = rand()%COLONNES;

    //test des coordonn�es : pas sur un mur :
    while (plateau[randomLigne][randomColonne] == " #"){
        srand(time(NULL));
        randomLigne = rand()%LIGNES;
        randomColonne = rand()%COLONNES;
    }

    plateau[randomLigne][randomColonne]="B";
}

void afficher_plateau(int tableau[LIGNES][COLONNES]){
    //ligne du haut du contour du labyrinthe
    for (int j = 0; j < COLONNES; j++){
        printf(" #");
    }
    printf("\n");

    //deuxi�me ligne du labyrinthe
    printf(" #");
    for (int j = 0; j < COLONNES-2; j++){
        tableau[1][j] = "  ";
    }

    //troisi�me ligne
    tableau[2] = {" #","  "," #"," #","  "," #","  ","  "," #","  "," #"," #"," #","  "," #"," #","  "," #","  ","  ","  "," #","  "," #"};

    //quatri�me ligne
    tableau[3] = {" #","  "," #","  ","  "," #"," #","  "," #","  "," #","  ","  ","  "," #","  ","  "," #"," #","  "," #"," #","  "," #"};

    //cinqui�me ligne
    tableau[4] = {"  ","  "," #"," #","  "," #","  "," #"," #","  "," #"," #"," #","  "," #"," #","  "," #","  "," #","  "," #","  ","  "};

    //sixi�me ligne
    tableau[5] = {" #","  "," #","  ","  "," #","  ","  "," #","  ","  ","  "," #","  "," #","  ","  "," #","  ","  ","  "," #","  "," #"};

    //septi�me ligne
    tableau[6] = {" #","  "," #"," #","  "," #","  ","  "," #","  "," #"," #"," #","  "," #"," #","  "," #","  ","  ","  "," #","  "," #"};

    //huiti�me ligne du labyrinthe
    for (int j = 0; j < COLONNES-2; j++){
        tableau[7][j] = "  ";
    }

    placementJoueur();
    printf(%d, tableau[2], "\n", tableau[3], "\n", tableau[4], "\n",tableau[5], "\n", tableau[6], "\n", tableau[7], "\n");

    //ligne du bas du contour du labyrinthe
    for (int j = 0; j < COLONNES; j++){
        printf(" #");
    }
    printf("\n");
}
