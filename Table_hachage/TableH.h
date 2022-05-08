//
// Created by anasse.elboudir on 25/04/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_TABLEH_H
#define ALGORITHME_STRUCTURE_DONNEE_TABLEH_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

typedef struct Word {
    string uppercase;
    string definition;
} Word;

class TableH {
    long taille;
    int nbElement;
    list<Word> *table;

public:
    explicit TableH(long taille, const string& path = "");

    ~TableH();

    void insert(const string &s);

    bool search(const string &s);

    int getNbElement() const;

    string toString() const;

    int tempsMax() const;

    double tempsMoyen() const;

    void display();

    friend ostream &operator<<(ostream &os, const TableH &table);

private:
    /**
     * hash function
     */
    int H(const string &) const;

    double fillingRate() const;

    int nbCollision() const;
};

#endif //ALGORITHME_STRUCTURE_DONNEE_TABLEH_H
