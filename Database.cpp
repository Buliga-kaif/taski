#include "Database.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "House.h"
#include "Demand.h"
#include "Apartment.h"
#include "Offer.h"

Database::Database(const std::string& file, double commission)
    : filename(file), company(std::make_unique<Company>(commission)) {
    loadFromFile();
}

void Database::addClient(const std::string& id, const std::string& name) {
    auto client = std::make_shared<Client>(id, name);
    clients.push_back(client);
    company->addClient(client);
    std::cout << "Client added: " << name << " with ID: " << id << "\n";
}

void Database::addRequest(std::shared_ptr<Request> request) {
    requests.push_back(request);
    company->addRequest(request);
    std::cout << "Request added: " << request->getType() << " for " << request->getProperty()->getType() << "\n";
}

void Database::showAllOffers(const std::string& type) const {
    company->showAllOffers(type);
}

void Database::showAllDemands(const std::string& type) const {
    company->showAllDemands(type);
}

void Database::showClientByPassport(const std::string& passportId) const {
    company->showClientByPassport(passportId);
}

void Database::findRequestByParams(double price, const std::string& location, double area) const {
    auto results = company->findRequests(price, location, area);
    if (results.empty()) {
        std::cout << "No matching requests found.\n";
    }
    else {
        std::cout << "Found matching requests:\n";
        for (const auto& req : results) {
            std::cout << req->getType() << " for " << req->getProperty()->getType() << " at " << req->getProperty()->getLocation()
                << ", Price: " << req->getPrice() << "\n";
        }
    }
}

void Database::showProfit() const {
    std::cout << "Company Profit: " << company->calculateProfit() << "\n";
}

void Database::showMostPopularRequests() const {
    auto popular = company->getMostPopularRequests();
    if (popular.empty()) {
        std::cout << "No requests available.\n";
        return;
    }
    std::cout << "Most Popular Requests:\n";
    for (const auto& req : popular) {
        std::cout << req->getType() << " for " << req->getProperty()->getType() << " at " << req->getProperty()->getLocation() << "\n";
    }
}

void Database::saveToFile() const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file for writing!\n";
        return;
    }

    file << "=== Clients ===\n";
    for (const auto& c : clients) {
        file << c->getPassportId() << "," << c->getFullName() << "\n";
    }

    file << "=== Requests ===\n";
    for (const auto& r : requests) {
        file << r->getType() << ","
            << r->getProperty()->getType() << ","
            << r->getProperty()->getLocation() << ","
            << r->getProperty()->getArea() << ","
            << r->getProperty()->getPrice() << ","
            << r->getPrice() << "\n";
    }

    file.close();
    std::cout << "Data saved to " << filename << "\n";
}

void Database::loadFromFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "No existing data file found. Starting fresh.\n";
        return;
    }

    std::string line;
    bool readingRequests = false;

    while (getline(file, line)) {
        if (line == "=== Requests ===") {
            readingRequests = true;
            continue;
        }

        if (line.empty() || line[0] == '=') continue;

        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        if (!readingRequests && tokens.size() >= 2) {
            addClient(tokens[0], tokens[1]);
        }
        else if (readingRequests && tokens.size() >= 6) {
            std::string type = tokens[0];
            std::string propType = tokens[1];
            std::string location = tokens[2];
            double area = std::stod(tokens[3]);
            double propPrice = std::stod(tokens[4]);
            double reqPrice = std::stod(tokens[5]);

            std::shared_ptr<Property> prop;
            if (propType == "House") {
                prop = std::make_shared<House>(location, area, propPrice);
            }
            else if (propType == "Apartment") {
                prop = std::make_shared<Apartment>(location, area, propPrice);
            }

            std::shared_ptr<Request> req;
            if (type == "Demand") {
                req = std::make_shared<Demand>(prop, reqPrice);
            }
            else if (type == "Offer") {
                req = std::make_shared<Offer>(prop, reqPrice);
            }

            if (req) {
                addRequest(req);
            }
        }
    }

    file.close();
    std::cout << "Data loaded from " << filename << "\n";
}

void Database::listClients() const {
    std::cout << "\n--- Clients ---\n";
    for (const auto& c : clients) {
        std::cout << "ID: " << c->getPassportId() << ", Name: " << c->getFullName() << "\n";
    }
}

void Database::listRequests() const {
    std::cout << "\n--- Requests ---\n";
    for (const auto& r : requests) {
        std::cout << r->getType() << " for " << r->getProperty()->getType() << " at " << r->getProperty()->getLocation()
            << ", Price: " << r->getPrice() << "\n";
    }
}
