
#include "Segment.h"
#include <iostream>
#include <limits>

template<typename T>
T getInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid input. Please enter a number.\n";
    }
    return value;
}

int main() {
    try {
        std::cout << "Enter left X, left Y, right X, right Y:\n";
        Segment segment = Segment::read_segment(std::cin);
        segment.display();

        float x = getInput<float>("Enter x to calculate ordinate: ");
        std::cout << "Ordinate at x=" << x << ": " 
                  << segment.calculate_ordinate(x) << std::endl;

        float delta = getInput<float>("Enter shift delta: ");
        segment.shift_left(delta);
        segment.display();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
