/**
 * \file exemple4.c
 * \brief Exemple 4
 * \author Quentin Deschamps
 * \date 2020
 *
 * Exemple 4 - Rotations des ABR
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libabr.h"


int main(int argc, char const *argv[]) {
    srand(time(NULL)); // initialisation de rand

    // Création d'un arbre aléatoire
    int nbSommets = 30;
    int valMin = 0;
    int valMax = 100;
    Abr* arbreAlea = creerArbreAlea("arbreAlea", 0, nbSommets, valMin, valMax);
    exportationDot(arbreAlea->racine, "arbre4.dot", 0);

    // Rotations
    // Rotation droite
    arbreAlea->racine = rotationDroite(arbreAlea->racine);
    MAJHauteurs(arbreAlea->racine);
    exportationDot(arbreAlea->racine, "arbre4RD.dot", 0);

    // Rotation gauche
    // Les fichiers arbre4.dot et arbre4RG.dot doivent être identiques (si rotation droite possible).
    arbreAlea->racine = rotationGauche(arbreAlea->racine);
    MAJHauteurs(arbreAlea->racine);
    exportationDot(arbreAlea->racine, "arbre4RG.dot", 0);

    // Rotation gauche droite
    arbreAlea->racine = rotationGaucheDroite(arbreAlea->racine);
    MAJHauteurs(arbreAlea->racine);
    exportationDot(arbreAlea->racine, "arbre4RGD.dot", 0);

    // Rotation droite gauche
    arbreAlea->racine = rotationDroiteGauche(arbreAlea->racine);
    MAJHauteurs(arbreAlea->racine);
    exportationDot(arbreAlea->racine, "arbre4RDG.dot", 0);

    libererAbr(arbreAlea);
    return 0;
}
