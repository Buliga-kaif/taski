#include <iostream>
#include "Array.h"

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    std::cout << "Введите размер массива n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Размер должен быть положительным.\n";
        return 1;
    }

    Array arr(n);

    int choice;
    std::cout << "Заполнить массив:\n1 - случайными числами\n2 - вручную\nВаш выбор: ";
    std::cin >> choice;

    if (choice == 1) {
        arr.fillRandom();
        std::cout << "Массив заполнен случайными числами.\n";
    } else if (choice == 2) {
        arr.fillManual();
    } else {
        std::cout << "Неверный выбор. Заполняю случайными числами.\n";
        arr.fillRandom();
    }

    arr.print("Исходный массив");

    std::cout << "\n--- Задача 1 ---\n";
    arr.task1();
    arr.print("После задачи 1");

    std::cout << "\n--- Задача 2 ---\n";
    int K;
    std::cout << "Введите число K для вставки: ";
    std::cin >> K;

    Array arr2 = arr.task2(K);
    arr2.print("После задачи 2");

    std::cout << "\n--- Задача 3 ---\n";
    Array arr3 = arr2.task3();
    arr3.print("Массив A (результат задачи 3)");

    return 0;
}
