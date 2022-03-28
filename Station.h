//
// Created by User on 3/22/2022.
//

#ifndef CO2402ASSIGNMENT_STATION_H
#define CO2402ASSIGNMENT_STATION_H

#include "CSquare.h"
#include "Properties.h"

class Station : public CSquare{
private:
    const float stationCost = 200.00;
    const float ticketPrice = 10.00;
    string propertyOwner;


public:
    Station();

    Station(int squareType, const string &squareName);

    float getPropertyCost() const override;

    float getPropertyRent() const override;

    string getPropertyOwner() const override;

    void setPropertyOwner(const string propertyOwner) override;
};


#endif //CO2402ASSIGNMENT_STATION_H
