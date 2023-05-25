#pragma once
#include "AirV.h"
#include "pch.h"
namespace Vehicle {
    class Eagle : public AirV {
    public:
        Eagle(int distance) {
            type = "Орел";
            velocity = 8;
            drf = 6;
            distance = (1 - (drf * 1. / 100)) * distance;
            time = distance * 1. / velocity;
            this->distance = distance;
        }
    };
}