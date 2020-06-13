#ifndef RECHERCHE
#define RECHERCHE

#include "structAbr.h"

int maximumArbre(Noeud* noeud);
Noeud* noeudMaxArbre(Noeud* noeud);
int minimumArbre(Noeud* noeud);
Noeud* noeudMinArbre(Noeud* noeud);
int appartient(Noeud* noeud, int val);
Noeud* cherche(Noeud* noeud, int val);
int successeurImmediat(Noeud* noeud);
Noeud* noeudSuccesseurImmediat(Noeud* noeud);
int estFeuille(Noeud* noeud);
void afficheAncetres(Noeud* noeud, int val);

#endif
