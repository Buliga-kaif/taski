#pragma once
#ifndef OFFER_H
#define OFFER_H

#include "Request.h"

/**
 * @brief Класс, представляющий предложение недвижимости.
 *
 * Наследуется от Request и реализует виртуальные методы.
 */
class Offer : public Request {
public:
    /**
     * @brief Конструктор предложения.
     * @param prop Объект недвижимости.
     * @param p Цена, по которой владелец хочет продать.
     */
    using Request::Request;  

    RequestType getEnumType() const override {
        return RequestType::Offer;
    }

    std::string getType() const override {
        return "Offer";
    }
};

#endif 
