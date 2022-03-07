//
// Created by anasse.elboudir on 28/02/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H
#define ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H

#include <list>
#include <stack>
#include <iostream>

using namespace std;

typedef struct Link
{
    char label;
    int ponderation;
} Link;

class GrapheListe {
public:
    explicit GrapheListe(int sommet);
    ~GrapheListe();

    static char convertIntToChar(int i);
    static int convertCharToIndex(char s);

    void display();
    void ajouterArc(char s1, char s2, int = 1);
    void ajouterArcOriente(char s1, char s2, int = 1);
    void parcourProfondeurRecursif();
    void parcourProfondeurIteratif();

private:
    void visiteSommetProfondeurR(int index, bool = true);
    void visiteSommetProfondeurI(int index, bool = true);

    std::list<Link>* links = nullptr;
    std::stack<int> pile;

    bool* visited;
    bool* stacked;

    int nb_sommets;
};


#endif //ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H
