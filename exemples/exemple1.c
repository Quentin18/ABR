/**
 * \file exemple1.c
 * \brief Exemple 1
 * \author Quentin Deschamps
 * \date 2020
 *
 * Exemple 1 - Création, insertion, suppression et exportation avec un ABR
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "libabr.h"


int main(int argc, char const *argv[]) {
    // Création d'un arbre
    Noeud* noeud = creerNoeud(2, NULL, NULL, NULL, 0);
    Abr* arbre = creerAbr("arbre1", 0, noeud);

    // Insertions
    inserer(arbre->racine, 1);
    inserer(arbre->racine, 3);
    inserer(arbre->racine, 4);
    inserer(arbre->racine, 0);
    // Mise à jour des hauteurs
    MAJHauteurs(arbre->racine);
    exportationDot(arbre->racine, "arbre1.dot", 0);

    // Suppression
    supprimer(arbre->racine, 3);
    MAJHauteurs(arbre->racine);
    exportationDot(arbre->racine, "arbre1Supprime.dot", 0);

    libererAbr(arbre);
    return 0;
}
