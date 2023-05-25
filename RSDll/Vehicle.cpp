#include "Vehicle.h"
#include <string>
    double Vehicle::summTime() { return time; }
    std::string Vehicle::get_type() { return type; }
    void Vehicle::set_distance(double distance) {
        this->distance = distance;
    }
