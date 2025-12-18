#pragma once
#ifndef DEMAND_H
#define DEMAND_H

#include "Request.h"

/**
 * @brief Класс, представляющий спрос на недвижимость.
 *
 * Наследуется от Request и реализует виртуальные методы.
 */
class Demand : public Request {
public:
    /**
     * @brief Конструктор спроса.
     * @param prop Объект недвижимости.
     * @param p Цена, по которой клиент хочет купить.
     */
    using Request::Request;  

    RequestType getEnumType() const override {
        return RequestType::Demand;
    }

    std::string getType() const override {
        return "Demand";
    }
};

#endif 
