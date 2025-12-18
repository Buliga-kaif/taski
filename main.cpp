#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Database.h"
#include "House.h"
#include "Apartment.h"
#include "Demand.h"
#include "Offer.h"

int main() {
    Database db("real_estate_data.txt", 5.0);
    std::cout << "  Real Estate Management System (v2.0)   \n";
    db.listClients();
    db.listRequests();
    std::cout << "\n";

    int choice;
    while (true) {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << " 1. Add Client\n";
        std::cout << " 2. Add Demand\n";
        std::cout << " 3. Add Offer\n";
        std::cout << " 4. List All Clients\n";
        std::cout << " 5. List All Requests\n";
        std::cout << " 6. Show Offers by Type\n";
        std::cout << " 7. Show Demands by Type\n";
        std::cout << " 8. Show Client by Passport ID\n";
        std::cout << " 9. Find Request (exact match)\n";
        std::cout << "10. 🔍 Find Offers by Price Range\n";  
        std::cout << "11. Show Company Profit\n";
        std::cout << "12. Show Most Popular Requests\n";
        std::cout << " 0. Exit (Save & Quit)\n";
        std::cout << "\nEnter your choice (0-12): ";
        
        if (!(std::cin >> choice)) {
            std::cout << " Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: { 
                std::string id, name;
                std::cout << "\n[Add Client]\n";
                std::cout << "Passport ID: "; std::cin >> id;
                std::cout << "Full Name: "; std::cin.ignore(); std::getline(std::cin, name);
                db.addClient(id, name);
                break;
            }

            case 2: 
            case 3: { 
                std::cout << "\n[Add " << (choice == 2 ? "Demand" : "Offer") << "]\n";
                int typeChoice;
                std::cout << "Property Type:\n  1. House\n  2. Apartment\n→ ";
                std::cin >> typeChoice;

                if (typeChoice != 1 && typeChoice != 2) {
                    std::cout << " Invalid property type.\n";
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

                if (choice == 2) {
                    db.addRequest(std::make_shared<Demand>(prop, reqPrice));
                    std::cout << "Demand added.\n";
                } else {
                    db.addRequest(std::make_shared<Offer>(prop, reqPrice));
                    std::cout << " Offer added.\n";
                }
                break;
            }

            case 4: 
                std::cout << "\n[Clients]\n";
                db.listClients();
                break;

            case 5: 
                std::cout << "\n[All Requests]\n";
                db.listRequests();
                break;

            case 6: 
            case 7: { 
                std::string type;
                std::cout << "\n[" << (choice == 6 ? "Offers" : "Demands") << "]\n";
                std::cout << "Property Type (House / Apartment): ";
                std::cin >> type;
                if (choice == 6) {
                    db.showAllOffers(type);
                } else {
                    db.showAllDemands(type);
                }
                break;
            }

            case 8: { 
                std::string id;
                std::cout << "\n[Client Lookup]\nPassport ID: ";
                std::cin >> id;
                db.showClientByPassport(id);
                break;
            }

            case 9: { 
                double price, area;
                std::string loc;
                std::cout << "\n[Exact Match Search]\n";
                std::cout << "Price: "; std::cin >> price;
                std::cout << "Location: "; std::cin.ignore(); std::getline(std::cin, loc);
                std::cout << "Area: "; std::cin >> area;
                db.findRequestByParams(price, loc, area);
                break;
            }

            case 10: {
                double minP, maxP;
                std::string type;
                std::cout << "\n[Price Range Search — Offers Only]\n";
                std::cout << "Min Price: "; std::cin >> minP;
                std::cout << "Max Price: "; std::cin >> maxP;
                if (minP > maxP) {
                    std::cout << " Min price > Max price. Swapping...\n";
                    std::swap(minP, maxP);
                }
                std::cout << "Property Type (House / Apartment / [Enter] for all): ";
                std::cin >> type;
                if (type == "-" || type == "all" || type.empty()) type = "";
                db.findOffersByPriceRange(minP, maxP, type);
                break;
            }

            case 11: 
                std::cout << "\n[Profit Summary]\n";
                db.showProfit();
                break;

            case 12: 
                std::cout << "\n[Most Popular Requests]\n";
                db.showMostPopularRequests();
                break;

            case 0: // Exit
                std::cout << "\n Saving data...\n";
                db.saveToFile();
                std::cout << " Goodbye!\n";
                return 0;

            default:
                std::cout << " Invalid choice. Please enter 0–12.\n";
                break;
        }
    }
}
