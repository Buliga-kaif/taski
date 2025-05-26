#include "Segment.h"
#include <sstream>
#include <algorithm>

Segment::Segment(const Point& p1, const Point& p2) {
    if (p1 == p2) throw std::invalid_argument("Точки совпадают");
    points = {p1, p2};
}

float Segment::calculateY(float x) const {
    const Point& p1 = points[0];
    const Point& p2 = points[1];
    
    if (x < std::min(p1.getX(), p2.getX()) - EPSILON || 
        x > std::max(p1.getX(), p2.getX()) + EPSILON) {
        throw std::out_of_range("x вне отрезка");
    }
    
    if (std::abs(p1.getX() - p2.getX()) < EPSILON) return p1.getY();
    return p1.getY() + ((p2.getY() - p1.getY()) / (p2.getX() - p1.getX())) * (x - p1.getX());
}

void Segment::shiftLeft(float delta) {
    for (auto& p : points) {
        p = Point(p.getX() - delta, p.getY());
    }
}

Segment Segment::readSegment(std::istream& is) {
    float x1, y1, x2, y2;
    if (!(is >> x1 >> y1 >> x2 >> y2)) {
        throw std::invalid_argument("Ошибка ввода");
    }
    return Segment(Point(x1, y1), Point(x2, y2));
}
