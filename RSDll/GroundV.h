#pragma once
#include "Vehicle.h"
class GroundV : public Vehicle {
public:
    GroundV() {
        type = "Наземный транспорт";
        quantity = 0;
        travelTime = 0;
    }
protected:
    int travelTime;
    int quantity;
};