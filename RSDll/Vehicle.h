#pragma once
#include <string>
#include "pch.h"
namespace Vehicle {
    class Vehicle {
    protected:
        int velocity;
        std::string type;
        double distance;
        double time;
    public:
        RSDII_API virtual double summTime();
        Vehicle() {
            velocity = 0;
            type = "ря";
            distance = 0;
        }
        RSDII_API std::string get_type();
        RSDII_API void set_distance(double distance);
    };
}