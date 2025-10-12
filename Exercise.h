/**
 * @brief Абстрактный класс для выполнения заданий.
 */

#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Абстрактный класс для выполнения заданий с матрицей и генератором.
     */
    class Exercise
    {
    protected:
        Matrix<int> matrix; 
        Generator* gen;     

    public:
        /**
         * @brief Конструктор.
         * @param mat Матрица.
         * @param g Генератор.
         */
        Exercise(Matrix<int>& mat, Generator* g);

        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Exercise() = default;

        /**
         * @brief Абстрактный метод задания 1.
         */
        virtual void Task1() = 0;

        /**
         * @brief Абстрактный метод задания 2.
         */
        virtual void Task2() = 0;
    };
}
