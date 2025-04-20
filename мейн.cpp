#include <iostream>
#include <vector>
#include "Quadrilateral.h"

int main() {
    try {
        std::vector<Point> points;
        for (size_t i = 0; i < 4; ++i) {
            std::cout << "Enter coordinates for point " << i + 1 << " (x y): ";
            double x, y;
            std::cin >> x >> y;
            points.emplace_back(x, y); // Используем конструктор вместо set-методов
        }

        Quadrilateral quad(points);
        std::cout << "Is convex: " << (quad.isConvex() ? "Yes" : "No") << std::endl;
        std::cout << "Can circumscribe: " << (quad.canCircumscribe() ? "Yes" : "No") << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
