/**
 * @brief Простые юнит-тесты без Google Test.
 */
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <string>
#include <random>
#include <stdexcept>

// Подключаем все необходимые заголовки
#include "Matrix.h"
#include "Generator.h"
#include "ConstantGenerator.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "Exercise.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"

using namespace miit::algebra;

void test_Matrix() {
    std::cout << "Testing Matrix...\n";

    // Тест 1: Конструктор по умолчанию
    {
        Matrix<int> m;
        assert(m.getSize() == 0);
    }

    // Тест 2: Конструктор с размером
    {
        Matrix<int> m(3);
        assert(m.getSize() == 3);
        m[0] = 10;
        m[1] = 20;
        m[2] = 30;
        assert(m[0] == 10 && m[1] == 20 && m[2] == 30);
    }

    // Тест 3: Выход за границы
    {
        Matrix<int> m(2);
        bool threw = false;
        try {
            (void)m[5];
        } catch (const std::out_of_range&) {
            threw = true;
        }
        assert(threw);
    }

    // Тест 4: Копирование
    {
        Matrix<int> m1(2);
        m1[0] = 100;
        m1[1] = 200;
        Matrix<int> m2 = m1;
        assert(m2.getSize() == 2);
        assert(m2[0] == 100 && m2[1] == 200);
    }

    // Тест 5: Присваивание
    {
        Matrix<int> m1(2);
        m1[0] = 42;
        m1[1] = 84;
        Matrix<int> m2(1);
        m2 = m1;
        assert(m2.getSize() == 2);
        assert(m2[0] == 42 && m2[1] == 84);
    }

    // Тест 6: toString
    {
        Matrix<int> m(3);
        m[0] = 1;
        m[1] = -2;
        m[2] = 3;
        assert(m.toString() == "1 -2 3");
    }

    std::cout << " Matrix tests passed.\n";
}

void test_Generators() {
    std::cout << "Testing Generators...\n";

    // ConstantGenerator
    {
        ConstantGenerator gen(999);
        assert(gen.generate() == 999);
        assert(gen.generate() == 999);
    }

    // IStreamGenerator
    {
        std::istringstream input("42");
        IStreamGenerator gen(input);
        assert(gen.generate() == 42);
    }

    // RandomGenerator — проверим, что значения в диапазоне
    {
        RandomGenerator gen(-10, 10);
        for (int i = 0; i < 100; ++i) {
            int val = gen.generate();
            assert(val >= -10 && val <= 10);
        }
    }

    std::cout << " Generator tests passed.\n";
}

void test_Task1Exercise() {
    std::cout << "Testing Task1Exercise...\n";

    // Обычный случай
    {
        Matrix<int> mat(4);
        mat[0] = 5;
        mat[1] = 100;  // будет заменён
        mat[2] = -3;
        mat[3] = -1;   // макс. отриц.

        Task1Exercise task(mat, new ConstantGenerator(0));
        task.Task();

        assert(mat[0] == 5);
        assert(mat[1] == -1); // заменён
        assert(mat[2] == -3);
        assert(mat[3] == -1);
    }

    // Нет отрицательных — не меняется
    {
        Matrix<int> mat(3);
        mat[0] = 1;
        mat[1] = 2;
        mat[2] = 3;

        Task1Exercise task(mat, new ConstantGenerator(0));
        task.Task();

        assert(mat[1] == 2);
    }

    // Маленький массив — не должно падать
    {
        Matrix<int> mat(1);
        mat[0] = -5;
        Task1Exercise task(mat, new ConstantGenerator(0));
        task.Task();
        assert(mat[0] == -5);
    }

    std::cout << " Task1Exercise tests passed.\n";
}

void test_Task2Exercise() {
    std::cout << "Testing Task2Exercise...\n";

    // Обычный случай: вставка K перед числами с '1'
    {
        Matrix<int> mat(3);
        mat[0] = 5;     // без '1'
        mat[1] = 12;    // есть '1'
        mat[2] = -101;  // есть '1'

        Task2Exercise task(mat, new ConstantGenerator(0), 999);
        task.Task();

        assert(mat.getSize() == 5);
        assert(mat[0] == 5);
        assert(mat[1] == 999);
        assert(mat[2] == 12);
        assert(mat[3] == 999);
        assert(mat[4] == -101);
    }

    // Нет цифр '1' — ничего не вставляется
    {
        Matrix<int> mat(2);
        mat[0] = 23;
        mat[1] = -45;
        Task2Exercise task(mat, new ConstantGenerator(0), 777);
        task.Task();
        assert(mat.getSize() == 2);
        assert(mat[0] == 23);
        assert(mat[1] == -45);
    }

    // Число 1 и 0
    {
        Matrix<int> mat(2);
        mat[0] = 0;
        mat[1] = 1;
        Task2Exercise task(mat, new ConstantGenerator(0), 100);
        task.Task();
        assert(mat.getSize() == 3);
        assert(mat[0] == 0);
        assert(mat[1] == 100);
        assert(mat[2] == 1);
    }

    // Пустой массив
    {
        Matrix<int> mat(0);
        Task2Exercise task(mat, new ConstantGenerator(0), 5);
        task.Task();
        assert(mat.getSize() == 0);
    }

    std::cout << " Task2Exercise tests passed.\n";
}

int main() {
    std::cout << "=== Запуск всех тестов ===\n";

    test_Matrix();
    test_Generators();
    test_Task1Exercise();
    test_Task2Exercise();

    std::cout << "\n🎉 Все тесты пройдены успешно!\n";
    return 0;
}
