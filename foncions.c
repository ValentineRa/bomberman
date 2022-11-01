#include "bomberman.h"

#include <conio.h>

void deplacementJoueur(char plateau[LIGNES][COLONNES], int ligne, int colonne){

	//déplacement du joueur
	int dir;
	do{
		dir=getch();
		plateau[ligne][colonne] = ' ';
		if (dir == HAUT){
		    if (placeLibre(plateau, ligne - 1, ligne)){
                ligne = ligne - 1;
		    }
		}
		else if (dir == BAS){
		    if (placeLibre(plateau, ligne + 1, colonne)){
                ligne = ligne + 1;
		    }
		}
		else if (dir == DROITE){
		    if (placeLibre(plateau, ligne, colonne + 1)){
                colonne = colonne + 1;
		    }
		}
		else if (dir == GAUCHE){
		    if (placeLibre(plateau, ligne, colonne - 1)){
                colonne = colonne - 1;
		    }
		}
		plateau[ligne][colonne] = 'B';
		afficher_plateau(plateau);
        }while(dir==HAUT || dir==BAS || dir==DROITE || dir==GAUCHE);
}


void afficher_plateau(char plateau[LIGNES][COLONNES]){

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

int placeLibre(char plateau[LIGNES][COLONNES], int ligne, int colonne){
    int d = 0;
    if (plateau[ligne][colonne] == ' '){
        d = 1;
        return d;
    }
    return d;
}
