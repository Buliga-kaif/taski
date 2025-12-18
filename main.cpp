// main.cpp (сокращённая ключевая часть — цикл)
int main() {
    Database db("real_estate_data.txt", 5.0);
    // ... инициализация, вывод welcome и т.д.

    enum class Command {
        Help, AddClient, AddDemand, AddOffer,
        ListClients, ListRequests, ShowOffers, ShowDemands,
        ShowClient, FindRequest, ShowProfit, ShowPopular, Exit, Unknown
    };

    auto parseCommand = [](const std::string& cmd) -> Command {
        if (cmd == "help") return Command::Help;
        if (cmd == "add_client") return Command::AddClient;
        if (cmd == "add_demand") return Command::AddDemand;
        if (cmd == "add_offer") return Command::AddOffer;
        if (cmd == "list_clients") return Command::ListClients;
        if (cmd == "list_requests") return Command::ListRequests;
        if (cmd == "show_offers") return Command::ShowOffers;
        if (cmd == "show_demands") return Command::ShowDemands;
        if (cmd == "show_client") return Command::ShowClient;
        if (cmd == "find_request") return Command::FindRequest;
        if (cmd == "show_profit") return Command::ShowProfit;
        if (cmd == "show_popular") return Command::ShowPopular;
        if (cmd == "exit") return Command::Exit;
        return Command::Unknown;
    };

    std::string input;
    while (true) {
        std::cout << "\nEnter command: ";
        std::cin >> input;
        Command cmd = parseCommand(input);

        switch (cmd) {
            case Command::Help:
                std::cout << "Available commands: help, add_client, ...\n";
                break;

            case Command::AddClient: {
                std::string id, name;
                std::cout << "Passport ID: "; std::cin >> id;
                std::cout << "Full Name: "; std::cin.ignore(); getline(std::cin, name);
                db.addClient(id, name);
                break;
            }

            case Command::AddDemand:
            case Command::AddOffer: {
                std::string loc;
                double area, propPrice, reqPrice;
                int typeChoice;

                std::cout << "Property type:\n  1. House\n  2. Apartment\nChoice: ";
                std::cin >> typeChoice;

                std::shared_ptr<Property> prop;
                switch (typeChoice) {
                    case 1: {
                        std::cout << "Location: "; std::cin.ignore(); getline(std::cin, loc);
                        std::cout << "Area: "; std::cin >> area;
                        std::cout << "Property Price: "; std::cin >> propPrice;
                        prop = std::make_shared<House>(loc, area, propPrice);
                        break;
                    }
                    case 2: {
                        std::cout << "Location: "; std::cin.ignore(); getline(std::cin, loc);
                        std::cout << "Area: "; std::cin >> area;
                        std::cout << "Property Price: "; std::cin >> propPrice;
                        prop = std::make_shared<Apartment>(loc, area, propPrice);
                        break;
                    }
                    default:
                        std::cout << "Invalid type.\n";
                        continue;
                }

                std::cout << "Request Price: ";
                std::cin >> reqPrice;

                if (cmd == Command::AddDemand) {
                    db.addRequest(std::make_shared<Demand>(prop, reqPrice));
                    std::cout << "Demand added.\n";
                } else {
                    db.addRequest(std::make_shared<Offer>(prop, reqPrice));
                    std::cout << "Offer added.\n";
                }
                break;
            }

            case Command::ListClients:
                db.listClients(); break;

            case Command::ListRequests:
                db.listRequests(); break;

            case Command::ShowOffers:
            case Command::ShowDemands: {
                int typeChoice;
                std::cout << "1. House\n2. Apartment\nChoice: ";
                std::cin >> typeChoice;

                std::string typeStr;
                switch (typeChoice) {
                    case 1: typeStr = "House"; break;
                    case 2: typeStr = "Apartment"; break;
                    default: std::cout << "Invalid.\n"; continue;
                }

                if (cmd == Command::ShowOffers)
                    db.showAllOffers(typeStr);
                else
                    db.showAllDemands(typeStr);
                break;
            }

            case Command::ShowClient: {
                std::string id;
                std::cout << "Passport ID: "; std::cin >> id;
                db.showClientByPassport(id);
                break;
            }

            case Command::FindRequest: {
                double price, area;
                std::string loc;
                std::cout << "Price: "; std::cin >> price;
                std::cout << "Location: "; std::cin.ignore(); getline(std::cin, loc);
                std::cout << "Area: "; std::cin >> area;
                db.findRequestByParams(price, loc, area);
                break;
            }

            case Command::ShowProfit:
                db.showProfit(); break;

            case Command::ShowPopular:
                db.showMostPopularRequests(); break;

            case Command::Exit:
                db.saveToFile();
                std::cout << "Goodbye!\n";
                return 0;

            case Command::Unknown:
                std::cout << "Unknown command. Type 'help'.\n";
                break;
        }
    }
}
