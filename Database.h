#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include "Client.h"
#include "Request.h"
#include "Company.h"
#include <vector>
#include <memory>
#include <string>

class Database {
private:
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Request>> requests;
    std::unique_ptr<Company> company;
    std::string filename;

public:
    Database(const std::string& file, double commission);

    void addClient(const std::string& id, const std::string& name);
    void addRequest(std::shared_ptr<Request> request);

    void showAllOffers(const std::string& type) const;
    void showAllDemands(const std::string& type) const;

    void showClientByPassport(const std::string& passportId) const;

    void findRequestByParams(double price, const std::string& location, double area) const;

    void findOffersByPriceRange(double minPrice, double maxPrice, const std::string& type = "") const;

    void showProfit() const;
    void showMostPopularRequests() const;

    void listUniqueProperties() const;

    void saveToFile() const;
    void loadFromFile();

    void listClients() const;
    void listRequests() const;
};

#endif 
