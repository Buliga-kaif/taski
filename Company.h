#pragma once
#ifndef COMPANY_H
#define COMPANY_H

#include "Client.h"
#include "Request.h"
#include <vector>
#include <memory>
#include <map>
#include <string>
#include <set>

struct PropertyComparator;

class Company {
private:
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Request>> requests;
    
    
    std::set<std::shared_ptr<Property>, PropertyComparator> properties;

    double commissionPercent;

public:
    Company(double commission);

    void addClient(std::shared_ptr<Client> client);
    void addRequest(std::shared_ptr<Request> request);
    size_t getUniquePropertyCount() const { return properties.size(); }
    void listUniqueProperties() const;

    void showAllOffers(const std::string& type) const;
    void showAllDemands(const std::string& type) const;

    void showClientByPassport(const std::string& passportId) const;

    std::vector<std::shared_ptr<Request>> findRequests(double price, const std::string& location, double area) const;

    std::vector<std::shared_ptr<Request>> findOffersByPriceRange(
        double minPrice, double maxPrice, const std::string& propertyType = ""
    ) const;

    double calculateProfit() const;

    std::vector<std::shared_ptr<Request>> getMostPopularRequests() const;
};

#endif 
