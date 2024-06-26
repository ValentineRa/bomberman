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




#include <stdlib.h>

struct bombe
{
	time_t start;
	size_t must_explose_in;
	struct bombe *next;
};

struct bombe *bombe_new(struct bombe*bombes, size_t time)
{
	struct bombe *bombe = calloc(1, sizeof(struct bombe));
	if (!bombe)
		return NULL;

	bombe->start = time(NULL);
	bombe->must_explose_in = time;

	if (bombes)
	{
		struct bombe *next = bombes;
		while(next->next)
		{
			next = next->next;
		}
		next->next = bombe;
		return bombes;
	}
	return bombe;
}

void check_bombes(struct bombe *bombes)
{
	struct bombe *prev = NULL;
	struct bombe *current = bombes;
	while (current)
	{
		if (difftime(bombe->start, time(NULL)) >= current->must_explose_in)
		{
			//On fait exploser la bombe
			//Tu fais ton impacte sur la map
			
			(*bombes).start;
			bombes->start;
			
			if (prev)
				prev->next = current->next;		
			struct bombe *tmp = current;
			current = current->next;

			free(tmp);
			continue;
		}

		prev = current;
		current = current->next;
	}
}

int demo(void)
{
	struct bombe *bombes = NULL;
	while (1)
	{
		//check deplacement du joueur 1
		//Si bombe posée
		struct bombes *tmp = bombe_new(bombes, 5);
		if (tmp)
			bombes = tmp;
		
		//check deplacement du joueur 2
		//Si bombe posée
		struct bombes *tmp = bombe_new(bombes, 4);
		if (tmp)
			bombes = tmp;

		//Verification des bombes
		check_bombes(bombes);
	}
}


