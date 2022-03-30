//
// Created by User on 3/22/2022.
//

#ifndef CO2402ASSIGNMENT_GOTOJAILSQUARE_H
#define CO2402ASSIGNMENT_GOTOJAILSQUARE_H

#include "CSquare.h"

class GotoJailSquare : public CSquare{
private:
    const float jailPrice = 50;
public:
    GotoJailSquare();

    GotoJailSquare(int squareType, const string &squareName);

    float getPropertyCost() const override;

};


#endif //CO2402ASSIGNMENT_GOTOJAILSQUARE_H
