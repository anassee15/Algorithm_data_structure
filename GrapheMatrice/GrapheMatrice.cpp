//
// Created by anasse.elboudir on 21/02/2022.
//

#include "GrapheMatrice.h"

GrapheMatrice::GrapheMatrice(int nb) {
    this->links = new int *[nb];
    this->visited = new bool[nb];

    this->taille = nb;

    for (int i = 0; i < this->taille; ++i) {
        this->links[i] = new int[nb];
        this->visited[i] = false;

        for (int j = 0; j < this->taille; j++) {
            this->links[i][j] = 0;
        }
    }
}

GrapheMatrice::~GrapheMatrice() {
    for (int i = 0; i < this->taille; ++i) {
        delete[] this->links[i];
    }

    delete this->links;
}

void GrapheMatrice::display() {
    if (this->links != nullptr) {
        for (int i = 0; i < this->taille; i++) {
            for (int j = 0; j < this->taille; j++) {
                cout << this->links[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void GrapheMatrice::ajouterArc(char s1, char s2, int p) {
    int index1 = Conversion::charToInt(s1);
    int index2 = Conversion::charToInt(s2);

    if (this->links != nullptr) {
        this->links[index1][index2] = p;
        this->links[index2][index1] = p;
    }
}

void GrapheMatrice::ajouterArcOriente(char s1, char s2, int p) {
    int index1 = Conversion::charToInt(s1);
    int index2 = Conversion::charToInt(s2);

    if (this->links != nullptr) {
        this->links[index1][index2] = p;
    }
}

int GrapheMatrice::degre(char sommet) {
    int index = Conversion::charToInt(sommet);
    int degre = 0;

    for (int j = 0; j < this->taille; j++) {
        if (this->links[index][j] != 0) {
            degre++;
        }
    }
    return degre;
}

bool GrapheMatrice::estFortementConnexe() {
    int nb_arrete = 0;

    for (int i = 0; i < this->taille; i++) {
        for (int j = 0; j < this->taille; j++) {
            if (this->links[i][j] == 1) {
                nb_arrete++;
            }
        }
    }
    return nb_arrete > (this->taille * log2(this->taille));
}

bool GrapheMatrice::estOriente() {
    for (int i = 0; i < this->taille; i++) {
        for (int j = 0; j < this->taille; j++) {
            if (this->links[i][j] != this->links[j][i]) {
                return true;
            }
        }
    }
    return false;
}

bool GrapheMatrice::estPondere() {
    for (int i = 0; i < this->taille; i++) {
        for (int j = 0; j < this->taille; j++) {
            if (this->links[i][j] != 0 && this->links[i][j] != 1) {
                return true;
            }
        }
    }
    return false;
}

bool GrapheMatrice::estConnexe() {
    for (int i = 0; i < this->taille; i++) {
        this->visited[i] = false;
    }

    visiteSommetProfondeurR(0, false);

    for (int i = 0; i < this->taille; i++) {
        if (!this->visited[i]) {
            return false;
        }
    }
    return true;
}

void GrapheMatrice::parcoursProfondeurRecursif() {
    // on marque tout les sommets comme non visiter
    for (int i = 0; i < this->taille; i++) {
        this->visited[i] = false;
    }

    // on visite chaque sommet en profondeur
    for (int i = 0; i < this->taille; i++) {
        this->visiteSommetProfondeurR(i);
    }
}

void GrapheMatrice::visiteSommetProfondeurR(int index, bool show) {
    // si le sommet est deja visiter on ne continue pas
    if (this->visited[index]) {
        return;
    }

    if (show) {
        cout << Conversion::intToChar(index) << endl;
    }

    // on marque le sommet comme visité
    this->visited[index] = true;

    // on cherche les sommets voisin du sommet actuel
    for (int j = 0; j < this->taille; j++) {
        if (this->links[index][j] != 0 && !this->visited[j]) {
            visiteSommetProfondeurR(j, show);
        }
    }
}

void GrapheMatrice::parcoursProfondeurPile() {

}

void GrapheMatrice::visiteSommetProfondeurPile() {

}
