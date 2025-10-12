/**
 * @brief Реализация задания 1.
 */

#include "Task1Exercise.h"

miit::algebra::Task1Exercise::Task1Exercise(Matrix<int>& mat, Generator* g)
    : Exercise(mat, g)
{}
void miit::algebra::Task1Exercise::Task1()
{
    int max_negative = 0;
    bool found = false;
    for (size_t i = 0; i < matrix.getSize(); ++i) {
        if (matrix[i] < 0) {
            if (!found || matrix[i] > max_negative) {
                max_negative = matrix[i];
                found = true;
            }
        }
    }
    if (found && matrix.getSize() > 1) {
        matrix[1] = max_negative;
    }
}
