include <iostream>
#include <vector>
#include <memory>
#include "Company.h"
#include "House.h"
#include "Apartment.h"
#include "Client.h"
#include "Demand.h"
#include "Offer.h"

/**
 * @brief Главная функция демонстрационной программы.
 *
 * Создаёт объекты, добавляет их в компанию, и тестирует функционал.
 */
int main() {
    // Создаём компанию с 5% комиссией
    auto company = std::make_shared<Company>(5.0);

    // Создаём объекты недвижимости
    auto house1 = std::make_shared<House>("Downtown", 150.0, 500000.0);
    auto apt1 = std::make_shared<Apartment>("Suburbs", 80.0, 300000.0);
    auto house2 = std::make_shared<House>("Uptown", 200.0, 700000.0);      // Offer на дом
    auto apt2 = std::make_shared<Apartment>("City Center", 90.0, 400000.0); // Demand на квартиру

    // Создаём клиентов
    auto client1 = std::make_shared<Client>("123456", "Ivan Ivanov");
    auto client2 = std::make_shared<Client>("654321", "Petr Petrov");

    // Добавляем клиентов
    company->addClient(client1);
    company->addClient(client2);

    // Создаём запросы
    auto demand1 = std::make_shared<Demand>(house1, 500000.0); // Demand на дом
    auto offer1 = std::make_shared<Offer>(apt1, 300000.0);     // Offer на квартиру
    auto offer2 = std::make_shared<Offer>(house2, 700000.0);   // Offer на дом
    auto demand2 = std::make_shared<Demand>(apt2, 400000.0);   // Demand на квартиру

    // Добавляем запросы в компанию
    company->addRequest(demand1);
    company->addRequest(offer1);
    company->addRequest(offer2);
    company->addRequest(demand2);

    // Демонстрация полиморфизма
    std::vector<std::shared_ptr<Request>> requests = { demand1, offer1, offer2, demand2 };
    for (const auto& req : requests) {
        std::cout << "Type: " << req->getType() << ", Property Type: " << req->getProperty()->getType()
            << ", Location: " << req->getProperty()->getLocation() << ", Price: " << req->getPrice() << "\n";
    }

    std::cout << "\nAll Offers for Houses:\n";
    company->showAllOffers("House");

    std::cout << "\nAll Demands for Apartments:\n";
    company->showAllDemands("Apartment");

    std::cout << "\nClient by Passport '123456':\n";
    company->showClientByPassport("123456");

    std::cout << "\nProfit: " << company->calculateProfit() << "\n";

    std::cout << "\nMost Popular Requests:\n";
    auto popular = company->getMostPopularRequests();
    for (const auto& req : popular) {
        std::cout << req->getType() << " for " << req->getProperty()->getType() << " at " << req->getProperty()->getLocation() << "\n";
    }

    return 0;
}
