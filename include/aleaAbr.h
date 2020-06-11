#ifndef ALEA
#define ALEA

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"
#include "importAbr.h"
#include "hauteurAbr.h"

int* entiersAlea(int nbSommets, int valMin, int valMax);
void afficheEntiersAlea(int* entiers, int nbSommets);
Abr* creerArbreAlea(char* nom, int id, int nbSommets, int valMin, int valMax);

#endif