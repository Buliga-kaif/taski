#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include "Property.h"
#include <memory>

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
