#pragma once
#ifndef OFFER_H
#define OFFER_H

#include "Request.h"

class Offer : public Request {
public:
    using Request::Request;

    RequestType getEnumType() const override { return RequestType::Offer; }
    std::string getType() const override { return "Offer"; }
};

#endif 
