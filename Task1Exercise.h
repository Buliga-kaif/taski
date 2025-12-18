/**
 * @brief Реализация задания 1: заменить второй элемент на макс. отрицательный.
 */

#pragma once
#include "Matrix.h" 

namespace miit::algebra
{
    /**
     * @brief Реализация задания 1.
     */
    class Task1Exercise
    {
    public:
        /**
         * @brief Конструктор.
         * @param mat Массив, в котором нужно выполнить задачу.
         */
        explicit Task1Exercise(Matrix<int>& mat);

        /**
         * @brief Выполняет задание 1.
         */
        void Task();

    private:
        Matrix<int>& matrix; 
    };
}
