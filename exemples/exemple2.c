/**
 * \file exemple2.c
 * \brief Exemple 2
 * \author Quentin Deschamps
 * \date 2020
 *
 * Exemple 2 - Importation d'un ABR via un fichier .txt et parcours
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "libabr.h"


int main(int argc, char const *argv[]) {
    Abr* arbre = importationAbr("arbre.txt");

    // Création de fichiers .dot
    exportationDot(arbre->racine, "arbre2.dot", 0);
    exportationDot(arbre->racine, "arbre2Prefixe.dot", 1);
    exportationDot(arbre->racine, "arbre2Infixe.dot", 2);
    exportationDot(arbre->racine, "arbre2Postfixe.dot", 3);

    // Affichage des parcours en console
    printf("Parcours préfixe : ");
    parcoursPrefixe(arbre->racine);
    printf("\nParcours infixe : ");
    parcoursInfixe(arbre->racine);
    printf("\nParcours postfixe : ");
    parcoursPostfixe(arbre->racine);
    printf("\n");

    // Affichage du minimum et maximum
    printf("Minimum : %d\n", minimumArbre(arbre->racine));
    printf("Maximum : %d\n", maximumArbre(arbre->racine));
    libererAbr(arbre);
    return 0;
}
