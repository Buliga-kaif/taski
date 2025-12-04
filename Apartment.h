#pragma once
#ifndef APARTMENT_H
#define APARTMENT_H

#include "Property.h"
#include <string>

/**
 * @brief Класс, представляющий квартиру.
 *
 * Наследуется от Property и реализует его виртуальные методы.
 */
class Apartment : public Property {
private:
    std::string location; ///< Местоположение квартиры.
    double area;          ///< Площадь квартиры.
    double price;         ///< Цена квартиры.

public:
    /**
     * @brief Конструктор квартиры.
     * @param loc Местоположение.
     * @param a Площадь.
     * @param p Цена.
     */
    Apartment(const std::string& loc, double a, double p);

    std::string getLocation() const override;
    double getArea() const override;
    double getPrice() const override;
    std::string getType() const override;
};

#endif
