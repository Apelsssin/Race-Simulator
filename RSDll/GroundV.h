#pragma once
#include "Vehicle.h"
#include "pch.h"
namespace Vehicle {
    class GroundV : public Vehicle {
    public:
        GroundV() {
            type = "�������� ���������";
            quantity = 0;
            travelTime = 0;
        }
    protected:
        int travelTime;
        int quantity;
    };
}