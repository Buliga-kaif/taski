#ifndef SEGMENT_H
#define SEGMENT_H
#include "PiecewiseLinearApproximation.h"
#include <stdexcept>

/**
 * @class Segment
 * @brief Класс для работы с отрезком (наследник аппроксимации).
 */
class Segment : public PiecewiseLinearApproximation {
private:
    static constexpr float EPSILON = std::numeric_limits<float>::epsilon();

public:
    Segment(const Point& p1, const Point& p2);
    Segment(std::initializer_list<Point> points);

    float calculateY(float x) const override;
    void shiftLeft(float delta);

    
    static Segment readSegment(std::istream& is);
    void display() const;
};

#endif
