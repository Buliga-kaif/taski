/**
 * @brief Реализация задания 2.
 */

#include "Task2Exercise.h"
#include <vector>
#include <string>
#include <algorithm>

miit::algebra::Task2Exercise::Task2Exercise(Matrix<int>& mat, Generator* g, int K)
    : Exercise(mat, g), k(K)
{}

void miit::algebra::Task2Exercise::Task2()
{
    std::vector<int> result;
    for (size_t i = 0; i < matrix.getSize(); ++i) {
        int val = matrix[i];
        std::string s = std::to_string(std::abs(val));
        if (s.find('1') != std::string::npos) {
            result.push_back(k);
        }
        result.push_back(val);
    }

    // Пересоздаём матрицу
    Matrix<int> newMat(result.size());
    for (size_t i = 0; i < result.size(); ++i) {
        newMat[i] = result[i];
    }
    matrix = newMat;
}
