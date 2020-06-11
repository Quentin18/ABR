"""
Graphe du fichier hauteur.csv
"""
import matplotlib.pyplot as plt


f = open('hauteur.csv')
lignes = f.readlines()
listeDonnees = [[], [], []]
listeLabel = ["n", "Hauteur moyenne", "Facteur de déséquilibre moyen"]

for l in lignes:
    donnees = l.split(";")
    for i in range(len(donnees)):
        listeDonnees[i].append(float(donnees[i]))

for i in range(1, len(listeDonnees)):
    plt.plot(listeDonnees[0], listeDonnees[i], label=listeLabel[i])

plt.legend()
plt.xlabel("Nombre de noeuds")
plt.ylabel("Hauteur moyenne / Facteur de déséquilibre moyen")
plt.title("Hauteur moyenne et facteur de déséquilibre d'un ABR en fonction du nombre de noeuds")
plt.show()
plt.tight_layout()
f.close()
