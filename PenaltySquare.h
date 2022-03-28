//
// Created by User on 3/25/2022.
//

#ifndef CO2402ASSIGNMENT_PENALTYSQUARE_H
#define CO2402ASSIGNMENT_PENALTYSQUARE_H
#include <map>

#include "CSquare.h"

class PenaltySquare : public CSquare{
private:
    map<int, int> penalty;

public:
    PenaltySquare();

    PenaltySquare(int squareType, const string &squareName);

    int getBonusMoney(int rolledNumber) override;
};


#endif //CO2402ASSIGNMENT_PENALTYSQUARE_H
