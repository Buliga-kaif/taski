/**
 * @brief Абстрактный класс генератора значений.
 */

#pragma once

namespace miit::algebra
{
    /**
     * @brief Абстрактный класс для генерации значений.
     */
    class Generator
    {
    public:
        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Generator() = default;

        /**
         * @brief Виртуальный метод для генерации значения.
         * @return Сгенерированное значение.
         */
        virtual int generate() = 0;
    };
}
