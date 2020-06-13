#ifndef IMPORT
#define IMPORT

#include "structAbr.h"
#include "rechercheAbr.h"
#include "hauteurAbr.h"

Noeud* creerNoeud(int cle, Noeud* filsG, Noeud* filsD, Noeud* pere, int hauteur);
Abr* creerAbr(char* nom, int id, Noeud* racine);
void libererNoeud(Noeud* noeud);
void libererAbr(Abr* arbre);
Noeud* inserer(Noeud* noeud, int val);
void insererAbr(Abr* arbre, int val);
Noeud* supprimer(Noeud* noeud, int val);
void supprimerAbr(Abr* arbre, int val);
Abr* importationAbr(char* nomFichier);

#endif
