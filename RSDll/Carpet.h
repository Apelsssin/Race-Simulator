#pragma once
#include "AirV.h"
#include "pch.h"
namespace Vehicle {
    class Carpet : public AirV {
    public:
        Carpet(int distance) {
            type = "Ковер-самолет";
            velocity = 10;
            if (distance >= 1000 && distance < 5000) drf = 3;
            if (distance >= 5000 && distance < 10000) drf = 10;
            if (distance >= 10000) drf = 5;
            distance = (1 - (drf * 1. / 100)) * distance;
            time = distance * 1. / velocity;
            this->distance = distance;
        }
    };
}