 #include <iostream>
#include <string>
#include "Database.h"
#include "Offer.h"
#include "Demand.h"
#include "House.h"
#include "Apartment.h"

int main() {
    Database db("real_estate_data.txt", 5.0); // 5% commission

  
    std::cout << "       Welcome to Real Estate Management DB      \n";
    std::cout << " Loading Data from File...\n";
    std::cout << "\n List of All Clients:\n";
    db.listClients();

    std::cout << "\n List of All Requests (Demands & Offers):\n";
    db.listRequests();

    std::cout << "\n" << std::string(60, '-') << "\n\n";



    std::cout << "Available Commands:\n";
    std::cout << "  add_client       Add a new client\n";
    std::cout << "  add_demand       Add a new demand\n";
    std::cout << "  add_offer        Add a new offer\n";
    std::cout << "  list_clients     Show all clients\n";
    std::cout << "  list_requests    Show all demands and offers\n";
    std::cout << "  show_offers      Show all offers for a property type\n";
    std::cout << "  show_demands     Show all demands for a property type\n";
    std::cout << "  show_client      Show client info by passport ID\n";
    std::cout << "  find_request     Find request by price, location, area\n";
    std::cout << "  show_profit      Show company's profit\n";
    std::cout << "  show_popular     Show most popular requests\n";
    std::cout << "  help             Show this message\n";
    std::cout << "  exit             Save and exit\n\n";

    std::string command;

    while (true) {
        std::cout << " Enter Command \n";
  
        std::cin >> command;

        if (command == "help") {
            std::cout << "\n Available Commands:\n";
            std::cout << "  add_client      — Add a new client\n";
            std::cout << "  add_demand      — Add a new demand\n";
            std::cout << "  add_offer       — Add a new offer\n";
            std::cout << "  list_clients    — Show all clients\n";
            std::cout << "  list_requests   — Show all demands and offers\n";
            std::cout << "  show_offers     — Show all offers for a property type\n";
            std::cout << "  show_demands    — Show all demands for a property type\n";
            std::cout << "  show_client     — Show client info by passport ID\n";
            std::cout << "  find_request    — Find request by price, location, area\n";
            std::cout << "  show_profit     — Show company's profit\n";
            std::cout << "  show_popular    — Show most popular requests\n";
            std::cout << "  help            — Show this message\n";
            std::cout << "  exit            — Save and exit\n\n";
        }
        else if (command == "add_client") {
            std::string id, name;
            std::cout << "\n Adding New Client...\n";
            std::cout << "  Enter Passport ID: ";
            std::cin >> id;
            std::cout << "  Enter Full Name: ";
            std::cin.ignore();
            getline(std::cin, name);
            db.addClient(id, name);
            std::cout << " Client successfully added!\n\n";
        }
        else if (command == "add_demand") {
            std::string propType, location;
            double area, propPrice, reqPrice;
            std::cout << "\n Adding New Demand...\n";
            std::cout << "  Enter Property Type (House/Apartment): ";
            std::cin >> propType;
            std::cout << "  Enter Location: ";
            std::cin.ignore();
            getline(std::cin, location);
            std::cout << "  Enter Property Area: ";
            std::cin >> area;
            std::cout << "  Enter Property Price: ";
            std::cin >> propPrice;
            std::cout << "  Enter Request Price: ";
            std::cin >> reqPrice;

            std::shared_ptr<Property> prop;
            if (propType == "House") {
                prop = std::make_shared<House>(location, area, propPrice);
            }
            else if (propType == "Apartment") {
                prop = std::make_shared<Apartment>(location, area, propPrice);
            }
            else {
                std::cout << " Invalid property type. Skipping.\n\n";
                continue;
            }

            auto demand = std::make_shared<Demand>(prop, reqPrice);
            db.addRequest(demand);
            std::cout << " Demand successfully added!\n\n";
        }
        else if (command == "add_offer") {
            std::string propType, location;
            double area, propPrice, reqPrice;
            std::cout << "\n Adding New Offer...\n";
            std::cout << "  Enter Property Type (House/Apartment): ";
            std::cin >> propType;
            std::cout << "  Enter Location: ";
            std::cin.ignore();
            getline(std::cin, location);
            std::cout << "  Enter Property Area: ";
            std::cin >> area;
            std::cout << "  Enter Property Price: ";
            std::cin >> propPrice;
            std::cout << "  Enter Request Price: ";
            std::cin >> reqPrice;

            std::shared_ptr<Property> prop;
            if (propType == "House") {
                prop = std::make_shared<House>(location, area, propPrice);
            }
            else if (propType == "Apartment") {
                prop = std::make_shared<Apartment>(location, area, propPrice);
            }
            else {
                std::cout << " Invalid property type. Skipping.\n\n";
                continue;
            }

            auto offer = std::make_shared<Offer>(prop, reqPrice);
            db.addRequest(offer);
            std::cout << " Offer successfully added!\n\n";
        }
        else if (command == "list_clients") {
            std::cout << "\n List of All Clients:\n";
            db.listClients();
            std::cout << "\n";
        }
        else if (command == "list_requests") {
            std::cout << "\n List of All Requests (Demands & Offers):\n";
            db.listRequests();
            std::cout << "\n";
        }
        else if (command == "show_offers") {
            std::string type;
            std::cout << "\n Enter Property Type (House/Apartment): ";
            std::cin >> type;
            std::cout << "\n All Offers for '" << type << "':\n";
            db.showAllOffers(type);
            std::cout << "\n";
        }
        else if (command == "show_demands") {
            std::string type;
            std::cout << "\n Enter Property Type (House/Apartment): ";
            std::cin >> type;
            std::cout << "\n All Demands for '" << type << "':\n";
            db.showAllDemands(type);
            std::cout << "\n";
        }
        else if (command == "show_client") {
            std::string id;
            std::cout << "\n Enter Passport ID: ";
            std::cin >> id;
            std::cout << "\n Client Info:\n";
            db.showClientByPassport(id);
            std::cout << "\n";
        }
        else if (command == "find_request") {
            double price, area;
            std::string location;
            std::cout << "\n Searching for Request...\n";
            std::cout << "  Enter Price: ";
            std::cin >> price;
            std::cout << "  Enter Location: ";
            std::cin.ignore();
            getline(std::cin, location);
            std::cout << "  Enter Area: ";
            std::cin >> area;
            std::cout << "\n Results:\n";
            db.findRequestByParams(price, location, area);
            std::cout << "\n";
        }
        else if (command == "show_profit") {
            std::cout << "\n Company Profit Summary:\n";
            db.showProfit();
            std::cout << "\n";
        }
        else if (command == "show_popular") {
            std::cout << "\n Most Popular Requests:\n";
            db.showMostPopularRequests();
            std::cout << "\n";
        }
        else if (command == "exit") {
            std::cout << "\n Saving database...";
            db.saveToFile();
            std::cout << "\n Goodbye!\n";
            break;
        }
        else {
            std::cout << "\n Unknown command. Type 'help' for available commands.\n\n";
        }
    }

    return 0;
}
