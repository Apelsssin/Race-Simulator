#include "Exceptions.h"
#include "pch.h"
namespace Vehicle {
    const char* Exceptions::what() const noexcept
    {
        return message.c_str();
    }
}