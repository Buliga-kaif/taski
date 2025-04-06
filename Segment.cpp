#include "Segment.h"

Segment::Segment(const Point& left, const Point& right)
    : left_point(left), right_point(right.x, left.y) {}

float Segment::calculate_ordinate(float x) const {
    if (x >= left_point.x && x <= right_point.x) {
        return left_point.y;
    } else {
        throw std::out_of_range("x is out of the segment bounds");
    }
}

void Segment::shift_left(float delta) {
    left_point.x -= delta;
    right_point.x -= delta;
}

Segment Segment::read_segment(float left_x, float left_y, float right_x) {
    Point left(left_x, left_y);
    return Segment(left, Point(right_x, 0));
}

void Segment::display() const {
    std::cout << "Segment: ";
    left_point.display();
    right_point.display();
}
