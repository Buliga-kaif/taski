#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include "Property.h"
#include <string>

/**
 * @brief Класс, представляющий дом.
 *
 * Наследуется от Property и реализует его виртуальные методы.
 */
class House : public Property {
private:
    std::string location; ///< Местоположение дома.
    double area;          ///< Площадь дома.
    double price;         ///< Цена дома.

public:
    /**
     * @brief Конструктор дома.
     * @param loc Местоположение.
     * @param a Площадь.
     * @param p Цена.
     */
    House(const std::string& loc, double a, double p);

    std::string getLocation() const override;
    double getArea() const override;
    double getPrice() const override;
    std::string getType() const override;
};

#endif
