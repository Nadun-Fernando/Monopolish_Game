//
// Created by User on 3/25/2022.
//

#ifndef CO2402ASSIGNMENT_BONUSSQUARE_H
#define CO2402ASSIGNMENT_BONUSSQUARE_H

#include <map>

#include "CSquare.h"

class BonusSquare : public CSquare{
private:
    map<int, int> bonus;

public:
    BonusSquare();

    BonusSquare(int squareType, const string &squareName);

    int getBonusMoney(int rolledNumber);


};


#endif //CO2402ASSIGNMENT_BONUSSQUARE_H
