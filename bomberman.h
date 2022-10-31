#ifndef BOMBERMAN_H_INCLUDED
#define BOMBERMAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define LIGNES 10
#define COLONNES 24

#define TRUE 256
#define FALSE 0

typedef struct {
  char pseudo[20];
}joueur;

// Prototypes de fonctions :
void afficher_plateau(void);
void placementJoueur(void);

#endif // BOMBERMAN_H_INCLUDED
