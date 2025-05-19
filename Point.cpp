#include "Point.h"
#include <cmath>
#include <iostream>

Point::Point(float x, float y) : x(x), y(y) {}

float Point::getX() const { return x; }
float Point::getY() const { return y; }

void Point::display() const {
    std::cout << "Point(" << x << ", " << y << ")";
}

bool Point::operator==(const Point& other) const {
    return (std::abs(x - other.x) < EPSILON && 
           (std::abs(y - other.y) < EPSILON);
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}
