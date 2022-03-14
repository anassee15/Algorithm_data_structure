//
// Created by anasse.elboudir on 28/02/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H
#define ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H

#include <list>
#include <stack>
#include <queue>
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
    void parcourProfondeurIteratifPile();
    void parcourLargeurIteratifQueue();


private:
    void visiteSommetProfondeurR(int index);
    void visiteSommetProfondeurI(int index);
    void visiteSommetLargeurI(int index);

    int nb_sommets;
    bool* visited;
    bool* stacked;
    std::stack<int> pile;
    std::queue<int> queue;
    std::list<Link>* links = nullptr;
};


#endif //ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H
