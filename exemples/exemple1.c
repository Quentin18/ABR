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
    Abr* arbre = creerAbr("arbre1", 0, NULL);

    // Insertions
    insererAbr(arbre, 2);
    insererAbr(arbre, 1);
    insererAbr(arbre, 3);
    insererAbr(arbre, 4);
    insererAbr(arbre, 0);
    exportationDot(arbre->racine, "arbre1.dot", 0);

    // Suppression
    supprimerAbr(arbre, 3);
    exportationDot(arbre->racine, "arbre1Supprime.dot", 0);

    libererAbr(arbre);
    return 0;
}
