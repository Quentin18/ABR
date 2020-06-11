#ifndef EXPORT
#define EXPORT

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"

void ecritParcoursPrefixe(Noeud* noeud, FILE* fichier, int* step);
void ecritParcoursInfixe(Noeud* noeud, FILE* fichier, int* step);
void ecritParcoursPostfixe(Noeud* noeud, FILE* fichier, int* step);
void ecritHauteur(Noeud* noeud, FILE* fichier);
void ecritPere(Noeud* noeud, FILE* fichier);
void ecritParcours(Noeud* noeud, FILE* fichier, int choixParcours);
void ecritNoeud(Noeud* noeud, FILE* fichier, int* compteur);
void ecritArbre(Noeud* noeud, FILE* fichier, int* compteur);
void exportationDot(Noeud* noeud, char* nomFichier, int choixParcours);

#endif