#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include "Property.h"

class House : public Property {
public:
    House(const std::string& loc, double a, double p)
        : Property(loc, a, p) {}

    std::string getType() const override { return "House"; }
    PropertyType getEnumType() const override { return PropertyType::House; }
};

#endif 
