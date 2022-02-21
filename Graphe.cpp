//
// Created by anasse.elboudir on 21/02/2022.
//

#include "Graphe.h"
using namespace std;

Graphe::Graphe(int nb)
{
    this->taille = nb;
    links = new int*[nb];

    for(int i = 0; i < nb; i++)
    {
        links[i] = new int[nb];

        for(int j=0; j < nb; j++)
        {
            links[i][j] = 0;
        }
    }
}

void Graphe::afficherGraphe()
{
    if (this->links != nullptr)
    {
        for(int i=0; i < this->taille; i++)
        {
            for(int j=0; j < this->taille; j++)
            {
                cout << this->links[i][j] << " ";
            }

            cout << endl;
        }
    }
}


//void ajouterArc(char s1, char s2, int p=1);
//void ajouterArcOriente(char s1, char s2, int p=1);
//int degre(char sommet);
//void supprimerGraphe();