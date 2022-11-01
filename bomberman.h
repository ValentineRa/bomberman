#ifndef BOMBERMAN_H_INCLUDED
#define BOMBERMAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define LIGNES 10
#define COLONNES 24

#define TRUE 256
#define FALSE 0

#define HAUT 273
#define BAS 274
#define DROITE 275
#define GAUCHE 276

typedef struct {
  char pseudo[20];
  char bombe;
}joueur;

// Prototypes de fonctions :
void afficher_plateau(char plateau[LIGNES][COLONNES]);
void deplacementJoueur(char plateau[LIGNES][COLONNES],int ligne, int colonne);
int placeLibre(char plateau[LIGNES][COLONNES], int ligne, int colonne);

#endif // BOMBERMAN_H_INCLUDED
