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

        static char convertIntToChar(int i);
        static int convertCharToIndex(char s);

        void afficherGraphe();
        void supprimerGraphe();
        void parcourProfondeurRecursif();
        void ajouterArc(char s1, char s2, int = 1);
        void ajouterArcOriente(char s1, char s2, int = 1);

        int degre(char sommet);
        bool estFortementConnexe();
        bool estOriente();
        bool estPondere();
        bool estConnexe();


    private:
        void visiteSommetProfondeurR(int index, bool = true);

        int taille;
        bool* visited;
        int** links = nullptr;
};


#endif //ALGORITHME_STRUCTURE_DONNEE_GRAPHEMATRICE_H
