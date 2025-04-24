#ifndef SEGMENT_H
#define SEGMENT_H

#include "Point.h"
#include <stdexcept>

class Segment {
private:
    Point left_point, right_point;

public:
    Segment(const Point& left, const Point& right);
    float calculate_ordinate(float x) const;
    void shift_left(float delta);
    static Segment read_segment(float left_x, float left_y, float right_x, float right_y);
    void display() const;
};

#endif
