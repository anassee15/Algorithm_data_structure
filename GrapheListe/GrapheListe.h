//
// Created by anasse.elboudir on 28/02/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H
#define ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <stack>
#include <queue>
#include "../File_priorite/PriorityQueue.h"
#include "../Tools/Conversion.h"

using namespace std;

typedef enum
{
    LARGEUR, PROFONDEUR, PRIM, DIJKSTRA
} Mode;

typedef struct Link
{
    char label;
    int ponderation;
} Link;

class GrapheListe {

    int nb_sommets;
    bool* visited;
    bool* stacked;
    int poid_dijkstra;

    stack<int> pile;
    queue<int> queue;
    list<Link>* links = nullptr;

    PriorityQueue priorityQueue;

public:
    explicit GrapheListe(int nb_sommet);
    explicit GrapheListe(const string& path, bool ponderer);
    ~GrapheListe();

    // operation de base graph
    void display();
    void ajouterArc(char s1, char s2, int = 1);
    void ajouterArcOriente(char s1, char s2, int = 1);

    bool estFortementConnexe();
    bool estOriente();
    bool estPondere();
    bool estConnexe();

    int degre(char sommet);

    // initialisation
    void initVisited();
    void initStacked();
    void clearStack();
    void clearQueue();

    // parcours
    void parcourProfondeurRecursif();
    void parcourProfondeurIteratifPile();
    void parcourLargeurIteratifQueue();
    void parcourGeneralise(Mode = PROFONDEUR);
    void prim(char = 'A', int = 0);
    void dijkstra(char = 'A', int = 0);

private:
    void visiteSommetProfondeurR(int index, bool = true);
    void visiteSommetProfondeurI(int index);
    void visiteSommetLargeurI(int index);
    void visiteSommetGeneraliseI(int index, Mode mode, int = 0);
    void visiteSommetPrim(int index, int = 0, Mode = PRIM);
    void visiteSommetDijkstra(int index, int = 0);
    void find_priority(Mode mode, int* priority, int index_current, int = 0);
};


#endif //ALGORITHME_STRUCTURE_DONNEE_GRAPHELISTE_H
