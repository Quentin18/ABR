/**
 * \file exportAbr.c
 * \brief Exportation des ABR
 * \author Quentin Deschamps
 * \date 2020
 *
 * Exportation des arbres binaires en .dot
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"
#include "hauteurAbr.h"


void ecritParcoursPrefixe(Noeud* noeud, FILE* fichier, int* step) {
    if (noeud != NULL) {
        fprintf(fichier, "\t%d [shape=record, label=\"{ %d | Step %d }\"];\n", noeud->cle, noeud->cle, *step);
        *step += 1;
        ecritParcoursPrefixe(noeud->filsG, fichier, step);
        ecritParcoursPrefixe(noeud->filsD, fichier, step);
    }
}

void ecritParcoursInfixe(Noeud* noeud, FILE* fichier, int* step) {
    if (noeud != NULL) {
        ecritParcoursInfixe(noeud->filsG, fichier, step);
        fprintf(fichier, "\t%d [shape=record, label=\"{ %d | Step %d }\"];\n", noeud->cle, noeud->cle, *step);
        *step += 1;
        ecritParcoursInfixe(noeud->filsD, fichier, step);
    }
}

void ecritParcoursPostfixe(Noeud* noeud, FILE* fichier, int* step) {
    if (noeud != NULL) {
        ecritParcoursPostfixe(noeud->filsG, fichier, step);
        ecritParcoursPostfixe(noeud->filsD, fichier, step);
        fprintf(fichier, "\t%d [shape=record, label=\"{ %d | Step %d }\"];\n", noeud->cle, noeud->cle, *step);
        *step += 1;
    }
}

void ecritHauteur(Noeud* noeud, FILE* fichier) {
    if (noeud != NULL) {
        fprintf(fichier, "\t%d [shape=record, label=\"{ %d | h = %d }\"];\n", noeud->cle, noeud->cle, noeud->hauteur);
        ecritHauteur(noeud->filsG, fichier);
        ecritHauteur(noeud->filsD, fichier);
    }
}

void ecritPere(Noeud* noeud, FILE* fichier) {
    if (noeud != NULL) {
        if (noeud->pere != NULL) {
            fprintf(fichier, "\t%d -> %d;\n", noeud->cle, noeud->pere->cle);
        }
        ecritPere(noeud->filsG, fichier);
        ecritPere(noeud->filsD, fichier);
    }
}

void ecritParcours(Noeud* noeud, FILE* fichier, int choixParcours) {
    int step = 1;
    switch (choixParcours) {
        case 1:
            fprintf(fichier, "\tlabel = \"Parcours préfixe\"\n");
            ecritParcoursPrefixe(noeud, fichier, &step);
            break;
        case 2:
            fprintf(fichier, "\tlabel = \"Parcours infixe\"\n");
            ecritParcoursInfixe(noeud, fichier, &step);
            break;
        case 3:
            fprintf(fichier, "\tlabel = \"Parcours postfixe\"\n");
            ecritParcoursPostfixe(noeud, fichier, &step);
            break;
        default:
            printf("Choix invalide !\n");
            break;
    }
}

void ecritNoeud(Noeud* noeud, FILE* fichier, int* compteur) {
    if (noeud != NULL) {
        if (noeud->filsG != NULL) {
            fprintf(fichier, "\t%d -> %d [color=blue];\n", noeud->cle, noeud->filsG->cle);
        }
        else {
            fprintf(fichier, "\tnull%d [shape=point];\n", *compteur);
            fprintf(fichier, "\t%d -> null%d [color=blue];\n", noeud->cle, *compteur);
            *compteur += 1;
        }
        if (noeud->filsD != NULL) {
            fprintf(fichier, "\t%d -> %d [color=red];\n", noeud->cle, noeud->filsD->cle);
        }
        else {
            fprintf(fichier, "\tnull%d [shape=point];\n", *compteur);
            fprintf(fichier, "\t%d -> null%d [color=red];\n", noeud->cle, *compteur);
            *compteur += 1;
        }
    }
}

void ecritArbre(Noeud* noeud, FILE* fichier, int* compteur) {
    if (noeud != NULL) {
        ecritNoeud(noeud, fichier, compteur);
        if (noeud->filsG != NULL) {
            ecritArbre(noeud->filsG, fichier, compteur);
        }
        if (noeud->filsD != NULL) {
            ecritArbre(noeud->filsD, fichier, compteur);
        }
    }
}

void exportationDot(Noeud* noeud, char* nomFichier, int choixParcours) {
    /* Exporte un arbre en .dot
    choixParcours écrit :
    - le parcours préfixe si égal à 1
    - le parcours infixe si égal à 2
    - le parcours postfixe si égal à 3
    - les hauteurs des noeuds sinon
    */
    FILE* fichier = NULL;
    fichier = fopen(nomFichier, "w");
    if (fichier != NULL) {
        fprintf(fichier, "digraph arbre {\n");
        fprintf(fichier, "\tgraph [ordering=\"out\"]\n");
        if (choixParcours == 1 || choixParcours == 2 || choixParcours == 3) {
            ecritParcours(noeud, fichier, choixParcours);
        }
        else {
            ecritHauteur(noeud, fichier);
            // ecritPere(noeud, fichier); // Vérifie si les pères sont OK
        }
        int compteur = 0;
        ecritArbre(noeud, fichier, &compteur);
        fprintf(fichier, "}");
        fclose(fichier);
        printf("Création du fichier %s réussie !\n", nomFichier);
    }
    else {
        printf("Impossible de créer le fichier %s !\n", nomFichier);
    }
}
