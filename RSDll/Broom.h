#pragma once
#include "AirV.h"
#include <cstdlib>
#include "pch.h"
namespace Vehicle {
    class Broom : public AirV {
    public:
        Broom(int distance) {
            type = "Метла";
            velocity = 20;
            div_t res = div(distance, 1000);
            drf = res.quot;
            distance = (1 - (drf * 1. / 100)) * distance;
            time = distance * 1. / velocity;
            this->distance = distance;
        }
    };
}