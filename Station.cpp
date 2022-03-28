//
// Created by User on 3/22/2022.
//

#include "Station.h"

Station::Station() {

}


Station::Station(int squareType, const string &squareName) : CSquare(squareType, squareName) {

}

float Station::getPropertyCost() const {
    return stationCost;
}

float Station::getPropertyRent() const {
    return ticketPrice;
}

string Station::getPropertyOwner() const {
    return propertyOwner;
}

void Station::setPropertyOwner(const string propertyOwner) {
    this->propertyOwner = propertyOwner;
}


