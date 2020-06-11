#ifndef STRUCT
#define STRUCT

typedef struct noeud {
    /* Représente un noeud */
    int cle;
    struct noeud* filsG;
    struct noeud* filsD;
    struct noeud* pere;
    int hauteur;
} Noeud;

typedef struct abr {
    /* Représente un arbre */
    char* nom;
    int id;
    Noeud* racine;
} Abr;

#endif
