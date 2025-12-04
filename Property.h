#pragma once
#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

/**
 * @brief Абстрактный базовый класс, представляющий недвижимость.
 *
 * Определяет общий интерфейс для всех видов недвижимости,
 * таких как дома и квартиры.
 */
    class Property {
    public:
        virtual ~Property() = default;

        /**
         * @brief Возвращает местоположение недвижимости.
         * @return std::string местоположение.
         */
        virtual std::string getLocation() const = 0;

        /**
         * @brief Возвращает площадь недвижимости.
         * @return double площадь в квадратных метрах.
         */
        virtual double getArea() const = 0;

        /**
         * @brief Возвращает цену недвижимости.
         * @return double цена.
         */
        virtual double getPrice() const = 0;

        /**
         * @brief Возвращает тип недвижимости.
         * @return std::string тип ("House", "Apartment").
         */
        virtual std::string getType() const = 0;
};

#endif
