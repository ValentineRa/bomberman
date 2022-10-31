#include "bomberman.h"

void afficher_plateau(int tableau[LIGNES][COLONNES]){
    //ligne du haut du contour du labyrinthe
    for (int j = 0; j < COLONNES; j++){
        printf(" #");
    }
    printf("\n");

    //deuxième ligne du labyrinthe
    printf(" #");
    for (int j = 0; j < COLONNES-2; j++){
        tableau[1][j] = "  ";
        printf(tableau[LIGNES][j]);
    }
    printf(" #");
    printf("\n");

    //troisième ligne
    tableau[2] = {" #","  "," #"," #","  "," #","  ","  "," #","  "," #"," #"," #","  "," #"," #","  "," #","  ","  ","  "," #","  "," #"};
    printf(tableau[2]);
    printf("\n");

    //quatrième ligne
    tableau[3] = {" #","  "," #","  ","  "," #"," #","  "," #","  "," #","  ","  ","  "," #","  ","  "," #"," #","  "," #"," #","  "," #"};
    printf(tableau[3]);
    printf("\n");

    //cinquième ligne
    tableau[4] = {"  ","  "," #"," #","  "," #","  "," #"," #","  "," #"," #"," #","  "," #"," #","  "," #","  "," #","  "," #","  ","  "};
    printf(tableau[4]);
    printf("\n");

    //sixième ligne
    tableau[5] = {" #","  "," #","  ","  "," #","  ","  "," #","  ","  ","  "," #","  "," #","  ","  "," #","  ","  ","  "," #","  "," #"};
    printf(tableau[5]);
    printf("\n");

    //septième ligne
    tableau[6] = {" #","  "," #"," #","  "," #","  ","  "," #","  "," #"," #"," #","  "," #"," #","  "," #","  ","  ","  "," #","  "," #"};
    printf(tableau[6]);
    printf("\n");

    //huitième ligne du labyrinthe
    printf(" #");
    for (int j = 0; j < COLONNES-2; j++){
        tableau[7][j] = "  ";
        printf(tableau[LIGNES][j]);
    }
    printf(" #");
    printf("\n");

    //ligne du bas du contour du labyrinthe
    for (int j = 0; j < COLONNES; j++){
        printf(" #");
    }
    printf("\n");
}
