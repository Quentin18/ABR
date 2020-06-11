/**
 * \file analyseHauteur.c
 * \brief Analyse de hauteurs des ABR
 * \author Quentin Deschamps
 * \date 2020
 *
 * Analyse des hauteurs moyennes des ABR
 * Lancer le script Python graphiqueHauteur.py pour afficher le graphe :
 * python3 graphiqueHauteur.py
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hauteurAbr.h"


int main(int argc, char const *argv[]) {
    srand(time(NULL)); // initialisation de rand

    // Crée le fichier hauteur.csv
    experimentationMoyennes("hauteur.csv", 2000, 2, 0, 100);

    return 0;
}
