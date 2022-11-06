#include <stdio.h>
#define LIGNES 24
#define COLONNES 10

static char plateau[LIGNES][COLONNES] = {
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ','#','#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#',' ','#',' ',' ',' ','#',' ','#'},
	{'#',' ','#',' ',' ','#','#',' ','#',' ','#',' ',' ',' ','#',' ',' ','#','#',' ','#','#',' ','#'},
	{' ',' ','#','#',' ','#',' ','#','#',' ','#','#','#',' ','#','#',' ','#',' ','#',' ','#',' ',' '},
	{'#',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ','#'},
	{'#','x','#','#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#',' ','#',' ',' ',' ','#',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};

int main (void){
    //bombe(plateau, 8, 2, 3);
    //afficher_plateau(plateau);
    highscore(4, 3);
    return 0;
}

void highscore(int compteur, int max)
{
        FILE *fichier=NULL;
        int score[3]={0};
        fichier= fopen("highscore.txt", "r+");
        if (fichier != NULL)
        {
            fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);
            if (compteur <= score[0])
            {
                printf("Meilleur score de %d tours!!\n", compteur);
                fseek(fichier, 0, SEEK_SET);
                fputc(compteur, fichier);
                fclose(fichier);
            }
            else if (compteur <= score[1] && compteur > score[0])
            {
                printf("Second meilleur score de %d tours!!\n", compteur);
                fseek(fichier, 1, SEEK_SET);
                fputc(compteur, fichier);
                fclose(fichier);
            }
            else if (compteur <= score[2] && compteur > score[1] && compteur > score[2])
            {
                printf("Troisieme meilleur score de %d tours!!\n", compteur);
                fseek(fichier, 2, SEEK_SET);
                fputc(compteur, fichier);
                fclose(fichier);
            }
            else
            {
                printf("Pas de meilleurs scores\n\n");
                fclose(fichier);
            }
        }
        else
        {
            printf("Erreur de chargement des meilleures scores.\n\n");
        }
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

int bombe(char plateau[LIGNES][COLONNES], int ligne, int colonne, int nombre){
    int secondes;
    int n = 0; //nombre de bombes qui vont exploser ce tour

    time_t begin = time( NULL );
    do {
        time_t now = time( NULL );
        secondes = now - begin;
    }while (nombre != secondes);

    printf("fin du temps");
    printf("\n");

    int nbcasesL = 0;
    int nbcasesC = 0;
    while (plateau[ligne][colonne] != '#' || nombre != nbcasesL){ //explosion sur la ligne
        if (plateau[ligne][colonne] == 'x'){
            n = n + 1;
        }
        printf("coucou1");
        plateau[ligne][colonne] = ' ';
        ligne = ligne + 1;
        nbcasesL = nbcasesL + 1;
        }
    printf("coucou2");
    while (plateau[ligne][colonne] != '#' || 2 * nombre != nbcasesC){ //explosion sur la colonne
        if (plateau[ligne][colonne] == 'x'){
            n = n + 1;
        }
        plateau[ligne][colonne] = ' ';
        colonne = colonne + 1;
        nbcasesC = nbcasesC + 1;
        }
    printf("le nombre de bombe est : %d", n);
    return n;
}

