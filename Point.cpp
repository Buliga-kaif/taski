#include "Point.h"
#include <cmath>

constexpr double EPSILON = 1e-9;

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

bool Point::operator==(const Point& other) const {
    return (std::abs(x - other.x) < EPSILON && 
           (std::abs(y - other.y) < EPSILON);
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}
