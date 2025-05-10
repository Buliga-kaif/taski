#include "Segment.h"
#include <iostream>

int main() {
    try {
        std::cout << "Enter left X, left Y, right X, right Y: ";
        Segment segment = Segment::read_segment(std::cin);
        segment.display();

        float x;
        std::cout << "Enter x to calculate ordinate: ";
        std::cin >> x;
        std::cout << "Ordinate at x=" << x << ": " 
                  << segment.calculate_ordinate(x) << std::endl;

        float delta;
        std::cout << "Enter shift delta: ";
        std::cin >> delta;
        segment.shift_left(delta);
        segment.display();

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
