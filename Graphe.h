//
// Created by anasse.elboudir on 21/02/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_GRAPHE_H
#define ALGORITHME_STRUCTURE_DONNEE_GRAPHE_H

#include <iostream>

class Graphe {
    public:
        explicit Graphe(int nb);
        void afficherGraphe();
//        void ajouterArc(char s1, char s2, int p=1);
//        void ajouterArcOriente(char s1, char s2, int p=1);
//        int degre(char sommet);
//        void supprimerGraphe();

    private:
        int** links = nullptr;
        int taille;
};


#endif //ALGORITHME_STRUCTURE_DONNEE_GRAPHE_H
