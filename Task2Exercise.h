/**
 * @brief Реализация задания 2: вставить K перед элементами с цифрой 1.
 */

#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Реализация задания 2.
     */
    class Task2Exercise : public Exercise
    {
    private:
        int k; ///< Значение для вставки.

    public:
        /**
         * @brief Конструктор.
         * @param mat Матрица.
         * @param g Генератор.
         * @param K Значение для вставки.
         */
        Task2Exercise(Matrix<int>& mat, Generator* g, int K);

        /**
         * @brief Выполняет задание 2.
         */
        void Task2() override;

        void Task1() override {}
    };
}
