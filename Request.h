#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include "Property.h"
#include <memory>

enum class RequestType {
    Demand,
    Offer
};


class Request {
protected:
    std::shared_ptr<Property> property;
    double price;

public:
    Request(std::shared_ptr<Property> prop, double p) : property(prop), price(p) {}
    virtual ~Request() = default;

    virtual RequestType getEnumType() const = 0; /
    virtual std::string getType() const = 0;

    std::shared_ptr<Property> getProperty() const { return property; }
    double getPrice() const { return price; }
};

/**
 * @brief Абстрактный базовый класс для запросов (спрос и предложение).
 *
 * Содержит ссылку на недвижимость и цену.
 */
class Request {
protected:
    std::shared_ptr<Property> property; ///< Объект недвижимости, связанный с запросом.
    double price;                       ///< Цена запроса.

public:
    /**
     * @brief Конструктор запроса.
     * @param prop Объект недвижимости.
     * @param p Цена.
     */
    Request(std::shared_ptr<Property> prop, double p);

    virtual ~Request() = default;

    /**
     * @brief Возвращает тип запроса ("Demand" или "Offer").
     * @return std::string тип запроса.
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Возвращает связанную недвижимость.
     * @return std::shared_ptr<Property>.
     */
    std::shared_ptr<Property> getProperty() const;

    /**
     * @brief Возвращает цену запроса.
     * @return double цена.
     */
    double getPrice() const;
};

#endif
