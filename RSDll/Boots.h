#pragma once
#include "GroundV.h"
#include "pch.h"
namespace Vehicle {
    class Boots : public GroundV {
    public:
        Boots(int distance) {
            type = "Ботинки-вездеходы";
            velocity = 6;
            travelTime = 60;
            this->distance = distance;
            time = distance * 1. / velocity;
            quantity = time / travelTime;
            if (fmodf(time, travelTime) == 0) quantity = quantity - 1;
        }
        RSDII_API double summTime() override;
    };
}