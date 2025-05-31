
#ifndef SEGMENT_H
#define SEGMENT_H

#include "PiecewisetLinearApproximation.h"
#include <stdexcept>
#include <limits>
#include <iostream>
/**
 * @class Segment
 * @brief Класс для работы с отрезком (наследник аппроксимации).
 */
class Segment : public PiecewisetLinearApproximation {
private:
    static constexpr float EPSILON = std::numeric_limits<float>::epsilon();

public:
    Segment(const Point& p1, const Point& p2);
    Segment(std::initializer_list<Point> points);
    
    float calculate(float x) const override;
    void shiftLeft(float delta);
    
    static Segment readSegment(std::istream& is);
    void display() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Segment& s);
    friend std::istream& operator>>(std::istream& is, Segment& s);
};

#endif
