
#pragma once
#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

enum class PropertyType {
    House,
    Apartment
};

class Property {
protected:
    std::string location;
    double area;
    double price;

public:
    Property(const std::string& loc, double a, double p)
        : location(loc), area(a), price(p) {}

    virtual ~Property() = default;

    virtual std::string getLocation() const { return location; }
    virtual double getArea() const { return area; }
    virtual double getPrice() const { return price; }

    virtual std::string getType() const = 0;  // pure virtual
    virtual PropertyType getEnumType() const = 0; // для switch-friendly идентификации
};

#endif
