//
// Created by anasse.elboudir on 28/02/2022.
//

#include "GrapheListe.h"

int GrapheListe::convertCharToIndex(char s)
{
    return toupper(s) - 'A';
}

char GrapheListe::convertIntToChar(int i)
{
    char charedInt;
    charedInt = char(i + 65);
    return charedInt;
}

GrapheListe::GrapheListe(int sommet)
{
    this->nb_sommets = sommet;
    this->links = new std::list<Link>[sommet];
    this->visited = new bool[sommet];
}

GrapheListe::~GrapheListe()
{
    delete[] links;
    links = nullptr;
}

void GrapheListe::ajouterArc(char s1, char s2, int p)
{
    Link nod;
    nod.label = s1;
    nod.ponderation = p;

    this->links[convertCharToIndex(s2)].push_back(nod);

    nod.label = s2;
    nod.ponderation = p;
    this->links[this->convertCharToIndex(s1)].push_back(nod);

}

void GrapheListe::ajouterArcOriente(char s1, char s2, int p)
{
    Link nod;
    nod.label = s2;
    nod.ponderation = p;
    this->links[this->convertCharToIndex(s1)].push_back(nod);
}

void GrapheListe::display()
{
    for (int i = 0; i < this->nb_sommets; i++)
    {
        std::cout << convertIntToChar(i);
        for (auto const &nod : this->links[i])
        {
            std::cout << " --> (" << nod.label << ", " << nod.ponderation << ")";
        }
        std::cout << std::endl;
    }
}

void GrapheListe::visiteSommetProfondeurR(int index, bool show)
{
    // IMPORTANT
    if(this->visited[index])
    {
        return;
    }

    if (show)
    {
        cout << convertIntToChar(index) << endl;
    }

    this->visited[index] = true;

    for (auto& nod : this->links[index])
    {
        visiteSommetProfondeurR(this->convertCharToIndex(nod.label), show);
    }
}

void GrapheListe::parcourProfondeurRecursif()
{
    for(int i=0; i < this->nb_sommets; i++)
    {
        this->visited[i] = false;
    }

    for(int i=0; i < this->nb_sommets; i++)
    {
        this->visiteSommetProfondeurR(i);
    }

}

void GrapheListe::visiteSommetProfondeurI(int index, bool show)
{
    if(!this->visited[index])
    {
        this->pile.push(index);
    }

    while (!this->pile.empty())
    {
        int indice = this->pile.top();
        this->pile.pop();

        cout << convertIntToChar(indice) << endl;
        this->visited[indice] = true;

        for (auto &nod: this->links[indice]) {
            int position = convertCharToIndex(nod.label);
            if (!this->stacked[position] && !this->visited[position])
            {
                this->stacked[position] = true;
                this->pile.push(position);
            }
        }
    }
}

void GrapheListe::parcourProfondeurIteratif()
{
    for(int i=0; i < this->nb_sommets; i++)
    {
        this->visited[i] = false;
    }

    while(!this->pile.empty())
    {
        this->pile.pop();
    }

    for(int i=0; i < this->nb_sommets; i++)
    {
        this->visiteSommetProfondeurI(i);
    }
}

