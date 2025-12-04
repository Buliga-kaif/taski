#include "Request.h"

Request::Request(std::shared_ptr<Property> prop, double p)
    : property(prop), price(p) {}

std::shared_ptr<Property> Request::getProperty() const {
    return property;
}

double Request::getPrice() const {
    return price;
}
