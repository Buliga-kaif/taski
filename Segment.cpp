#include "Segment.h"

Segment::Segment(const Point& left, const Point& right)
    : left_point(left), right_point(right) {} 

float Segment::calculate_ordinate(float x) const {
    if (x >= left_point.getX() && x <= right_point.getX()) {
        return left_point.getY(); // Сегмент горизонтальный (y одинаковый)
    } 
    throw std::out_of_range("x is out of the segment bounds");
}

void Segment::shift_left(float delta) {
    left_point = Point(left_point.getX() - delta, left_point.getY());
    right_point = Point(right_point.getX() - delta, right_point.getY());
}

Segment Segment::read_segment(float left_X, float left_y, float right_X) {
    Point left(left_X, left_y);
    Point right(right_X, left_y); 
    return Segment(left, right);
}


void Segment::display() const {
    std::cout << "Segment: ";
    left_point.display();
    std::cout << " -> ";
    right_point.display();
    std::cout << "\n";
}
