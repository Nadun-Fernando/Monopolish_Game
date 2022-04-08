//
// Created by Nadun N. T. Fernando on 2/13/2022.
//

#include "Properties.h"

Properties::Properties() = default;

Properties::Properties(int squareType, const string &squareName, float propertyCost, float propertyRent, int colorGroup)
        : CSquare(squareType, squareName), propertyCost(propertyCost), propertyRent(propertyRent),
          colorGroup(colorGroup) {}

Properties::~Properties() {

}

float Properties::getPropertyCost() const {
    return propertyCost;
}

void Properties::setPropertyCost(float propertyCost) {
    Properties::propertyCost = propertyCost;
}

float Properties::getPropertyRent() const {
    return propertyRent;
}

void Properties::setPropertyRent(float propertyRent) {
    Properties::propertyRent = propertyRent;
}

int Properties::getColorGroup() const {
    return colorGroup;
}

void Properties::setColorGroup(int colorGroup) {
    Properties::colorGroup = colorGroup;
}

string Properties::getPropertyOwner() const {
    return propertyOwner;
}

void Properties::setPropertyOwner(const string propertyOwner) {
    Properties::propertyOwner = propertyOwner;
}

bool Properties::isMortgaged() const {
    return mortgaged;
}

void Properties::setMortgaged(bool mortgaged) {
    Properties::mortgaged = mortgaged;
}



