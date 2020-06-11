/**
 * \file exemple3.c
 * \brief Exemple 3
 * \author Quentin Deschamps
 * \date 2020
 *
 * Exemple 3 - Arbre aléatoire
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

    // Création des fichiers
    exportationDot(arbreAlea->racine, "arbre3.dot", 0);
    exportationDot(arbreAlea->racine, "arbre3Prefixe.dot", 1);
    exportationDot(arbreAlea->racine, "arbre3Infixe.dot", 2);
    exportationDot(arbreAlea->racine, "arbre3Postfixe.dot", 3);

    // Affichage des parcours en console
    printf("Parcours préfixe : ");
    parcoursPrefixe(arbreAlea->racine);
    printf("\nParcours infixe : ");
    parcoursInfixe(arbreAlea->racine);
    printf("\nParcours postfixe : ");
    parcoursPostfixe(arbreAlea->racine);
    printf("\n");

    // Affichage du minimum et du maximum
    printf("Minimum : %d\n", minimumArbre(arbreAlea->racine));
    printf("Maximum : %d\n", maximumArbre(arbreAlea->racine));

    // Fonctions de recherche
    printf("Successeur immédiat racine : %d\n", successeurImmediat(arbreAlea->racine));
    printf("Hauteur de l'arbre : %d\n", hauteur(arbreAlea->racine));

    int val = 12;
    if (appartient(arbreAlea->racine, val)) {
        printf("%d appartient à l'arbre !\n", val);

        printf("Ancêtres de %d : ", val);
        afficheAncetres(arbreAlea->racine, val);
        printf("\n");

        printf("Suppression de %d...\n", val);
        supprimer(arbreAlea->racine, val);
        MAJHauteurs(arbreAlea->racine);
        exportationDot(arbreAlea->racine, "arbre3Supprime.dot", 0);
    }
    else {
        printf("%d n'appartient pas à l'arbre !\n", val);
    }

    libererAbr(arbreAlea);
    return 0;
}
