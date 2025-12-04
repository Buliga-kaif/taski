#include "Apartment.h"

Apartment::Apartment(const std::string& loc, double a, double p)
    : location(loc), area(a), price(p) {}

std::string Apartment::getLocation() const {
    return location;
}

double Apartment::getArea() const {
    return area;
}

double Apartment::getPrice() const {
    return price;
}

std::string Apartment::getType() const {
    return "Apartment";
}
