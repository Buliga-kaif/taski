#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <vector>
#include "Point.h"

class Quadrilateral {
private:
    std::vector<Point> vertices;
    
    struct Line {
        double A, B, C; // Ax + By + C = 0
    };

    Line getLineFromPoints(const Point& p1, const Point& p2) const;
    bool findIntersection(const Line& l1, const Line& l2, Point& intersection) const;
    bool isPointInsideBoundingBox(const Point& p) const;
    
public:
    Quadrilateral(const std::vector<Point>& points);
    bool isConvex() const;
    bool canCircumscribe(double tolerance = 1e-9) const;
};

#endif
