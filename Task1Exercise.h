/**
* @brief Реализация задания 1: заменить второй элемент на макс. отрицательный.
 */

#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Реализация задания 1.
     */
    class Task1Exercise : public Exercise
    {
    public:
        /**
         * @brief Конструктор.
         * @param mat Матрица.
         * @param g Генератор.
         */
        Task1Exercise(Matrix<int>& mat, Generator* g);

        /**
         * @brief Выполняет задание 1.
         */
        void Task1() override;

        void Task2() override {}
    };
}
