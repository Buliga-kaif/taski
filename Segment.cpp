#include "Segment.h"
#include <cmath>
#include <limits>

Segment::Segment(const Point& left, const Point& right) 
    : left_point(left), right_point(right) {
    if (left == right) {
        throw std::invalid_argument("Points cannot be the same");
    }
}

float Segment::calculate_ordinate(float x) const {
    float x1 = left_point.getX();
    float y1 = left_point.getY();
    float x2 = right_point.getX();
    float y2 = right_point.getY();

    if (x < std::min(x1, x2) - EPSILON || x > std::max(x1, x2) + EPSILON) {
        throw std::out_of_range("x is out of the segment bounds");
    }

    if (std::abs(x1 - x2) < EPSILON) return y1;
    return y1 + ((y2 - y1) / (x2 - x1)) * (x - x1);
}

void Segment::shift_left(float delta) {
    left_point = Point(left_point.getX() - delta, left_point.getY());
    right_point = Point(right_point.getX() - delta, right_point.getY());
}

Segment Segment::read_segment(std::istream& is) {
    float left_x, left_y, right_x, right_y;
    if (!(is >> left_x >> left_y >> right_x >> right_y)) {
        throw std::invalid_argument("Invalid input");
    }
    return Segment(Point(left_x, left_y), Point(right_x, right_y));
}

void Segment::display() const {
    std::cout << "Segment: ";
    left_point.display();
    std::cout << " -> ";
    right_point.display();
    std::cout << "\n";
}

const Point& Segment::getLeft() const { return left_point; }
const Point& Segment::getRight() const { return right_point; }
