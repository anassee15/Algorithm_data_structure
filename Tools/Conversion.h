//
// Created by anasse.elboudir on 09/04/2022.
//

#ifndef ALGORITHME_STRUCTURE_DONNEE_CONVERSION_H
#define ALGORITHME_STRUCTURE_DONNEE_CONVERSION_H

#include <iostream>

class Conversion {
public:
    static char intToChar(int i) { return char(i + 65); }
    static int charToInt(char c) { return toupper(c) - 'A'; }
};


#endif //ALGORITHME_STRUCTURE_DONNEE_CONVERSION_H
