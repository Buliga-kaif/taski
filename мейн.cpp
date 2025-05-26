#include <iostream>
#include <vector>
#include "Quadrilateral.h"

/**
 * @brief Основная функция для ввода данных и проверки свойств четырёхугольника.
 */
int main() {
    try {
        std::vector<Point> points;
        for (size_t i = 0; i < 4; ++i) {
            double x, y;
            std::cout << "Введите координаты точки " << i + 1 << " (x y): ";
            std::cin >> x >> y;
            points.emplace_back(x, y);
        }
        Quadrilateral quad(points);
        std::cout << "Выпуклый: " << (quad.isConvex() ? "Да" : "Нет") << "\n";
        std::cout << "Можно описать окружность: " << (quad.canCircumscribe() ? "Да" : "Нет") << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
