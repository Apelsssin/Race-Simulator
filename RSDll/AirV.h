#pragma once
#include "Vehicle.h"
#include "pch.h"
namespace Vehicle {
    class AirV : public Vehicle {
    public:
        AirV() {
            type = "��������� ���������";
        }
        RSDII_API double summTime() override;
        RSDII_API virtual void reduce();
    protected:
        int drf = 0;
    };
}