//
// Created by User on 3/25/2022.
//

#include "PenaltySquare.h"

PenaltySquare::PenaltySquare() = default;


PenaltySquare::PenaltySquare(int squareType, const string &squareName) : CSquare(squareType, squareName) {
    penalty.insert(pair<int, int> (1, 20));
    penalty.insert(pair<int, int> (2, 50));
    penalty.insert(pair<int, int> (3, 100));
    penalty.insert(pair<int, int> (4, 150));
    penalty.insert(pair<int, int> (5, 200));
    penalty.insert(pair<int, int> (6, 300));
}

int PenaltySquare::getBonusMoney(int rolledNumber) {
    map<int, int> :: iterator it;

    for (it = penalty.begin(); it != penalty.end(); it++) {
        if (it->first == rolledNumber) {
            return it->second;
        }
    }
    return 0;
}
