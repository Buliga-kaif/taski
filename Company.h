#pragma once
#ifndef COMPANY_H
#define COMPANY_H

#include "Client.h"
#include "Request.h"
#include <vector>
#include <memory>
#include <map>
#include <string>

/**
 * @brief Класс, представляющий компанию по продаже недвижимости.
 *
 * Управляет клиентами, спросом и предложением, а также вычисляет прибыль.
 */
class Company {
private:
    std::vector<std::shared_ptr<Client>> clients;        ///< Список клиентов.
    std::vector<std::shared_ptr<Request>> requests;      ///< Список запросов (спрос и предложение).
    double commissionPercent;                             ///< Процент комиссии.

public:
    /**
     * @brief Конструктор компании.
     * @param commission Процент комиссии.
     */
    Company(double commission);

    /**
     * @brief Добавляет клиента в список.
     * @param client Указатель на клиента.
     */
    void addClient(std::shared_ptr<Client> client);

    /**
     * @brief Добавляет запрос в список.
     * @param request Указатель на запрос.
     */
    void addRequest(std::shared_ptr<Request> request);

    /**
     * @brief Выводит все предложения для указанного типа недвижимости.
     * @param type Тип недвижимости ("House", "Apartment").
     */
    void showAllOffers(const std::string& type) const;

    /**
     * @brief Выводит все спросы для указанного типа недвижимости.
     * @param type Тип недвижимости ("House", "Apartment").
     */
    void showAllDemands(const std::string& type) const;

    /**
     * @brief Выводит информацию о клиенте по номеру паспорта.
     * @param passportId Номер паспорта.
     */
    void showClientByPassport(const std::string& passportId) const;

    /**
     * @brief Находит запросы по цене, локации и площади.
     * @param price Цена.
     * @param location Локация.
     * @param area Площадь.
     * @return Вектор найденных запросов.
     */
    std::vector<std::shared_ptr<Request>> findRequests(double price, const std::string& location, double area) const;

    /**
     * @brief Вычисляет прибыль компании с предложений.
     * @return double Прибыль.
     */
    double calculateProfit() const;

    /**
     * @brief Возвращает список самых популярных запросов.
     * @return Вектор самых популярных запросов.
     */
    std::vector<std::shared_ptr<Request>> getMostPopularRequests() const;
};

#endif
