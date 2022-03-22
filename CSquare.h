//
// Created by Nadun N. T. Fernando on 2/13/2022.
//

#ifndef CO2402ASSIGNMENT_CSQUARE_H
#define CO2402ASSIGNMENT_CSQUARE_H

#include <string>

using namespace std;

class CSquare {
private:
    int squareType;
    string squareName;

public:
    CSquare();

    CSquare(int squareType, string squareName);

    virtual ~CSquare();

    int getSquareType() const;

    void setSquareType(int squareType);

    const string &getSquareName() const;

    void setSquareName(const string &squareName);

    virtual float getPropertyCost() const;
    virtual float getPropertyRent() const;
    virtual int getColorGroup() const;
    virtual string getPropertyOwner() const;
    virtual void setPropertyOwner(const string propertyOwner);
};


#endif //CO2402ASSIGNMENT_CSQUARE_H
