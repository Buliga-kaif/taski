#include <iostream>
#include <vector>
#include "Quadrilateral.h"

int main() {
    const size_t numPoints = 4;
    const double tolerance = 1e-9;

    try {
        std::vector<Point> points;
        for (size_t i = 0; i < numPoints; ++i) {
            double x, y;
            std::cout << "Enter coordinates for point " << i + 1 << " (x y): ";
            std::cin >> x >> y;
            points.emplace_back(x, y);
        }

        Quadrilateral quad(points);
        std::cout << "Is convex: " << (quad.isConvex() ? "Yes" : "No") << "\n";
        std::cout << "Can circumscribe: " << (quad.canCircumscribe(tolerance) ? "Yes" : "No") << "\n";

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
