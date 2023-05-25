#include "Boots.h"
#include "pch.h"
namespace Vehicle {
    double Boots::summTime() {
        double timeS = time;
        for (int i = 1; i <= quantity; ++i) {
            if (i == 1) timeS = timeS + 10;
            if (i > 1)  timeS = timeS + 5;
        }
        return timeS;
    }
}