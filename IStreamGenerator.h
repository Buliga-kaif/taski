/**
 * @brief Класс генерации значений из потока.
 */

#pragma once
#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
    /**
     * @brief Реализация генератора значений из потока (например, stdin).
     */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in; ///< Входной поток.

    public:
        /**
         * @brief Конструктор.
         * @param in Входной поток (по умолчанию std::cin).
         */
        IStreamGenerator(std::istream& in = std::cin);

        /**
         * @brief Генерирует значение из потока.
         * @return Значение, прочитанное из потока.
         */
        int generate() override;
    };
}
