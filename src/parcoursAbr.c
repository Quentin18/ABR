/**
 * \file parcoursAbr.c
 * \brief Parcours des ABR
 * \author Quentin Deschamps
 * \date 2020
 *
 * Parcours des arbres binaires
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"


void parcoursPrefixe(Noeud* noeud) {
    if (noeud != NULL) {
        printf("%d ; ", noeud->cle);
        parcoursPrefixe(noeud->filsG);
        parcoursPrefixe(noeud->filsD);
    }
}

void parcoursInfixe(Noeud* noeud) {
    if (noeud != NULL) {
        parcoursInfixe(noeud->filsG);
        printf("%d ; ", noeud->cle);
        parcoursInfixe(noeud->filsD);
    }
}

void parcoursPostfixe(Noeud* noeud) {
    if (noeud != NULL) {
        parcoursPostfixe(noeud->filsG);
        parcoursPostfixe(noeud->filsD);
        printf("%d ; ", noeud->cle);
    }
}
