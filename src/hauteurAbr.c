/**
 * \file hauteurAbr.c
 * \brief Hauteurs des ABR
 * \author Quentin Deschamps
 * \date 2020
 *
 * Hauteurs dans les arbres binaires
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"
#include "aleaAbr.h"

#define NBABR 10


int max(int a, int b) {
    return (a < b) ? b : a;
}

int hauteur(Noeud* noeud) {
    /* Retourne la hauteur d'un noeud */
    if (noeud != NULL) {
        return max(hauteur(noeud->filsG), hauteur(noeud->filsD)) + 1;
    }
    return -1;
}

void MAJHauteurs(Noeud* noeud) {
    /* Met à jour les hauteurs des noeuds d'un arbre */
    if (noeud != NULL) {
        noeud->hauteur = hauteur(noeud);
        MAJHauteurs(noeud->filsD);
        MAJHauteurs(noeud->filsG);
    }
}

void moyennes(int n, int valMin, int valMax, float* hauteurMoyenne, float* desequilibreMoyen) {
    /* Retourne la hauteur moyenne et le facteur de déséquilibre moyen d'un arbre de taille n */
    Abr* arbreAlea;
    for (int i = 0 ; i < NBABR ; i++) {
        arbreAlea = creerArbreAlea("", 0, n, valMin, valMax);
        *hauteurMoyenne += arbreAlea->racine->hauteur;
        *desequilibreMoyen += abs(hauteur(arbreAlea->racine->filsG) - hauteur(arbreAlea->racine->filsD));
        libererAbr(arbreAlea);
    }
    *hauteurMoyenne /= NBABR;
    *desequilibreMoyen /= NBABR;
}

void experimentationMoyennes(char* nomFichier, int nMax, int nInc, int valMin, int valMax) {
    /* Etudie la hauteur moyenne et le facteur de déséquilibre moyen d'un abr */
    FILE* fichier = NULL;
    fichier = fopen(nomFichier, "w");
    float hauteurMoyenne, desequilibreMoyen;
    if (fichier != NULL) {
        printf("Création du fichier %s en cours...\n", nomFichier);
        for (int n = 1 ; n < nMax ; n += nInc) {
            hauteurMoyenne = 0.0;
            desequilibreMoyen = 0.0;
            moyennes(n, valMin, valMax, &hauteurMoyenne, &desequilibreMoyen);
            fprintf(fichier, "%d;%f;%f\n", n, hauteurMoyenne, desequilibreMoyen);
        }
        fclose(fichier);
        printf("Création du fichier %s réussie !\n", nomFichier);
    }
    else {
        printf("Impossible de créer le fichier %s !\n", nomFichier);
    }
}
