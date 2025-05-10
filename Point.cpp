#include "Point.h"
#include <iostream>

Point::Point(float x, float y) : x(x), y(y) {}

void Point::display() const {
    std::cout << "Point(" << x << ", " << y << ")";
}

float Point::getX() const { return x; }
float Point::getY() const { return y; }
