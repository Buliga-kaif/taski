#include "Segment.h"
#include <iostream>

int main() {
    Segment segment = Segment::read_segment(1, 2, 4);
    segment.display();

    try {
        std::cout << "Ordinate at x=2: " << segment.calculate_ordinate(2) << std::endl;
        std::cout << "Ordinate at x=5: " << segment.calculate_ordinate(5) << std::endl;
    } 
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    segment.shift_left(1);
    segment.display();

    return 0;
}
