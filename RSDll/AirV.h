#pragma once
#include "Vehicle.h"
class AirV : public Vehicle {
public:
    AirV() {
        type = "��������� ���������";
    }
    double summTime() override;
    virtual void reduce();
protected:
    int drf = 0;
};