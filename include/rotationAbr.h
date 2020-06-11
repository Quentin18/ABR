#ifndef ROTATION
#define ROTATION

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"

int facteurEquilibre(Noeud* noeud);
Noeud* rotationGauche(Noeud* x);
Noeud* rotationDroite(Noeud* x);
Noeud* rotationGaucheDroite(Noeud* x);
Noeud* rotationDroiteGauche(Noeud* x);

#endif