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

// importAbr
Noeud* creerNoeud(int cle, Noeud* filsG, Noeud* filsD, Noeud* pere, int hauteur);
Abr* creerAbr(char* nom, int id, Noeud* racine);
void libererNoeud(Noeud* noeud);
void libererAbr(Abr* arbre);
Noeud* inserer(Noeud* noeud, int val);
void insererAbr(Abr* arbre, int val);
Noeud* supprimer(Noeud* noeud, int val);
void supprimerAbr(Abr* arbre, int val);
Abr* importationAbr(char* nomFichier);

// exportAbr
void ecritParcoursPrefixe(Noeud* noeud, FILE* fichier, int* step);
void ecritParcoursInfixe(Noeud* noeud, FILE* fichier, int* step);
void ecritParcoursPostfixe(Noeud* noeud, FILE* fichier, int* step);
void ecritHauteur(Noeud* noeud, FILE* fichier);
void ecritPere(Noeud* noeud, FILE* fichier);
void ecritParcours(Noeud* noeud, FILE* fichier, int choixParcours);
void ecritNoeud(Noeud* noeud, FILE* fichier, int* compteur);
void ecritArbre(Noeud* noeud, FILE* fichier, int* compteur);
void exportationDot(Noeud* noeud, char* nomFichier, int choixParcours);

// aleaAbr
int* entiersAlea(int nbSommets, int valMin, int valMax);
void afficheEntiersAlea(int* entiers, int nbSommets);
Abr* creerArbreAlea(char* nom, int id, int nbSommets, int valMin, int valMax);

// parcoursAbr
void parcoursPrefixe(Noeud* noeud);
void parcoursInfixe(Noeud* noeud);
void parcoursPostfixe(Noeud* noeud);

// rechercheAbr
int maximumArbre(Noeud* noeud);
Noeud* noeudMaxArbre(Noeud* noeud);
int minimumArbre(Noeud* noeud);
Noeud* noeudMinArbre(Noeud* noeud);
int appartient(Noeud* noeud, int val);
Noeud* cherche(Noeud* noeud, int val);
int successeurImmediat(Noeud* noeud);
Noeud* noeudSuccesseurImmediat(Noeud* noeud);
int estFeuille(Noeud* noeud);
void afficheAncetres(Noeud* noeud, int val);

// hauteurAbr
int max(int a, int b);
int hauteur(Noeud* noeud);
void moyennes(int n, int valMin, int valMax, float* hauteurMoyenne, float* desequilibreMoyen);
void experimentationMoyennes(char* nomFichier, int nMax, int nInc, int valMin, int valMax);
void MAJHauteurs(Noeud* noeud);

// rotationAbr
int facteurEquilibre(Noeud* noeud);
Noeud* rotationGauche(Noeud* x);
Noeud* rotationDroite(Noeud* x);
Noeud* rotationGaucheDroite(Noeud* x);
Noeud* rotationDroiteGauche(Noeud* x);
