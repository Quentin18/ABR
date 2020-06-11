/**
 * \file rotationAbr.c
 * \brief Rotations des ABR
 * \author Quentin Deschamps
 * \date 2020
 *
 * Rotations des arbres binaires
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"


int facteurEquilibre(Noeud* noeud) {
    /* Retourne le facteur d'équilibre du noeud */
    if (noeud != NULL) {
        int hauteurFG = (noeud->filsG != NULL) ? noeud->filsG->hauteur : -1;
        int hauteurFD = (noeud->filsD != NULL) ? noeud->filsD->hauteur : -1;
        return hauteurFG - hauteurFD;
    }
    return 0;
}

Noeud* rotationGauche(Noeud* x) {
    /* Effectue une rotation gauche, où
    - x correspond à la racine de l'arbre
    - z correspond au fils gauche de x */
    if (x != NULL && x->filsG != NULL) {
        Noeud* z = x->filsG;
        Noeud* t = z->filsD;
        x->filsG = t;
        if (t != NULL) {
            t->pere = x;
        }
        z->filsD = x;
        x->pere = z;
        return z;
    }
    printf("Rotation gauche impossible !\n");
    return x;
}

Noeud* rotationDroite(Noeud* x) {
    /* Effectue une rotation droite, où
    - x correspond à la racine de l'arbre
    - z correspond au fils droit de x */
    if (x != NULL && x->filsD != NULL) {
        Noeud* z = x->filsD;
        Noeud* t = z->filsG;
        x->filsD = t;
        if (t != NULL) {
            t->pere = x;
        }
        z->filsG = x;
        x->pere = z;
        return z;
    }
    printf("Rotation droite impossible !\n");
    return x;
}

Noeud* rotationGaucheDroite(Noeud* x) {
    /* Effectue une rotation gauche droite, où
    - x correspond à la racine de l'arbre
    - z correspond au fils droit de x */
    if (x != NULL && x->filsD != NULL && x->filsD->filsG != NULL) {
        Noeud* z = x->filsD;
        Noeud* y = z->filsG;
        Noeud* t3 = y->filsD;
        z->filsG = t3;
        if (t3 != NULL) {
            t3->pere = z;
        }
        y->filsD = z;
        z->pere = y;
        Noeud* t2 = y->filsG;
        x->filsD = t2;
        if (t2 != NULL) {
            t2->pere = x;
        }
        y->filsG = x;
        x->pere = y;
        return y;
    }
    printf("Rotation gauche droite impossible !\n");
    return x;
}

Noeud* rotationDroiteGauche(Noeud* x) {
    /* Effectue une rotation droite gauche, où
    - x correspond à la racine de l'arbre
    - z correspond au fils gauche de x */
    if (x != NULL && x->filsG != NULL && x->filsG->filsD != NULL) {
        Noeud* z = x->filsG;
        Noeud* y = z->filsD;
        Noeud* t3 = y->filsG;
        z->filsD = t3;
        if (t3 != NULL) {
            t3->pere = z;
        }
        y->filsG = z;
        z->pere = y;
        Noeud* t2 = y->filsD;
        x->filsG = t2;
        if (t2 != NULL) {
            t2->pere = x;
        }
        y->filsD = x;
        x->pere = y;
        return y;
    }
    printf("Rotation droite gauche impossible !\n");
    return x;
}

// https://en.wikipedia.org/wiki/AVL_tree (droite et gauche inversés)
