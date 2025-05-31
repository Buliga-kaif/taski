
#include "Segment.h"
#include <sstream>
#include <algorithm>
#include <limits>

Segment::Segment(const Point& p1, const Point& p2) {
    if (p1 == p2) throw std::invalid_argument("Points are identical");
    points = {p1, p2};
}

float Segment::calculate(float x) const {
    const Point& p1 = points[0];
    const Point& p2 = points[1];
    
    if (x < std::min(p1.getX(), p2.getX()) - EPSILON ||
        x > std::max(p1.getX(), p2.getX()) + EPSILON) {
        throw std::out_of_range("X is out of segment range");
    }
    
    if (std::abs(p1.getX() - p2.getX()) < EPSILON) 
        return p1.getY();
    
    return p1.getY() + ((p2.getY() - p1.getY()) / 
                      (p2.getX() - p1.getX())) * (x - p1.getX());
}

void Segment::shiftLeft(float delta) {
    for (auto& p : points) {
        p = Point(p.getX() - delta, p.getY());
    }
}

Segment Segment::readSegment(std::istream& is) {
    Point p1, p2;
    if (!(is >> p1 >> p2)) {
        throw std::invalid_argument("Invalid input format");
    }
    return Segment(p1, p2);
}

void Segment::display() const {
    std::cout << "Segment: " << points[0] << " to " << points[1];
}

std::ostream& operator<<(std::ostream& os, const Segment& s) {
    os << s.points[0] << " " << s.points[1];
    return os;
}

std::istream& operator>>(std::istream& is, Segment& s) {
    Point p1, p2;
    if (is >> p1 >> p2) {
        s = Segment(p1, p2);
    }
    return is;
}
