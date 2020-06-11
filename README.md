# ABR
Implémentation des Arbres Binaires de Recherche en C

![](https://github.com/Quentin18/ABR/blob/master/img/abr.png)

## Installation
Clonez le projet :
```bash
git clone https://github.com/Quentin18/ABR.git
```

Générez la librairie statique *libabr* :
```bash
cd src
make
```

Compilez les exemples pour voir l'utilisation de la librairie :
```bash
cd ../exemples
make
```

## Fonctionnalités
Voici la liste des fonctionnalités de la librairie *libabr* :

* Création de noeuds, d'arbres
* Génération d'arbres aléatoires
* Insertion, suppression de noeuds
* Parcours préfixe, infixe, postfixe
* Importation d'un arbre par un fichier *.txt*
* Exportation en fichier *.dot*
* Recherche d'éléments, maximum, minimum
* Hauteurs
* Rotations simples et doubles

![](https://github.com/Quentin18/ABR/blob/master/img/abr2.png)

## Analyse
Dans le répertoire *exemples*, vous trouverez le fichier *analyseHauteur.c* qui étudie la variation de la hauteur moyenne et du facteur de déséquilibre moyen d'un arbre binaire de recherche en fonction du nombre de noeuds. Celui-ci génère le fichier *hauteur.csv* qui peut être visionné par le script Python *graphiqueHauteur.py* :
```bash
python3 graphiqueHauteur.py
```
Vous avez besoin de *matplotlib* pour visionner le graphe :
```bash
pip3 install matplotlib
```

## Contact
Quentin Deschamps: quentindeschamps18@gmail.com

## Licence
[MIT](https://choosealicense.com/licenses/mit/)
