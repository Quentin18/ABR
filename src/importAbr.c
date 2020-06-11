/**
 * \file importAbr.c
 * \brief Importation des ABR
 * \author Quentin Deschamps
 * \date 2020
 *
 * Importation des arbres binaires
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "structAbr.h"
#include "rechercheAbr.h"
#include "hauteurAbr.h"


Noeud* creerNoeud(int cle, Noeud* filsG, Noeud* filsD, Noeud* pere, int hauteur) {
    /* Crée un noeud */
    Noeud* noeud = malloc(sizeof(Noeud));
    if (noeud != NULL) {
        noeud->cle = cle;
        noeud->filsG = filsG;
        noeud->filsD = filsD;
        noeud->pere = pere;
        noeud->hauteur = hauteur;
        return noeud;
    }
    printf("Erreur d'allocation mémoire !\n");
    return NULL;
}

Abr* creerAbr(char* nom, int id, Noeud* racine) {
    /* Crée un arbre */
    Abr* arbre = malloc(sizeof(Abr));
    if (arbre != NULL) {
        arbre->nom = nom;
        arbre->id = id;
        arbre->racine = racine;
        return arbre;
    }
    printf("Erreur d'allocation mémoire !\n");
    return NULL;
}

void libererNoeud(Noeud* noeud) {
    if (noeud != NULL) {
        if (noeud->filsG != NULL) {
            libererNoeud(noeud->filsG);
        }
        if (noeud->filsD != NULL) {
            libererNoeud(noeud->filsD);
        }
        free(noeud);
    }
}

void libererAbr(Abr* arbre) {
    libererNoeud(arbre->racine);
    free(arbre);
}

void inserer(Noeud* noeud, int val) {
    if (noeud == NULL) {
        printf("Noeud vide !\n");
    }
    else {
        if (val < noeud->cle) {
            if (noeud->filsG == NULL) {
                noeud->filsG = creerNoeud(val, NULL, NULL, noeud, 0);
            }
            else {
                inserer(noeud->filsG, val);
            }
        }
        if (val > noeud->cle) {
            if (noeud->filsD == NULL) {
                noeud->filsD = creerNoeud(val, NULL, NULL, noeud, 0);
            }
            else {
                inserer(noeud->filsD, val);
            }
        }
    }
}

Noeud* supprimer(Noeud* noeud, int val) {
    if (noeud == NULL) {
        return NULL;
    }
    if (val < noeud->cle) {
        noeud->filsG = supprimer(noeud->filsG, val);
    }
    else if (val > noeud->cle) {
        noeud->filsD = supprimer(noeud->filsD, val);
    }
    else {
        Noeud* noeudTemp;
        if (noeud->filsG == NULL) {
            noeudTemp = noeud->filsD;
            free(noeud);
            return noeudTemp;
        }
        else if (noeud->filsD == NULL) {
            noeudTemp = noeud->filsG;
            free(noeud);
            return noeudTemp;
        }
        Noeud* successeur = noeudSuccesseurImmediat(noeud);
        noeud->cle = successeur->cle;
        noeud->filsD = supprimer(noeud->filsD, successeur->cle);
    }
    return noeud;
}

Abr* importationAbr(char* nomFichier) {
    /* Importe un arbre binaire de recherche stocké dans un fichier .txt
    Structure du fichier .txt :
    - Première ligne : nombre de noeuds
    - Lignes suivantes : clés des noeuds
    */
    FILE* fichier = NULL;
    fichier = fopen(nomFichier, "r");
    if (fichier != NULL) {
        int nbSommets, cle;
        fscanf(fichier, "%d", &nbSommets);
        fscanf(fichier, "%d", &cle);
        Abr* arbre = creerAbr("A", 0, creerNoeud(cle, NULL, NULL, NULL, 0));
        if (arbre != NULL) {
            for (int i = 1 ; i < nbSommets ; i++) {
                fscanf(fichier, "%d", &cle);
                inserer(arbre->racine, cle);
            }
            fclose(fichier);
            printf("Importation de l'arbre du fichier %s réussie !\n", nomFichier);
            MAJHauteurs(arbre->racine);
            return arbre;
        }
        fclose(fichier);
        printf("Erreur d'allocation mémoire !\n");
        return NULL;
    }
    printf("Fichier introuvable !\n");
    return NULL;
}
