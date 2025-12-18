
/**
 * @brief Точка входа в приложение.
 */
#include <iostream>
#include <limits>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Exercise.h"

enum  FillMethod {
    Manual = 1,
    Random = 2
};

bool safeInputInt(int& value) {
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool safeInputSize(size_t& value) {
    int temp_int = 0;
    if (!(std::cin >> temp_int) || temp_int < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    value = static_cast<size_t>(temp_int);
    return true;
}
#ifndef TEST_MODE
int main()
{
    using namespace miit::algebra;

    size_t n = 0;
    std::cout << "Enter array size: ";
    while (!safeInputSize(n)) {
        std::cout << "Invalid input. Please enter a non-negative integer: ";
    }

    if (n == 0) {
        std::cout << "Array size is 0. Creating empty array.\n";
    }
    Matrix<int> mat(n);

    std::cout << "Choose fill method:\n";
    std::cout << static_cast<int>(FillMethod::Manual) << " - Enter manually\n";
    std::cout << static_cast<int>(FillMethod::Random) << " - Fill with random numbers\n";
    std::cout << "Your choice: ";

    int choice = 0;
    while (!safeInputInt(choice) || (choice != static_cast<int>(FillMethod::Manual) && choice != static_cast<int>(FillMethod::Random))) {
        std::cout << "Invalid input. Please enter " << static_cast<int>(FillMethod::Manual) << " or " << static_cast<int>(FillMethod::Random) << ": ";
    }

    switch (static_cast<FillMethod>(choice)) {
    case FillMethod::Manual: {
        std::cout << "Enter " << n << " numbers:\n";
        for (size_t i = 0; i < n; ++i) {
            int temp_val = 0;
            std::cout << "Element " << i + 1 << ": ";
            while (!(std::cin >> temp_val)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter an integer: ";
            }
            mat[i] = temp_val;
        }
        break;
    }
    case FillMethod::Random: {
        RandomGenerator gen(-10, 10);
        for (size_t i = 0; i < n; ++i) {
            mat[i] = gen.generate();
        }
        break;
    }
    default:
        std::cout << "Unexpected error in choice. Filling with random numbers.\n";
        RandomGenerator gen(-10, 10);
        for (size_t i = 0; i < n; ++i) {
            mat[i] = gen.generate();
        }
        break;
    }

   
    std::cout << "Original array: " << mat.toString() << std::endl;

    // Task 1
    Task1Exercise t1(mat);
    t1.Task();
    std::cout << "After task 1: " << mat.toString() << std::endl;

    // Task 2
    int k = 0;
    std::cout << "Enter K for task 2: ";
    while (!safeInputInt(k)) {
        std::cout << "Invalid input. Please enter an integer: ";
    }
    Task2Exercise t2(mat, new RandomGenerator(-10, 10), k);
    t2.Task();
    std::cout << "After task 2: " << mat.toString() << std::endl;

    // Task 3
    Task3Exercise t3(mat);
    Matrix<int> resultArray = t3.Task();
    std::cout << "Result of task 3 (new array A): " << resultArray.toString() << std::endl;

    return 0;
}
#endif
