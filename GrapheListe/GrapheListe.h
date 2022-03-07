//
// Created by anasse.elboudir on 28/02/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H
#define ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H

#include <list>
#include <iostream>
using namespace std;

typedef struct Link
{
    char label;
    int ponderation;
} Link;

class GrapheListe {
public:
    GrapheListe(int sommet);
    ~GrapheListe();
    static char convertIntToChar(int i);
    static int convertCharToIndex(char s);
    void ajouterArc(char s1, char s2, int = 1);
    void ajouterArcOriente(char s1, char s2, int = 1);
    void display();
    void parcourProfondeurRecursif();
    void parcourProfondeurIteratif();

private:
    void visiteSommetProfondeurR(int index, bool = true);
    void visiteSommetProfondeurI(int index, bool = true);
    std::list<Link>* links = nullptr;
    int nb_sommets;
    bool* visited;
    bool* stacked;
};


#endif //ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H
