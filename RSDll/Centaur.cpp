#include "Centaur.h"
double Centaur::summTime() {
    double timeS = time;
    for (int i = 1; i <= quantity; ++i) {
        timeS = timeS + 2;
    }
    return timeS;
}