#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Database.h"
#include "House.h"
#include "Apartment.h"
#include "Demand.h"
#include "Offer.h"

namespace Config {    
    const std::string DATA_FILENAME = "real_estate_data.txt";
    const double COMMISSION_PERCENT = 5.0;
    const std::string TYPE_HOUSE = "House";
    const std::string TYPE_APARTMENT = "Apartment";
    const std::string REQUEST_OFFER = "Offer";
    const std::string REQUEST_DEMAND = "Demand";
    const std::string MSG_WELCOME = "  Real Estate Management System ";
    const std::string MSG_SAVING = " Saving data...";
    const std::string MSG_GOODBYE = " Goodbye!";
    const std::string MSG_INVALID_INPUT = " Invalid input. Please enter a number.";
    const std::string MSG_INVALID_PROPERTY = " Invalid property type.";
    const std::string MSG_DEMAND_ADDED = "Demand added.\n";
    const std::string MSG_OFFER_ADDED = " Offer added.\n";
    const std::string MSG_PRICE_SWAP = " Min price > Max price. Swapping...\n";
}

namespace Menu {
    const int ADD_CLIENT = 1;
    const int ADD_DEMAND = 2;
    const int ADD_OFFER = 3;
    const int LIST_CLIENTS = 4;
    const int LIST_REQUESTS = 5;
    const int SHOW_OFFERS = 6;
    const int SHOW_DEMANDS = 7;
    const int SHOW_CLIENT = 8;
    const int FIND_EXACT = 9;
    const int FIND_BY_PRICE = 10;
    const int SHOW_PROFIT = 11;
    const int SHOW_POPULAR = 12;
    const int EXIT = 0;
}

int main() {
    Database db(Config::DATA_FILENAME, Config::COMMISSION_PERCENT);

    std::cout << Config::MSG_WELCOME << "\n";
    db.listClients();
    db.listRequests();
    std::cout << "\n";

    int choice;
    while (true) {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << " " << Menu::ADD_CLIENT << ". Add Client\n";
        std::cout << " " << Menu::ADD_DEMAND << ". Add Demand\n";
        std::cout << " " << Menu::ADD_OFFER << ". Add Offer\n";
        std::cout << " " << Menu::LIST_CLIENTS << ". List All Clients\n";
        std::cout << " " << Menu::LIST_REQUESTS << ". List All Requests\n";
        std::cout << " " << Menu::SHOW_OFFERS << ". Show Offers by Type\n";
        std::cout << " " << Menu::SHOW_DEMANDS << ". Show Demands by Type\n";
        std::cout << " " << Menu::SHOW_CLIENT << ". Show Client by Passport ID\n";
        std::cout << " " << Menu::FIND_EXACT << ". Find Request (exact match)\n";
        std::cout << " " << Menu::FIND_BY_PRICE << ".  Find Offers by Price Range\n";
        std::cout << " " << Menu::SHOW_PROFIT << ". Show Company Profit\n";
        std::cout << " " << Menu::SHOW_POPULAR << ". Show Most Popular Requests\n";
        std::cout << " " << Menu::EXIT << ". Exit (Save & Quit)\n";
        std::cout << "\nEnter your choice (0-12): ";

        if (!(std::cin >> choice)) {
            std::cout << Config::MSG_INVALID_INPUT << "\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case Menu::ADD_CLIENT: {
                std::string id, name;
                std::cout << "\n[Add Client]\n";
                std::cout << "Passport ID: "; std::cin >> id;
                std::cout << "Full Name: "; std::cin.ignore(); std::getline(std::cin, name);
                db.addClient(id, name);
                break;
            }

            case Menu::ADD_DEMAND:
            case Menu::ADD_OFFER: {
                const bool isDemand = (choice == Menu::ADD_DEMAND);
                std::cout << "\n[Add " << (isDemand ? "Demand" : "Offer") << "]\n";

                int typeChoice;
                std::cout << "Property Type:\n  1. House\n  2. Apartment\n→ ";
                std::cin >> typeChoice;

                if (typeChoice != 1 && typeChoice != 2) {
                    std::cout << Config::MSG_INVALID_PROPERTY << "\n";
                    break;
                }

                std::string location;
                double area, propPrice, reqPrice;

                std::cout << "Location: "; std::cin.ignore(); std::getline(std::cin, location);
                std::cout << "Area (m²): "; std::cin >> area;
                std::cout << "Property Price: "; std::cin >> propPrice;
                std::cout << "Request Price: "; std::cin >> reqPrice;

                std::shared_ptr<Property> prop;
                if (typeChoice == 1) {
                    prop = std::make_shared<House>(location, area, propPrice);
                } else {
                    prop = std::make_shared<Apartment>(location, area, propPrice);
                }

                if (isDemand) {
                    db.addRequest(std::make_shared<Demand>(prop, reqPrice));
                    std::cout << Config::MSG_DEMAND_ADDED;
                } else {
                    db.addRequest(std::make_shared<Offer>(prop, reqPrice));
                    std::cout << Config::MSG_OFFER_ADDED;
                }
                break;
            }

            case Menu::LIST_CLIENTS:
                std::cout << "\n[Clients]\n";
                db.listClients();
                break;

            case Menu::LIST_REQUESTS:
                std::cout << "\n[All Requests]\n";
                db.listRequests();
                break;

            case Menu::SHOW_OFFERS:
            case Menu::SHOW_DEMANDS: {
                const bool isOffer = (choice == Menu::SHOW_OFFERS);
                std::string type;
                std::cout << "\n[" << (isOffer ? "Offers" : "Demands") << "]\n";
                std::cout << "Property Type (House / Apartment): ";
                std::cin >> type;
                if (isOffer) {
                    db.showAllOffers(type);
                } else {
                    db.showAllDemands(type);
                }
                break;
            }

            case Menu::SHOW_CLIENT: {
                std::string id;
                std::cout << "\n[Client Lookup]\nPassport ID: ";
                std::cin >> id;
                db.showClientByPassport(id);
                break;
            }

            case Menu::FIND_EXACT: {
                double price, area;
                std::string loc;
                std::cout << "\n[Exact Match Search]\n";
                std::cout << "Price: "; std::cin >> price;
                std::cout << "Location: "; std::cin.ignore(); std::getline(std::cin, loc);
                std::cout << "Area: "; std::cin >> area;
                db.findRequestByParams(price, loc, area);
                break;
            }

            case Menu::FIND_BY_PRICE: {
                double minP, maxP;
                std::string type;
                std::cout << "\n[Price Range Search — Offers Only]\n";
                std::cout << "Min Price: "; std::cin >> minP;
                std::cout << "Max Price: "; std::cin >> maxP;
                if (minP > maxP) {
                    std::cout << Config::MSG_PRICE_SWAP;
                    std::swap(minP, maxP);
                }
                std::cout << "Property Type (House / Apartment / [Enter] for all): ";
                std::cin >> type;
                if (type == "-" || type == "all" || type.empty()) {
                    type = "";
                }
                db.findOffersByPriceRange(minP, maxP, type);
                break;
            }

            case Menu::SHOW_PROFIT:
                std::cout << "\n[Profit Summary]\n";
                db.showProfit();
                break;

            case Menu::SHOW_POPULAR:
                std::cout << "\n[Most Popular Requests]\n";
                db.showMostPopularRequests();
                break;

            case Menu::EXIT:
                std::cout << Config::MSG_SAVING << "\n";
                db.saveToFile();
                std::cout << Config::MSG_GOODBYE << "\n";
                return 0;

            default:
                std::cout << " Invalid choice. Please enter 0–12.\n";
                break;
        }
    }
}
