#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <string>

/**
 * @brief Класс, представляющий клиента.
 *
 * Содержит информацию о клиенте: паспорт и ФИО.
 */
class Client {
private:
    std::string passportId; ///< Номер паспорта.
    std::string fullName;   ///< Полное имя.

public:
    /**
     * @brief Конструктор клиента.
     * @param id Номер паспорта.
     * @param name Полное имя.
     */
    Client(const std::string& id, const std::string& name);

    /**
     * @brief Возвращает номер паспорта.
     * @return std::string номер паспорта.
     */
    std::string getPassportId() const;

    /**
     * @brief Возвращает полное имя.
     * @return std::string полное имя.
     */
    std::string getFullName() const;
};

#endif
