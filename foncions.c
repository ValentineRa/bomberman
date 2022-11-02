#include "bomberman.h"


void deplacementDesDeuxJoueurs(char plateau[LIGNES][COLONNES]){
    //initialisation joueur1
    int randomLigne;
	int randomColonne;

	do{
		randomLigne = rand()%LIGNES;
		randomColonne = rand()%COLONNES;
	} while (!placeLibre(plateau, randomLigne, randomColonne));

	plateau[randomLigne][randomColonne]='B';


    //initialisation joueur2
    int randomLigne2;
	int randomColonne2;

    do{
		randomLigne2 = rand()%LIGNES;
		randomColonne2 = rand()%COLONNES;
	} while (!placeLibre(plateau, randomLigne2, randomColonne2) || (randomLigne == randomLigne2 && randomColonne == randomColonne2));

	plateau[randomLigne2][randomColonne2]='b';

    afficher_plateau(plateau);


	//déplacement des deux joueurs simultanement :
    int dir, dir1;
    int bombeUtilise = 0;
    int bombeUtilise2 = 0;
    int a, c = 0; //pour les scores
    int b, bombeExplose = 0;
    int d, bombeExplose2 = 0;
        do{
            dir = getch();
            if (dir == 224) {
                dir1 = getch();
            }

            //poser une bombe pour le joueur 1
            if (dir == BOMBE){
                int Ligne = randomLigne;
                int Colonne = randomColonne;

                deplacementDesDeuxJoueurs(plateau[randomLigne][randomColonne]);
                plateau[Ligne][Colonne] = 'o';

                int n;
                printf("Combien de cases donc combien de secondes avant explosion ? ");
                scanf("%d", &n);
                b = bombe(plateau, randomLigne, randomColonne, n);
                bombeExplose = bombeExplose + b;

                bombeUtilise = bombeUtilise + 1;

                a = score(n, bombeUtilise, bombeExplose);
                //printf("Le nouveau score est de : %d pour %c", a, joueur1.pseudo);
                printf("\n");

            }
            // poser une bombe pour le joueur 2
            else if (dir == BOMBE2){
                int Ligne2 = randomLigne2;
                int Colonne2 = randomColonne2;

                deplacementDesDeuxJoueurs(plateau[randomLigne][randomColonne]);
                plateau[Ligne2][Colonne2] = 'o';

                int n;
                printf("Combien de cases donc combien de secondes avant explosion ? ");
                scanf("%d", &n);
                d = bombe(plateau, randomLigne2, randomColonne2, n);
                bombeExplose2 = bombeExplose2 + d;

                bombeUtilise2 = bombeUtilise2 + 1;

                c = score(n, bombeUtilise2, bombeExplose2);
                //printf("Le nouveau score est de : %d pour %c", c, joueur2.pseudo);
                printf("\n");
            }


            //deplacementJoueur1
            plateau[randomLigne][randomColonne] = ' ';
            if (dir1 == 72){ //HAUT
                if (placeLibre(plateau, randomLigne - 1, randomColonne)){
                    randomLigne = randomLigne - 1;
                }
            }
            else if (dir1 == 80){ //BAS
                if (placeLibre(plateau, randomLigne + 1, randomColonne)){
                    randomLigne = randomLigne + 1;
                }
            }
            else if (dir1 == 77){ //DROITE
                if (placeLibre(plateau, randomLigne, randomColonne + 1)){
                    if (randomLigne == 4 && randomColonne + 1 == 23){
                        randomColonne = 1;
                        printf("ligne : %d et colonne : %d ",randomLigne,randomColonne);
                        printf("\n");
                    }
                    else{
                        randomColonne = randomColonne + 1;
                    }
                }
            }
            else if (dir1 == 75){ //GAUCHE
                if (placeLibre(plateau, randomLigne, randomColonne - 1)){
                    if (randomLigne == 4 && randomColonne - 1 == 0){
                        randomColonne = 22;
                    }
                    else{
                        randomColonne = randomColonne - 1;
                    }
                }
            }
            plateau[randomLigne][randomColonne] = 'B';

            //Fin déplacementJoueur1
            //deplacementJoueur2

            plateau[randomLigne2][randomColonne2] = ' ';
            if (dir == HAUT2){
                if (placeLibre(plateau, randomLigne2 - 1, randomColonne2)){
                    randomLigne2 = randomLigne2 - 1;
                }
            }
            else if (dir == BAS2){
                if (placeLibre(plateau, randomLigne2 + 1, randomColonne2)){
                    randomLigne2 = randomLigne2 + 1;
                }
            }
            else if (dir == DROITE2){
                if (placeLibre(plateau, randomLigne2, randomColonne2 + 1)){
                    if (randomLigne2 == 4 && randomColonne2 + 1 == 23){
                        randomColonne2 = 1;
                    }
                    else {
                    randomColonne2 = randomColonne2 + 1;
                    }
                }
            }
            else if (dir == GAUCHE2){
                if (placeLibre(plateau, randomLigne2, randomColonne2 - 1)){
                    if (randomLigne2 == 4 && randomColonne2 - 1 == 0){
                        randomColonne2 = 22;
                    }
                    else {
                        randomColonne2 = randomColonne2 - 1;
                    }
                }
            }
            plateau[randomLigne2][randomColonne2] = 'b';

            //Fin déplacementJoueur2

            afficher_plateau(plateau);
        }
        while(dir1==72 || dir1==80 || dir1==77 || dir1==75 || dir==HAUT2 || dir==BAS2 || dir==DROITE2 || dir==GAUCHE2);
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
        return plateau[ligne][colonne] == ' ';
}


void terrain(char plateau[LIGNES][COLONNES], int nombre){
    int obstableLigne, obstacleColonne;
    printf("\n");
    for (int i = 0; i < nombre; i++){
        do{
            obstableLigne = rand()%LIGNES;
            obstacleColonne = rand()%COLONNES;
        } while (!placeLibre(plateau, obstableLigne, obstacleColonne));
        plateau[obstableLigne][obstacleColonne] = 'x';
    }
}


int bombe(char plateau[LIGNES][COLONNES], int ligne, int colonne, int nombre){
    int secondes;
    int n = 0; //nombre de bombes qui vont exploser ce tour

    time_t begin = time( NULL );
    do {
        time_t now = time( NULL );
        secondes = now - begin;
    }while (n != secondes);

    int nbcasesL = 0;
    int nbcasesC = 0;
    while (plateau[ligne][colonne] != '#' || 2 * n != nbcasesL){ //explosion sur la ligne
        if (plateau[ligne][colonne] == 'x'){
            n = n + 1;
        }
        plateau[ligne][colonne] = ' ';
        ligne = ligne + 1;
        nbcasesL = nbcasesL + 1;
        }

    while (plateau[ligne][colonne] != '#' || 2 * n != nbcasesC){ //explosion sur la colonne
        if (plateau[ligne][colonne] == 'x'){
            n = n + 1;
        }
        plateau[ligne][colonne] = ' ';
        colonne = colonne + 1;
        nbcasesC = nbcasesC + 1;
        }
    return n;
}

int score (int nombre, int nbBombeUtilise, int nbObExplose){
    return nbObExplose / (nbBombeUtilise * nombre);
}
