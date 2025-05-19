#ifndef SEGMENT_H
#define SEGMENT_H

#include "Point.h"
#include <stdexcept>
#include <iostream>

class Segment {
private:
    Point left_point, right_point;
    static constexpr float EPSILON = std::numeric_limits<float>::epsilon();

public:
    Segment(const Point& left, const Point& right);
    float calculate_ordinate(float x) const;
    void shift_left(float delta);
    static Segment read_segment(std::istream& is);
    void display() const;
    const Point& getLeft() const;
    const Point& getRight() const;
};

#endif
