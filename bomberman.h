#ifndef BOMBERMAN_H_INCLUDED
#define BOMBERMAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <pthread.h>

#define LIGNES 10
#define COLONNES 24

#define TRUE 256
#define FALSE 0

#define BOMBE 32

#define HAUT2 122
#define BAS2 115
#define DROITE2 100
#define GAUCHE2 113
#define BOMBE2 119

typedef struct {
  char pseudo[20];

}joueur;

// Prototypes de fonctions :
void afficher_plateau(char plateau[LIGNES][COLONNES]);
void deplacementDesDeuxJoueurs(char plateau[LIGNES][COLONNES]);
void terrain(char plateau[LIGNES][COLONNES], int nombre);
int placeLibre(char plateau[LIGNES][COLONNES], int ligne, int colonne);
int bombe(char plateau[LIGNES][COLONNES], int ligne, int colonne, int nombre);
int score (int nombre, nbBombeUtilise, nbObExplose);

#endif // BOMBERMAN_H_INCLUDED
