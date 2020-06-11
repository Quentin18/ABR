/**
 * \file rechercheAbr.c
 * \brief Recherche dans les ABR
 * \author Quentin Deschamps
 * \date 2020
 *
 * Recherches dans les arbres binaires
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"


int maximumArbre(Noeud* noeud) {
    Noeud* noeudTmp = noeud;
    if (noeud != NULL) {
        while(noeudTmp->filsD != NULL) {
            noeudTmp = noeudTmp->filsD;
        }
        return noeudTmp->cle;
    }
    printf("Noeud vide !\n");
    return -1;
}

Noeud* noeudMaxArbre(Noeud* noeud) {
    Noeud* noeudTmp = noeud;
    if (noeud != NULL) {
        while(noeudTmp->filsD != NULL) {
            noeudTmp = noeudTmp->filsD;
        }
        return noeudTmp;
    }
    return NULL;
}

int minimumArbre(Noeud* noeud) {
    Noeud* noeudTmp = noeud;
    if (noeudTmp != NULL) {
        while(noeudTmp->filsG != NULL) {
            noeudTmp = noeudTmp->filsG;
        }
        return noeudTmp->cle;
    }
    printf("Noeud vide !\n");
    return -1;
}

Noeud* noeudMinArbre(Noeud* noeud) {
    Noeud* noeudTmp = noeud;
    if (noeud != NULL) {
        while(noeudTmp->filsG != NULL) {
            noeudTmp = noeudTmp->filsG;
        }
        return noeudTmp;
    }
    return NULL;
}

int appartient(Noeud* noeud, int val) {
    /* Retourne 1 si val appartient à l'arbre, 0 sinon */
    if (noeud != NULL) {
        if (noeud->cle == val) {
            return 1;
        }
        if (noeud->cle > val) {
            return appartient(noeud->filsG, val);
        }
        if (noeud->cle < val) {
            return appartient(noeud->filsD, val);
        }
    }
    return 0;
}

Noeud* cherche(Noeud* noeud, int val) {
    /* Retourne le noeud correspondant à val */
    if (noeud != NULL) {
        if (noeud->cle == val) {
            return noeud;
        }
        if (noeud->cle > val) {
            return cherche(noeud->filsG, val);
        }
        if (noeud->cle < val) {
            return cherche(noeud->filsD, val);
        }
    }
    return NULL;
}

int successeurImmediat(Noeud* noeud) {
    if (noeud != NULL) {
        return minimumArbre(noeud->filsD);
    }
    printf("Noeud vide !\n");
    return -1;
}

Noeud* noeudSuccesseurImmediat(Noeud* noeud) {
    if (noeud != NULL) {
        return noeudMinArbre(noeud->filsD);
    }
    return NULL;
}

int estFeuille(Noeud* noeud) {
    return (noeud != NULL && noeud->filsG == NULL && noeud->filsD == NULL);
}

void afficheAncetres(Noeud* noeud, int val) {
    /* Affiche les ancêtres d'un élément de valeur val */
    if (noeud != NULL && noeud->cle != val) {
        printf("%d ; ", noeud->cle);
        if (noeud->cle > val) {
            afficheAncetres(noeud->filsG, val);
        }
        else {
            afficheAncetres(noeud->filsD, val);
        }
    }
}
