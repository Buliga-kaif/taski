/**
 * @brief Реализация задания 3: сформировать новый массив по правилу чет/нечет.
 */

#pragma once
#include "Matrix.h" 

namespace miit::algebra
{
    /**
     * @brief Реализация задания 3.
     */
    class Task3Exercise
    {
    public:
        /**
         * @brief Конструктор.
         * @param mat Исходный массив D.
         */
        explicit Task3Exercise(const Matrix<int>& mat);

        /**
         * @brief Выполняет задание 3.
         * @return Новый массив A, сформированный по правилу.
         */
        Matrix<int> Task();

    private:
        const Matrix<int>& matrix; 
    };
}
