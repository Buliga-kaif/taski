#pragma once
#ifndef DEMAND_H
#define DEMAND_H

#include "Request.h"

/**
 * @brief Класс, представляющий спрос на недвижимость.
 *
 * Наследуется от Request.
 */
class Demand : public Request {
public:
    /**
     * @brief Конструктор спроса.
     * @param prop Объект недвижимости.
     * @param p Цена.
     */
    Demand(std::shared_ptr<Property> prop, double p);

    std::string getType() const override;
};

#endif
