#pragma once
#ifndef DEMAND_H
#define DEMAND_H

#include "Request.h"

class Demand : public Request {
public:
    using Request::Request;

    RequestType getEnumType() const override { return RequestType::Demand; }
    std::string getType() const override { return "Demand"; }
};

#endif 
