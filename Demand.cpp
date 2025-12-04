#include "Demand.h"

Demand::Demand(std::shared_ptr<Property> prop, double p)
    : Request(prop, p) {}

std::string Demand::getType() const {
    return "Demand";
}
