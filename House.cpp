#include "House.h"

House::House(const std::string& loc, double a, double p)
    : location(loc), area(a), price(p) {}

std::string House::getLocation() const {
    return location;
}

double House::getArea() const {
    return area;
}

double House::getPrice() const {
    return price;
}

std::string House::getType() const {
    return "House";
}
