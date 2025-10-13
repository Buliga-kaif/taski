/**
 * @brief Класс генерации случайных чисел.
 */

#pragma once
#include "Generator.h"
#include <random>

namespace miit::algebra
{
    /**
     * @brief Реализация генератора случайных чисел.
     */
    class RandomGenerator : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution; ///< Распределение для генерации.
        std::mt19937 generator; ///< Генератор случайных чисел.

    public:
        /**
         * @brief Конструктор.
         * @param min Минимальное значение.
         * @param max Максимальное значение.
         */
        RandomGenerator(const int min, const int max);

        /**
         * @brief Генерирует случайное число.
         * @return Случайное число в диапазоне [min, max].
         */
        int generate() override;
    };
}
