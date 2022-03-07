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
}

GrapheListe::~GrapheListe()
{
    delete[] links;
    links = nullptr;
}

void GrapheListe::ajouterArc(char s1, char s2, int p)
{
    Link nod;
    nod.indice = s1;
    nod.ponderation = p;

    this->links[convertCharToIndex(s2)].push_back(nod);

    nod.indice = s2;
    nod.ponderation = p;
    this->links[this->convertCharToIndex(s1)].push_back(nod);

}

void GrapheListe::ajouterArcOriente(char s1, char s2, int p)
{
    Link nod;
    nod.indice = s2;
    nod.ponderation = p;
    this->links[this->convertCharToIndex(s1)].push_back(nod);
}

void GrapheListe::display()
{
    for (int i = 0; i < this->nb_sommets; i++)
    {
        std::cout << convertIntToChar(i);
        for (auto const &n : this->links[i])
        {
            std::cout << "|" << n.indice;
        }
        std::cout << std::endl;
    }
}