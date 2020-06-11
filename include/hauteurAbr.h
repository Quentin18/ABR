#ifndef HAUTEUR
#define HAUTEUR

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"
#include "aleaAbr.h"

int max(int a, int b);
int hauteur(Noeud* noeud);
void moyennes(int n, int valMin, int valMax, float* hauteurMoyenne, float* desequilibreMoyen);
void experimentationMoyennes(char* nomFichier, int nMax, int nInc, int valMin, int valMax);
void MAJHauteurs(Noeud* noeud);

#endif