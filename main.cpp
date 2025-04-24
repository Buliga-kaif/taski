#include "Segment.h"
#include <iostream>

int main() {
    float x1, y1, x2, y2;
    std::cout << "Enter left X, left Y, right X, right Y: ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    Segment segment = Segment::read_segment(x1, y1, x2, y2);
    segment.display();

    try {
        float x;
        std::cout << "Enter x to calculate ordinate: ";
        std::cin >> x;
        std::cout << "Ordinate at x=" << x << ": " 
                  << segment.calculate_ordinate(x) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    segment.shift_left(1);
    segment.display();

    return 0;
}
