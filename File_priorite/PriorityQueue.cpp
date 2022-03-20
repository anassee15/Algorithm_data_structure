//
// Created by anasse.elboudir on 14/03/2022.
//

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
    Nod suppr_first_case;
    suppr_first_case.priority = -1;
    suppr_first_case.label = ' ';
    this->liste_priorite.push_back(suppr_first_case);
}

void PriorityQueue::insert(char label, float priority)
{
    Nod noeud;
    noeud.label = label;
    noeud.priority = (float) INT_MAX;

    this->liste_priorite.push_back(noeud);
    diminuerClef(label, priority);
}

void PriorityQueue::diminuerClef(char label, float priority)
{
    bool find = false;
    int i = 0;

    while (!find && this->liste_priorite.size() >= i)
    {
        if (this->liste_priorite[i].label == label)
        {
            this->liste_priorite[i].priority = priority;
            find = true;
        }
        i++;
    }

    i--;

    while (this->liste_priorite[i/2].priority > this->liste_priorite[i].priority && i > 1)
    {
        Nod tmp = this->liste_priorite[i/2];
        this->liste_priorite[i/2] = this->liste_priorite[i];
        this->liste_priorite[i] = tmp;

        i /= 2;
    }
}

void PriorityQueue::display()
{
    for(int i=1; i < this->liste_priorite.size(); i++)
    {
        cout << "('" << this->liste_priorite[i].label << "', " << this->liste_priorite[i].priority << ")  ";
    }

    cout << endl;
}


Nod PriorityQueue::extraireMin()
{
    Nod min = this->liste_priorite[1];
    this->liste_priorite[1] = this->liste_priorite[this->liste_priorite.size()];
    this->liste_priorite.pop_back();

    rendreMinimier();
    return min;
}

void PriorityQueue::rendreMinimier()
{
    //TODO: utiliser rendreMaximier()
}

Nod PriorityQueue::getMin()
{
    return this->liste_priorite[1];
}

