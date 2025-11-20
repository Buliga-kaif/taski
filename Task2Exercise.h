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
        Task2Exercise(Matrix<int>& mat, Generator* g, int K);
        void Task() override;
    };
}
