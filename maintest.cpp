#include <iostream>
#include "Company.h"
#include "House.h"
#include "Apartment.h"
#include "Client.h"
#include "Demand.h"
#include "Offer.h"

int main() {
    // Тестирование основной логики
    auto company = std::make_shared<Company>(5.0);

    auto house = std::make_shared<House>("Test City", 100.0, 200000.0);
    auto offer = std::make_shared<Offer>(house, 200000.0);
    company->addRequest(offer);

    double profit = company->calculateProfit();
    std::cout << "Expected profit: 10000, Actual: " << profit << "\n";
    if (profit == 10000.0) {
        std::cout << "Test passed.\n";
    } else {
        std::cout << "Test failed.\n";
    }

    return 0;
}
