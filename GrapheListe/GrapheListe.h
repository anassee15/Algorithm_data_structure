//
// Created by anasse.elboudir on 28/02/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H
#define ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H

#include <list>
#include <iostream>

typedef struct Link
{
    char indice;
    int ponderation;
} Link;

class GrapheListe {
public:
    GrapheListe(int sommet);
    ~GrapheListe();
    void ajouterArc(char s1, char s2, int = 1);
    void ajouterArcOriente(char s1, char s2, int = 1);
    void display();
    char convertIntToChar(int i);
    int convertCharToIndex(char s);

private:
    std::list<Link>* links = nullptr;
    int nb_sommets;
    bool* visited;
};


#endif //ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H
