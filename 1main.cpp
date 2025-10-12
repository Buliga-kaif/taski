/**
 * @brief Точка входа в приложение.
 */
#include <iostream>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"

int main()
{
    using namespace miit::algebra;

    size_t n;
    std::cout << "Enter array size: ";
    std::cin >> n;

    Matrix<int> mat(n);

    std::cout << "Choose fill method:\n";
    std::cout << "1 - Enter manually\n";
    std::cout << "2 - Fill with random numbers\n";
    std::cout << "Your choice: ";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        IStreamGenerator gen;
        std::cout << "Enter " << n << " numbers:\n";
        for (size_t i = 0; i < n; ++i) {
            mat[i] = gen.generate();
        }
    }
    else {
        RandomGenerator gen(-10, 10);
        for (size_t i = 0; i < n; ++i) {
            mat[i] = gen.generate();
        }
    }

    std::cout << "Original array: " << mat.toString() << std::endl;

    // Task 1
    Task1Exercise t1(mat, new RandomGenerator(-10, 10));
    t1.Task1();
    std::cout << "After task 1: " << mat.toString() << std::endl;

    // Task 2
    int k;
    std::cout << "Enter K for task 2: ";
    std::cin >> k;
    Task2Exercise t2(mat, new RandomGenerator(-10, 10), k);
    t2.Task2();
    std::cout << "After task 2: " << mat.toString() << std::endl;

    return 0;
}
