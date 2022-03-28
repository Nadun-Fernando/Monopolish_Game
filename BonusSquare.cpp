//
// Created by User on 3/25/2022.
//

#include "BonusSquare.h"

BonusSquare::BonusSquare() = default;

int BonusSquare::getBonusMoney(int rolledNumber) {
    map<int, int> :: iterator it;

    for (it = bonus.begin(); it != bonus.end(); it++) {
        if (it->first == rolledNumber) {
            return it->second;
        }
    }
    return 0;
}

BonusSquare::BonusSquare(int squareType, const string &squareName) : CSquare(squareType, squareName) {
    bonus.insert(pair<int, int> (1, 20));
    bonus.insert(pair<int, int> (2, 50));
    bonus.insert(pair<int, int> (3, 100));
    bonus.insert(pair<int, int> (4, 150));
    bonus.insert(pair<int, int> (5, 200));
    bonus.insert(pair<int, int> (6, 300));
}


