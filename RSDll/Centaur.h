#pragma once
#include "GroundV.h"
#include <cstdlib>
#include "pch.h"
namespace Vehicle {
    class Centaur : public GroundV {
    public:
        Centaur(int distance) {
            type = "Кентавр";
            velocity = 15;
            travelTime = 8;
            this->distance = distance;
            time = distance * 1. / velocity;
            quantity = time / travelTime;
            if (fmodf(time, travelTime) == 0) quantity = quantity - 1;
        }
        RSDII_API double summTime() override;
    };
}