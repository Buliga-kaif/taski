#include "Company.h"
#include <iostream>

Company::Company(double commission) : commissionPercent(commission) {}

void Company::addClient(std::shared_ptr<Client> client) {
    clients.push_back(client);
}

void Company::addRequest(std::shared_ptr<Request> request) {
    requests.push_back(request);
}

void Company::showAllOffers(const std::string& type) const {
    for (const auto& req : requests) {
        if (req->getType() == "Offer" && req->getProperty()->getType() == type) {
            std::cout << "Offer: " << req->getProperty()->getType() << " at " << req->getProperty()->getLocation()
                << ", Price: " << req->getPrice() << "\n";
        }
    }
}

void Company::showAllDemands(const std::string& type) const {
    for (const auto& req : requests) {
        if (req->getType() == "Demand" && req->getProperty()->getType() == type) {
            std::cout << "Demand: " << req->getProperty()->getType() << " at " << req->getProperty()->getLocation()
                << ", Price: " << req->getPrice() << "\n";
        }
    }
}

void Company::showClientByPassport(const std::string& passportId) const {
    for (const auto& client : clients) {
        if (client->getPassportId() == passportId) {
            std::cout << "Client: " << client->getFullName() << ", Passport ID: " << client->getPassportId() << "\n";
            return;
        }
    }
    std::cout << "Client not found.\n";
}

std::vector<std::shared_ptr<Request>> Company::findRequests(double price, const std::string& location, double area) const {
    std::vector<std::shared_ptr<Request>> result;
    for (const auto& req : requests) {
        auto prop = req->getProperty();
        if (prop->getPrice() == price && prop->getLocation() == location && prop->getArea() == area) {
            result.push_back(req);
        }
    }
    return result;
}

double Company::calculateProfit() const {
    double total = 0.0;
    for (const auto& req : requests) {
        if (req->getType() == "Offer") {
            total += req->getPrice() * (commissionPercent / 100.0);
        }
    }
    return total;
}

std::vector<std::shared_ptr<Request>> Company::getMostPopularRequests() const {
    std::map<std::string, int> count;
    for (const auto& req : requests) {
        auto key = req->getProperty()->getType() + " at " + req->getProperty()->getLocation();
        count[key]++;
    }

    int max = 0;
    for (const auto& p : count) {
        if (p.second > max) max = p.second;
    }

    std::vector<std::shared_ptr<Request>> result;
    for (const auto& req : requests) {
        auto key = req->getProperty()->getType() + " at " + req->getProperty()->getLocation();
        if (count[key] == max) {
            result.push_back(req);
        }
    }
    return result;
}
