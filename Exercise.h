#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    class Exercise
    {
    protected:
        Matrix<int> matrix;
        Generator* gen;

    public:
        Exercise(Matrix<int>& mat, Generator* g);
        virtual ~Exercise() = default;
        virtual void Task() = 0;
    };
}
