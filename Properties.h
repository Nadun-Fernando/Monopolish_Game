//
// Created by Nadun N. T. Fernando on 2/13/2022.
//

#ifndef CO2402ASSIGNMENT_PROPERTIES_H
#define CO2402ASSIGNMENT_PROPERTIES_H

#include "CSquare.h"

using namespace std;

class Properties : public CSquare {
private:
    string propertyOwner;
    float propertyCost{};
    float propertyRent{};
    int colorGroup{};
    bool mortgaged = false;

public:
    Properties();

    Properties(int squareType, const string &squareName, float propertyCost, float propertyRent, int colorGroup);

    virtual ~Properties();

    string getPropertyOwner() const;

    void setPropertyOwner(const string propertyOwner);

    float getPropertyCost() const;

    void setPropertyCost(float propertyCost);

    float getPropertyRent() const;

    void setPropertyRent(float propertyRent);

    int getColorGroup() const;

    void setColorGroup(int colorGroup);

    bool isMortgaged() const;

    void setMortgaged(bool mortgaged);


};


#endif //CO2402ASSIGNMENT_PROPERTIES_H
