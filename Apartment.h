#pragma once
#ifndef APARTMENT_H
#define APARTMENT_H

#include "Property.h"

class Apartment : public Property {
public:
    Apartment(const std::string& loc, double a, double p)
        : Property(loc, a, p) {}

    std::string getType() const override { return "Apartment"; }
    PropertyType getEnumType() const override { return PropertyType::Apartment; }
};

#endif 
