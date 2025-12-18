#pragma once
#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include <memory>

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

    virtual std::string getType() const = 0;
    virtual PropertyType getEnumType() const = 0;
};
struct PropertyComparator {
    bool operator()(const std::shared_ptr<Property>& a,
                    const std::shared_ptr<Property>& b) const {
        if (!a && !b) return false;
        if (!a) return true;
        if (!b) return false;

        if (a->getType() != b->getType())
            return a->getType() < b->getType();
        if (a->getLocation() != b->getLocation())
            return a->getLocation() < b->getLocation();
        if (a->getArea() != b->getArea())
            return a->getArea() < b->getArea();
        return a->getPrice() < b->getPrice();
    }
};

#endif 
