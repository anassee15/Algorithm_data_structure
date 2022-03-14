//
// Created by anasse.elboudir on 14/03/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_PRIORITYQUEUE_H
#define ALGORITHME_STRUCTURE_DONNEE_PRIORITYQUEUE_H

#include <iostream>
#include <vector>

typedef struct Nod
{
    char label;
    float priority;
} Nod;

class PriorityQueue {
public:
    PriorityQueue();
    void insertion(Nod element);
    Nod extraireMin();
    void diminuerClef();

private:
    std::vector<Nod> liste_priorite;
};


#endif //ALGORITHME_STRUCTURE_DONNEE_PRIORITYQUEUE_H
