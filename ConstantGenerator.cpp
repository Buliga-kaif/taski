/**
 * @brief Реализация класса ConstantGenerator.
 */

#include "ConstantGenerator.h"

miit::algebra::ConstantGenerator::ConstantGenerator(int val) : value(val)
{}

int miit::algebra::ConstantGenerator::generate()
{
    return value;
