#include "Offer.h"

Offer::Offer(std::shared_ptr<Property> prop, double p)
    : Request(prop, p) {}

std::string Offer::getType() const {
    return "Offer";
}
