#pragma once
#include <exception>
#include <iostream>
#include <string>
#include "pch.h"
namespace Vehicle {

    class Exceptions : public std::exception
    {
    private:
        std::string message;
    public:
        Exceptions(const std::string& message) {
            this->message = message;
        }
        RSDII_API const char* what() const noexcept override;
    };
}