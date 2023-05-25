#pragma once
#include <math.h>
#include "GroundV.h"
class Camel : public GroundV {
public:
    Camel(int distance) {
        type = "Верблюд";
        velocity = 10;
        travelTime = 30;
        this->distance = distance;
        time = distance * 1. / velocity;
        quantity = time / travelTime;
        if (fmodf(time, travelTime) == 0) quantity = quantity - 1;
    }
    double summTime() override;
};