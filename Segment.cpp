#include "Segment.h"
#include <iostream>

Segment::Segment(const Point& left, const Point& right) 
    : left_point(left), right_point(right) {}

float Segment::calculate_ordinate(float x) const {
    float x1 = left_point.getX();
    float y1 = left_point.getY();
    float x2 = right_point.getX();
    float y2 = right_point.getY();

    if (x < x1 || x > x2) {
        throw std::out_of_range("x is out of the segment bounds");
    }

    if (x1 == x2) return y1; // Вертикальный сегмент
    return y1 + ((y2 - y1) / (x2 - x1)) * (x - x1); // Уравнение прямой
}

void Segment::shift_left(float delta) {
    left_point = Point(left_point.getX() - delta, left_point.getY());
    right_point = Point(right_point.getX() - delta, right_point.getY());
}

Segment Segment::read_segment(float left_x, float left_y, float right_x, float right_y) {
    Point left(left_x, left_y);
    Point right(right_x, right_y);
    return Segment(left, right);
}

void Segment::display() const {
    std::cout << "Segment: ";
    left_point.display();
    std::cout << " -> ";
    right_point.display();
    std::cout << "\n";
}
