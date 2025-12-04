#pragma once
#ifndef OFFER_H
#define OFFER_H

#include "Request.h"

/**
 * @brief Класс, представляющий предложение недвижимости.
 *
 * Наследуется от Request.
 */
class Offer : public Request {
public:
    /**
     * @brief Конструктор предложения.
     * @param prop Объект недвижимости.
     * @param p Цена.
     */
    Offer(std::shared_ptr<Property> prop, double p);

    std::string getType() const override;
};

#endif
