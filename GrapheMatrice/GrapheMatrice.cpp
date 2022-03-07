//
// Created by anasse.elboudir on 21/02/2022.
//

#include "GrapheMatrice.h"
using namespace std;

GrapheMatrice::GrapheMatrice(int nb)
{
    this->taille = nb;
    this->links = new int*[nb];

    for(int i = 0; i < nb; i++)
    {
        this->links[i] = new int[nb];

        for(int j=0; j < nb; j++)
        {
            this->links[i][j] = 0;
        }
    }

    this->visited = new bool[taille];
}

void GrapheMatrice::afficherGraphe()
{
    if (this->links != nullptr)
    {
        for(int i=0; i < this->taille; i++)
        {
            for(int j=0; j < this->taille; j++)
            {
                cout << this->links[i][j] << "  ";
            }

            cout << endl;
        }
        cout << endl;
    }
}

int GrapheMatrice::convertCharToIndex(char s)
{
    return toupper(s) - 'A';
}

char GrapheMatrice::convertIntToChar(int i)
{
    char charedInt;
    charedInt = char(i + 65);
    return charedInt;
}

void GrapheMatrice::ajouterArc(char s1, char s2, int p)
{
    int index1 = convertCharToIndex(s1);
    int index2 = convertCharToIndex(s2);

    if(this->links != nullptr)
    {
        this->links[index1][index2] = p;
        this->links[index2][index1] = p;
    }
}

void GrapheMatrice::ajouterArcOriente(char s1, char s2, int p)
{
    int index1 = convertCharToIndex(s1);
    int index2 = convertCharToIndex(s2);

    if(this->links != nullptr)
    {
        this->links[index1][index2] = p;
    }
}

int GrapheMatrice::degre(char sommet)
{
    int index = convertCharToIndex(sommet);
    int degre = 0;

    if(this->links != nullptr)
    {
        for(int i=0; i < this->taille; i++)
        {
            if(this->links[index][i] != 0)
            {
                degre += 1;
            }
        }
    }
    return degre;
}

void GrapheMatrice::supprimerGraphe()
{
    for(int i=0; i < this->taille; i++)
    {
        delete[] links[i];
    }

    delete[] links;
}

bool GrapheMatrice::estFortementConnexe()
{
    int nb_arrete = 0;

    for(int i=0; i < this->taille; i++)
    {
        for (int j=0; j < this->taille; j++)
        {
            if (this->links[i][j] == 1)
            {
                nb_arrete++;
            }
        }
    }

    double sommet = this->taille;

    if(nb_arrete > sommet * std::log2(sommet))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GrapheMatrice::estOriente()
{
    for(int i=0; i < this->taille; i++)
    {
        for (int j=0; j < this->taille; j++)
        {
            if (this->links[i][j] != this->links[j][i])
            {
                return true;
            }
        }
    }
    return false;
}

bool GrapheMatrice::estPondere()
{
    for(int i=0; i < this->taille; i++)
    {
        for (int j=0; j < this->taille; j++)
        {
            if (this->links[i][j] != 0 && this->links[i][j] != 1)
            {
                return true;
            }
        }
    }
    return false;
}

void GrapheMatrice::visiteSommetProfondeurR(int index, bool show)
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

    for(int j=0; j < this->taille; j++)
    {
        if(this->links[index][j] != 0 && !this->visited[j])
        {
            visiteSommetProfondeurR(j, show);
        }
    }
}

void GrapheMatrice::parcourProfondeurRecursif()
{
    for(int i=0; i < this->taille; i++)
    {
        this->visited[i] = false;
    }

    for(int i=0; i < this->taille; i++)
    {
        this->visiteSommetProfondeurR(i);
    }
}

bool GrapheMatrice::estConnexe()
{
    for(int i=0; i < this->taille; i++)
    {
        this->visited[i] = false;
    }

    visiteSommetProfondeurR(0, false);

    for(int i= 0; i < this->taille; i++)
    {
        if(!this->visited[i])
        {
            return false;
        }
    }

    return true;
}
