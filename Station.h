//
// Created by User on 3/22/2022.
//

#ifndef CO2402ASSIGNMENT_STATION_H
#define CO2402ASSIGNMENT_STATION_H

#include "CSquare.h"

class Station {
private:
    const float stationCost = 200.00;
    const float ticketPrice = 10.00;

public:
    Station();

    float getStationCost() const;

    float getTicketPrice() const;
};


#endif //CO2402ASSIGNMENT_STATION_H
