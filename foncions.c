#include "bomberman.h"

static char plateau[LIGNES][COLONNES] = {
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{'#',' ','#','#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#',' ','#',' ',' ',' ','#',' ','#'},
	{'#',' ','#',' ',' ','#','#',' ','#',' ','#',' ',' ',' ','#',' ',' ','#','#',' ','#','#',' ','#'},
	{' ',' ','#','#',' ','#',' ','#','#',' ','#','#','#',' ','#','#',' ','#',' ','#',' ','#',' ',' '},
	{'#',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ','#'},
	{'#',' ','#','#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#',' ','#',' ',' ',' ','#',' ','#'},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
};

void placementJoueur(void){
	int randomLigne;
	int randomColonne;

	//placer le joueur1 à un endroit aléatoire
	randomLigne = rand()%LIGNES;
	randomColonne = rand()%COLONNES;

	//test des coordonnées : pas sur un mur :
	while (plateau[randomLigne][randomColonne] == '#'){
		randomLigne = rand()%LIGNES;
		randomColonne = rand()%COLONNES;
	}

	plateau[randomLigne][randomColonne]='B';
}

void afficher_plateau(void){
	//ligne du haut du contour du labyrinthe
	placementJoueur();

	for (size_t i = 0; i < LIGNES; i++)
	{
		for(size_t j = 0; j < COLONNES; j++)
		{
			printf("%c", plateau[i][j]);
			if (!COLONNES - 1)
				printf(" ");
		}
		printf("\n");
	}
}
