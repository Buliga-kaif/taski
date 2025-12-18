#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include "Property.h"
#include <memory>

enum class RequestType {
    Demand,
    Offer
};

class Request {
protected:
    std::shared_ptr<Property> property;
    double price;  

public:
    Request(std::shared_ptr<Property> prop, double p)
        : property(std::move(prop)), price(p) {}

    virtual ~Request() = default;

    virtual RequestType getEnumType() const = 0;
    virtual std::string getType() const = 0;

    std::shared_ptr<Property> getProperty() const { return property; }
    double getPrice() const { return price; }
};

#endif 
