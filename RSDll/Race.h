#pragma once
#include "pch.h"
namespace Vehicle {
    class Race {
    private:
        int type;
    public:
        Race(int i) {
            type = i;
        }
        RSDII_API int get_type();
    };
}