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
        Task1Exercise(Matrix<int>& mat, Generator* g);
        void Task() override;
    };
}
