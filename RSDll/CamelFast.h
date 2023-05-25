#pragma once
#include "GroundV.h"
#include <cstdlib>
class CamelFast : public GroundV {
public:
    CamelFast(int distance) {
        type = "Верблюд-быстроход";
        velocity = 40;
        travelTime = 10;
        this->distance = distance;
        time = distance * 1. / velocity;
        quantity = time / travelTime;
        if (fmodf(time, travelTime) == 0) quantity = quantity - 1;
    }
    double summTime() override;
};