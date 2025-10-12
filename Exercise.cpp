/**
 * @brief Реализация класса Exercise.
 */

#include "Exercise.h"

miit::algebra::Exercise::Exercise(Matrix<int>& mat, Generator* g)
    : matrix(mat), gen(g)
{}
