#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include "Client.h"
#include "Request.h"
#include "Company.h"
#include <vector>
#include <memory>
#include <string>

/**
 * @brief Класс для управления базой данных клиентов, спроса и предложения.
 *
 * Обеспечивает интерфейс для добавления, поиска и просмотра информации.
 */
class Database {
private:
    std::vector<std::shared_ptr<Client>> clients;        ///< Список клиентов.
    std::vector<std::shared_ptr<Request>> requests;      ///< Список спроса и предложения.
    std::unique_ptr<Company> company;                    ///< Объект компании.
    std::string filename;                                ///< Имя файла для сохранения данных.

public:
    /**
     * @brief Конструктор базы данных.
     * @param file Имя файла для сохранения/загрузки данных.
     * @param commission Комиссия компании.
     */
    Database(const std::string& file, double commission);

    /**
     * @brief Добавляет клиента в базу.
     * @param id Номер паспорта.
     * @param name Имя клиента.
     */
    void addClient(const std::string& id, const std::string& name);

    /**
     * @brief Добавляет запрос (спрос или предложение).
     * @param request Указатель на объект Request.
     */
    void addRequest(std::shared_ptr<Request> request);

    /**
     * @brief Выводит все предложения для указанного типа недвижимости.
     * @param type Тип недвижимости ("House", "Apartment").
     */
    void showAllOffers(const std::string& type) const;

    /**
     * @brief Выводит весь спрос для указанного типа недвижимости.
     * @param type Тип недвижимости ("House", "Apartment").
     */
    void showAllDemands(const std::string& type) const;

    /**
     * @brief Выводит информацию о клиенте по номеру паспорта.
     * @param passportId Номер паспорта.
     */
    void showClientByPassport(const std::string& passportId) const;

    /**
     * @brief Находит спрос или предложение по цене, локации и площади.
     * @param price Цена.
     * @param location Локация.
     * @param area Площадь.
     */
    void findRequestByParams(double price, const std::string& location, double area) const;

    /**
     * @brief Выводит прибыль компании.
     */
    void showProfit() const;

    /**
     * @brief Выводит список самых популярных спросов/предложений.
     */
    void showMostPopularRequests() const;

    /**
     * @brief Сохраняет данные в файл.
     */
    void saveToFile() const;

    /**
     * @brief Загружает данные из файла.
     */
    void loadFromFile();

    /**
     * @brief Выводит список всех клиентов.
     */
    void listClients() const;

    /**
     * @brief Выводит список всех запросов.
     */
    void listRequests() const;
};

#endif
