
#include "Segment.h"
#include <iostream>
#include <limits>
#include <string>


template<typename T>
T getInput(const std::string& prompt);

int main() {
    try {
        std::cout << "Enter left x, left y, right x, right y:\n";
        Segment segment = Segment::readSegment(std::cin);
        segment.display();
        std::cout << std::endl;

        float x = getInput<float>("Enter x to calculate ordinate: ");
        std::cout << "Ordinate at x=" << x << ": "
                  << segment.calculate(x) << std::endl;

        float delta = getInput<float>("Enter shift delta: ");
        segment.shiftLeft(delta);
        segment.display();
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}


template<typename T>
T getInput(const std::string& prompt) {
    T value{};
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid input. Please enter a number.\n";
    }
    return value;
}

template float getInput<float>(const std::string& prompt);
