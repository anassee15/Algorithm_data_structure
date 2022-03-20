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

bool PriorityQueue::isEmpty() {
    return this->liste_priorite.size() == 1;
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
    Nod min;

    if(!this->isEmpty())
    {
        min = this->liste_priorite[1];
        this->liste_priorite[1] = this->liste_priorite[this->liste_priorite.size() - 1];
        this->liste_priorite.pop_back();

        rendreMinimier();
    }
    else
    {
        cout << "file vide !!" << endl;
    }

    return min;
}

void PriorityQueue::rendreMinimier()
{
    int root = 1;
    bool maximier = false;
    int size = this->liste_priorite.size() - 1; // -1 because of we begin at the second case of our vector structure
    Nod save_root = this->liste_priorite[1];

    while((2 * root) <= size && !maximier)
    {
        int save;

        if(2*root + 1 <= size && this->liste_priorite[2*root+1].priority < this->liste_priorite[2*root].priority)
        {
            save = 2*root+1;
        }
        else
        {
            save = 2*root;
        }

        if(this->liste_priorite[save].priority < save_root.priority)
        {
            this->liste_priorite[root] = this->liste_priorite[save];
            root = save;
        }
        else
        {
            maximier = true;
        }
    }

    this->liste_priorite[root] = save_root;
}

Nod PriorityQueue::getMin()
{
    return this->liste_priorite[1];
}

