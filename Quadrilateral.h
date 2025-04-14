#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <vector>
#include "Point.h"

class Quadrilateral {
private:
    std::vector<Point> vertices;
    double crossProduct(const Point& p1, const Point& p2, const Point& p3) const;
    double getSideLength(size_t i, size_t j) const;

public:
    Quadrilateral(const std::vector<Point>& points);
    bool isConvex() const;
    bool canCircumscribe() const;
};

#endif 
