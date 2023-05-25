#include "Camel.h"
#include "pch.h"
namespace Vehicle {
    double Camel::summTime() {
        double timeS = time;
        for (int i = 1; i <= quantity; ++i) {
            if (i == 1) timeS = timeS + 5;
            if (i > 1)  timeS = timeS + 8;
        }
        return timeS;
    }
}