#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#include "bomberman.h"

static char plateau[LIGNES][COLONNES] = {
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ','#','#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#',' ','#',' ',' ',' ','#',' ','#'},
	{'#',' ','#',' ',' ','#','#',' ','#',' ','#',' ',' ',' ','#',' ',' ','#','#',' ','#','#',' ','#'},
	{' ',' ','#','#',' ','#',' ','#','#',' ','#','#','#',' ','#','#',' ','#',' ','#',' ','#',' ',' '},
	{'#',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ','#'},
	{'#',' ','#','#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#',' ','#',' ',' ',' ','#',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};

int main(void)
{
    srand(time(NULL));
    joueur joueur1 , joueur2; //initialisation des deux joueurs

    //printf("nom du joueur1 : ");
    //fgets(joueur1.pseudo, 20, stdin);   //demande le nom du joueur1

    //printf("\n nom du joueur2 : ");
    //fgets(joueur2.pseudo, 20, stdin);   //demande le nom du joueur2

    //test des coordonnées pour le premier placement :

    int randomLigne;
	int randomColonne;

	do{
		randomLigne = rand()%LIGNES;
		randomColonne = rand()%COLONNES;
	}//while (plateau[randomLigne][randomColonne] != ' ');
	while (!placeLibre(plateau, randomLigne, randomColonne));

	plateau[randomLigne][randomColonne]='B';

    afficher_plateau(plateau);

    deplacementJoueur(plateau, randomLigne, randomColonne);

    return 0;
}
