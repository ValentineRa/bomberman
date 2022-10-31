#ifndef BOMBERMAN_H_INCLUDED
#define BOMBERMAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define LIGNES 10
#define COLONNES 24

#define TRUE 256
#define FALSE 0

#define HAUT 0x48
#define BAS 50
#define DROITE 4D
#define GAUCHE 4B

typedef struct {
  char pseudo[20];
  char bombe;
}joueur;

// Prototypes de fonctions :
void afficher_plateau(void);
void placementJoueur(void);
int placeLibre(char plateau[LIGNES][COLONNES], int ligne, int colonne);

#endif // BOMBERMAN_H_INCLUDED
