#ifndef IMPORT
#define IMPORT

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"
#include "rechercheAbr.h"
#include "hauteurAbr.h"

Noeud* creerNoeud(int cle, Noeud* filsG, Noeud* filsD, Noeud* pere, int hauteur);
Abr* creerAbr(char* nom, int id, Noeud* racine);
void libererNoeud(Noeud* noeud);
void libererAbr(Abr* arbre);
void inserer(Noeud* noeud, int val);
Noeud* supprimer(Noeud* noeud, int val);
Abr* importationAbr(char* nomFichier);

#endif