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

void placementJoueur(void){
	int randomLigne;
	int randomColonne;

	//test des coordonnées pour le premier placement :
	do{
		randomLigne = rand()%LIGNES;
		randomColonne = rand()%COLONNES;
	}//while (plateau[randomLigne][randomColonne] != ' ');
	while (!placeLibre(plateau[LIGNES][COLONNES], randomLigne, randomColonne));

	plateau[randomLigne][randomColonne]='B';
    char placement = plateau[randomLigne][randomColonne];
    //printf("plateau 0,0 %c", plateau[0][0]);
	printf("plateau alea %c", placement);
    printf("plateau alea %c", plateau[randomLigne][randomColonne]);
	printf("\n");

/*

	//déplacement du joueur
	int dir;
	do{
		dir=getch();
		if (dir == 'HAUT'){
		    if (placeLibre(plateau[LIGNES][COLONNES], randomLigne - 1, randomColonne)){
                placement = plateau[randomLigne - 1][randomColonne];
                plateau[randomLigne][randomColonne]=' ';
		    }
		}
		else if (dir == 'BAS'){
		    if (placeLibre(plateau[LIGNES][COLONNES], randomLigne + 1, randomColonne)){
                placement = plateau[randomLigne + 1][randomColonne];
                plateau[randomLigne][randomColonne]=' ';
		    }
		}
		else if (dir == 'DROITE'){
		    if (placeLibre(plateau[LIGNES][COLONNES], randomLigne, randomColonne + 1)){
                placement = plateau[randomLigne][randomColonne + 1];
                plateau[randomLigne][randomColonne]=' ';
		    }
		}
		else if (dir == 'GAUCHE'){
		    if (placeLibre(plateau[LIGNES][COLONNES], randomLigne, randomColonne - 1)){
                placement = plateau[randomLigne][randomColonne - 1];
                plateau[randomLigne][randomColonne]=' ';
		    }
		}
        }while(dir=='HAUT' || dir=='BAS' || dir=='DROITE' || dir=='GAUCHE');*/
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

int placeLibre(char plateau[LIGNES][COLONNES], int ligne, int colonne){
    printf("coucou");
    printf("plateau 0,0 %c", plateau[0][0]);
    printf("ligne %d ", ligne);
    printf("colonne %d ", colonne);
    char t = plateau[ligne][colonne];
    printf("plateau : %c", t);
    if (plateau[ligne][colonne] == "#"){
        printf("false");
        return FALSE;
    }
    printf("true");
    return TRUE;
}

