//
// Created by anasse.elboudir on 25/04/2022.
//

#include "TableH.h"

TableH::TableH(long taille, const string &path) {
    this->taille = taille;
    this->nbElement = 0;
    this->table = new list<Word>[taille];

    if (!path.empty()) {
        ifstream file(path, ios::in);

        if (file) {
            string line;

            do {
                string word;
                file >> word;
                insert(word);
            } while (getline(file, line));

            file.close();
        } else
            cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

TableH::~TableH() {
    delete[] this->table;
}

ostream &operator<<(ostream &os, const TableH &table) {
    return os << table.toString();;
}

void TableH::insert(const string &s) {
    Word new_s;
    string upper = s;
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    new_s.uppercase = upper;
    new_s.definition = s;

    int indice = this->H(new_s.uppercase);
    this->table[indice].push_back(new_s);
    this->nbElement++;
}

int TableH::H(const string &s) const {
    const int p = 53;
    const int m = this->taille;
    int hash_value = 0;
    int p_pow = 1;

    for (char c: s) {
        hash_value += ((c - 'A' + 1) * p_pow);
        p_pow = (p_pow * p) % m;
    }

    return abs(hash_value) % this->taille;
}

bool TableH::search(const string &s) {
    string upper = s;
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    int indice = this->H(upper);

    if (!this->table[indice].empty()) {
        for (const Word &word: this->table[indice]) {
            if (s == word.definition) {
                return true;
            }
        }
    }
    return false;
}

double TableH::fillingRate() const {
    int fillingRate = 0;

    for (int i = 0; i < this->taille; i++) {
        if (!this->table[i].empty()) {
            fillingRate++;
        }
    }

    return (fillingRate * 100.0) / this->taille;
}

int TableH::nbCollision() const {
    int nbCollision = 0;
    for (int i = 0; i < this->taille; i++) {
        if (this->table[i].size() > 1) {
            nbCollision += this->table[i].size() - 1;
        }
    }
    return nbCollision;
}

int TableH::getNbElement() const {
    return this->nbElement;
}

int TableH::tempsMax() const {
    int nbLienMax = 0;

    for (int i = 0; i < this->taille; i++) {
        int nbLien = 0;

        for (Word word: this->table[i]) {
            nbLien++;
        }

        if (nbLien > nbLienMax) {
            nbLienMax = nbLien;
        }
    }
    return nbLienMax;
}

double TableH::tempsMoyen() const {
    double nbLien = 0;

    for (int i = 0; i < this->taille; i++) {
        int value_lien = 1;
        for (Word word: this->table[i]) {
            nbLien += value_lien;
            value_lien++;
        }
    }

    return nbLien / this->getNbElement();
}

void TableH::display() {
    for (int i = 0; i < this->taille; i++) {
        cout << i;
        for (const Word &word: this->table[i]) {
            cout << " ----> (" << word.definition << ", " << word.uppercase << ")";
        }
        cout << endl;
    }

    cout << "\n-----------------------------------\n" << endl;
    cout << "Nombre d'elements inserer : " << this->getNbElement() << endl;
    cout << "Taux de remplissage : " << this->fillingRate() << "%" << endl;
    cout << "Nombre de collision : " << this->nbCollision() << endl;
    cout << "Temps Max : " << this->tempsMax() << endl;
    cout << "Temps Moyen : " << this->tempsMoyen() << endl;
}

string TableH::toString() const {

    string s;

    s += "\n-----------------------------------\n\n";
    s += "Nombre d'elements inserer : " + to_string(this->getNbElement()) + "\n";
    s += "Taux de remplissage : " + to_string(this->fillingRate()) + "%\n";
    s += "Nombre de collision : " + to_string(this->nbCollision()) + "\n";
    s += "Temps Max : " + to_string(this->tempsMax()) + "\n";
    s += "Temps Moyen : " + to_string(this->tempsMoyen()) + "\n";

    return s;
}