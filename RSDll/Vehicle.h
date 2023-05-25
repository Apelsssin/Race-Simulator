#pragma once
#include <string>
class Vehicle {
protected:
    int velocity;
    std::string type;
    double distance;
    double time;
public:
    virtual double summTime();
    Vehicle() {
        velocity = 0;
        type = "ря";
        distance = 0;
    }
    std::string get_type();
    void set_distance(double distance);
};