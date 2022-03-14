//
// Created by anasse.elboudir on 14/03/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_PRIORITYQUEUE_H
#define ALGORITHME_STRUCTURE_DONNEE_PRIORITYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

typedef struct Nod
{
    char label;
    float priority;
} Nod;

class PriorityQueue {
public:
    PriorityQueue();
    void insert(char label, float = 0.0);
    void display();
    Nod extraireMin();

private:
    void diminuerClef(char label, float = 0.0);
    std::vector<Nod> liste_priorite;
};


#endif //ALGORITHME_STRUCTURE_DONNEE_PRIORITYQUEUE_H
