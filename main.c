#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>


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
    int cbObstacle;
    printf("Combien d'obstacles souhaitez-vous ? ");
    scanf("%d", &cbObstacle);

    terrain(plateau, cbObstacle);


    srand(time(NULL));
    joueur joueur1 , joueur2; //initialisation des deux joueurs

    printf("nom du joueur1 : ");
    fgets(joueur1.pseudo, 20, stdin); //demande le nom du joueur1
    fgets(joueur1.pseudo, 20, stdin);

    printf("\n");
    printf("nom du joueur2 : ");
    fgets(joueur2.pseudo, 20, stdin);   //demande le nom du joueur2

    deplacementDesDeuxJoueurs(plateau);

    return 0;
}
