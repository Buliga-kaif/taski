#include "Point.h"

Point::Point(float x, float y) : x(x), y(y) {}

void Point::display() const {
    std::cout << "Point(" << x << ", " << y << ")\n";
}
