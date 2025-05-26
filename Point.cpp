#include "Point.h"
#include <iostream>

Point::Point(float x, float y) : x(x), y(y) {}

float Point::getX() const { return x; }
float Point::getY() const { return y; }

void Point::display() const {
    std::cout << "Point(" << x << ", " << y << ")";
}

bool Point::operator==(const Point& other) const {
    return (std::abs(x - other.x) < EPSILON 
        && std::abs(y - other.y) < EPSILON;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
