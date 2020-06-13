/**
 * \file aleaAbr.c
 * \brief ABR aléatoires
 * \author Quentin Deschamps
 * \date 2020
 *
 * Création d'arbres binaires aléatoires
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"
#include "importAbr.h"
#include "hauteurAbr.h"


int* entiersAlea(int nbSommets, int valMin, int valMax) {
    /* Génère une liste d'entiers aléatoires inférieurs à max */
    int* entiers = malloc(nbSommets*sizeof(int));
    if (entiers != NULL) {
        for (int i = 0 ; i < nbSommets ; i++) {
            entiers[i] = valMin + rand() % (valMax - valMin);
        }
        return entiers;
    }
    printf("Erreur d'allocation mémoire !\n");
    return NULL;
}

void afficheEntiersAlea(int* entiers, int nbSommets) {
    /* Affiche une liste d'entiers */
    for (int i = 0 ; i < nbSommets ; i ++) {
        printf("%d\n", entiers[i]);
    }
}

Abr* creerArbreAlea(char* nom, int id, int nbSommets, int valMin, int valMax) {
    /* Crée un abr aléatoire */
    int* entiers = entiersAlea(nbSommets, valMin, valMax); // Génération entiers aléatoires
    // afficheEntiersAlea(entiers, nbSommets);
    Abr* arbre = creerAbr(nom, id, NULL); // Création arbre
    for (int i = 0 ; i < nbSommets ; i++) {
        insererAbr(arbre, entiers[i]); // Insertion des entiers aléatoires
    }
    MAJHauteurs(arbre->racine);
    free(entiers);
    return arbre;
}
