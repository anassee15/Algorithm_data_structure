//
// Created by anasse.elboudir on 21/02/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_GRAPHEMATRICE_H
#define ALGORITHME_STRUCTURE_DONNEE_GRAPHEMATRICE_H

#include <iostream>
#include <cmath>

class GrapheMatrice {
    public:
        explicit GrapheMatrice(int nb);
        void afficherGraphe();
        void ajouterArc(char s1, char s2, int = 1);
        void ajouterArcOriente(char s1, char s2, int = 1);
        void supprimerGraphe();
        int degre(char sommet);
        void parcourProfondeurRecursif();
        bool estFortementConnexe();
        bool estOriente();
        bool estPondere();
        bool estConnexe();

    private:
        void visiteSommetProfondeur(int index, bool = true);
        int** links = nullptr;
        int taille;
        bool* visited;
};


#endif //ALGORITHME_STRUCTURE_DONNEE_GRAPHEMATRICE_H
