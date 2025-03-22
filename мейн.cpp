#include <iostream>
#include "Quadrilateral.h"

int main() {
    try {
        std::vector<Point> points(4);
        
        for (int i = 0; i < 4; ++i) {
            std::cout << "Enter coordinates for point " << i + 1 << " (x y): ";
            std::cin >> points[i].x >> points[i].y;
        }

        Quadrilateral quad(points);

        std::cout << "Is the quadrilateral convex? " 
                  << (quad.isConvex() ? "Yes" : "No") << std::endl;
        std::cout << "Can a circumcircle be circumscribed? " 
                  << (quad.canCircumscribe() ? "Yes" : "No") << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
