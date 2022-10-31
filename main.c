#include <stdio.h>
#include <stdlib.h>

#include "bomberman.h"

int main()
{
    joueur joueur1 , joueur2; //initialisation des deux joueurs

    printf("nom du joueur1 : ");
    fgets(joueur1.pseudo, 20, stdin);   //demande le nom du joueur1

    printf("\n nom du joueur2 : ");
    fgets(joueur2.pseudo, 20, stdin);   //demande le nom du joueur2

    int plateau[LIGNES][COLONNES];

    int randomLigne;
    int randomColonne;

    //placer le joueur à un endroit aléatoire
    srand(time(NULL));
    randomLigne = rand()%LIGNES;
    randomColonne = rand()%COLONNES;

    //test des coordonnées : pas sur un mur :
    while (plateau[randomLigne][randomColonne] == "#"){
        srand(time(NULL));
        randomLigne = rand()%LIGNES;
        randomColonne = rand()%COLONNES;
    }

    plateau[randomLigne][randomColonne]="B";

    afficher_plateau(plateau);

    return 0;
}
