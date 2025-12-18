#include "Exercise.h"

miit::algebra::Exercise::Exercise(Matrix<int>& mat, Generator* g)
    : matrix(mat), gen(g)
{}

miit::algebra::Exercise::~Exercise()
{
    if (gen != nullptr) {
        delete gen;
        gen = nullptr;
    }
}
