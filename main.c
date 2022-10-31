#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#include "bomberman.h"

int main(void)
{
    srand(time(NULL));
    joueur joueur1 , joueur2; //initialisation des deux joueurs

    printf("nom du joueur1 : ");
    fgets(joueur1.pseudo, 20, stdin);   //demande le nom du joueur1

    printf("\n nom du joueur2 : ");
    fgets(joueur2.pseudo, 20, stdin);   //demande le nom du joueur2

    afficher_plateau();

    return 0;
}
