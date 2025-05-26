#include "Point.h"
#include <cmath>
#include <limits>

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

bool Point::operator==(const Point& other) const {
    return (std::abs(x - other.x) < std::numeric_limits<double>::epsilon() 
        && std::abs(y - other.y) < std::numeric_limits<double>::epsilon();
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
