//
// Created by anasse.elboudir on 14/03/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_PRIORITYQUEUE_H
#define ALGORITHME_STRUCTURE_DONNEE_PRIORITYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

typedef struct Vertex
{
    char label;
    float priority;
} Nod;

/**
 * Comportement de notre liste de priorité : lors de l'insertion, si la clé est deja dans le graph la valeur est modifier,
 * si vous souhaitez diminuer une valeur utiliser diminierClef().
 */
class PriorityQueue {

    vector<Vertex> liste_priorite;

public:
    PriorityQueue();
    void insert(char label, float = 0.0);
    void diminuerClef(char label, float = 0.0, bool = false);
    void display();
    bool isEmpty();
    Vertex extraireMin();
    Vertex getMin();

private:
    void rendreMinimier();
};


#endif //ALGORITHME_STRUCTURE_DONNEE_PRIORITYQUEUE_H
