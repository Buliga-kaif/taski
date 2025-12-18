/**
 * @brief Реализация задания 3.
 */

#include "Task3Exercise.h"

miit::algebra::Task3Exercise::Task3Exercise(const Matrix<int>& mat)
    : matrix(mat)
{}

miit::algebra::Matrix<int> miit::algebra::Task3Exercise::Task()
{
    size_t n = matrix.getSize();
    Matrix<int> result(n);
    for (size_t i = 0; i < n; ++i) {
        int d_i = matrix[i];
        if ((i + 1) % 2 == 0) { 
            result[i] = d_i * d_i; 
        } else { 
            if (i + 1 != 0) {
                result[i] = d_i / (i + 1); 
            }
  
        }
    }

    return result;
}
