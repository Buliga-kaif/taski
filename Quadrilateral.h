#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <vector>
#include "Point.h"

class Quadrilateral {
private:
    std::vector<Point> vertices;

    struct Line {
        double A, B, C; 
    };

    Line getLineFromPoints(const Point& p1, const Point& p2) const;
    bool findIntersection(const Line& l1, const Line& l2, Point& intersection) const;
    bool isPointInsideBoundingBox(const Point& p) const;
    double crossProduct(const Point& p1, const Point& p2, const Point& p3) const;
    bool areCollinear(const Point& a, const Point& b, const Point& c) const;
    double getSideLength(size_t i, size_t j) const;

public:
    Quadrilateral(const std::vector<Point>& points);
    bool isConvex() const;
    bool canCircumscribe(double tolerance = 1e-9) const;
};

#endif
