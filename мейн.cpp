#include <iostream>
#include <vector>
#include "Quadrilateral.h"

int main() {
    try {
        std::vector<Point> points(4);
        for (size_t i = 0; i < 4; ++i) {
            std::cout << "Enter coordinates for point " << i + 1 << " (x y): ";
            double x, y;
            std::cin >> x >> y;
            points[i].setX(x);
            points[i].setY(y);
        }

        Quadrilateral quad(points);

        std::cout << "Is the quadrilateral convex? "
                  << (quad.isConvex() ? "Yes" : "No") << std::endl;
        std::cout << "Can a circle be circumscribed? "
                  << (quad.canCircumscribe() ? "Yes" : "No") << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
