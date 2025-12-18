/**
 * @brief Класс генерации значений из константы.
 */

#pragma once
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Реализация генератора значений из константы.
     */
    class ConstantGenerator : public Generator
    {
    private:
        int value; ///< Константное значение.

    public:
        /**
         * @brief Конструктор.
         * @param val Константное значение.
         */
        explicit ConstantGenerator(int val);

        /**
         * @brief Генерирует значение.
         * @return Константное значение.
         */
        int generate() override;
    };
}
