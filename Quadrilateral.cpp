#include "Quadrilateral.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>

Quadrilateral::Quadrilateral(const std::vector<Point>& points) : vertices(points) {
    const size_t REQUIRED_POINTS = 4;
    if (vertices.size() != REQUIRED_POINTS) {
        throw std::invalid_argument("Exactly 4 points required");
    }


    for (size_t i = 0; i < vertices.size(); ++i) {
        for (size_t j = i + 1; j < vertices.size(); ++j) {
            if (vertices[i].getX() == vertices[j].getX() && 
                vertices[i].getY() == vertices[j].getY()) {
                throw std::invalid_argument("Points must be distinct");
            }
        }
    }


    for (size_t i = 0; i < vertices.size(); ++i) {
        const Point& a = vertices[i];
        const Point& b = vertices[(i + 1) % 4];
        const Point& c = vertices[(i + 2) % 4];
        if (areCollinear(a, b, c)) {
            throw std::invalid_argument("Three consecutive points are collinear");
        }
    }
}


bool Quadrilateral::areCollinear(const Point& a, const Point& b, const Point& c) const {
    return crossProduct(a, b, c) == 0;
}


double Quadrilateral::crossProduct(const Point& p1, const Point& p2, const Point& p3) const {
    return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - 
           (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}

Quadrilateral::Line Quadrilateral::getLineFromPoints(const Point& p1, const Point& p2) const {
    Line line;
    line.A = p2.getY() - p1.getY();
    line.B = p1.getX() - p2.getX();
    line.C = p2.getX() * p1.getY() - p1.getX() * p2.getY();
    return line;
}


bool Quadrilateral::findIntersection(const Line& l1, const Line& l2, Point& intersection) const {
    double det = l1.A * l2.B - l2.A * l1.B;
    if (fabs(det) < 1e-9) return false; 

    intersection = Point(
        (l1.B * l2.C - l2.B * l1.C) / det,
        (l2.A * l1.C - l1.A * l2.C) / det
    );
    return true;
}


bool Quadrilateral::isPointInsideBoundingBox(const Point& p) const {
    double xmin = vertices[0].getX(), xmax = xmin;
    double ymin = vertices[0].getY(), ymax = ymin;

    for (const auto& vertex : vertices) {
        xmin = std::min(xmin, vertex.getX());
        xmax = std::max(xmax, vertex.getX());
        ymin = std::min(ymin, vertex.getY());
        ymax = std::max(ymax, vertex.getY());
    }

    return (p.getX() >= xmin - 1e-9 && p.getX() <= xmax + 1e-9 &&
            p.getY() >= ymin - 1e-9 && p.getY() <= ymax + 1e-9);
}


bool Quadrilateral::isConvex() const {
   
    bool hasPositive = false, hasNegative = false;
    for (size_t i = 0; i < 4; ++i) {
        double cp = crossProduct(vertices[i], vertices[(i+1)%4], vertices[(i+2)%4]);
        if (cp > 0) hasPositive = true;
        else if (cp < 0) hasNegative = true;
        if (hasPositive && hasNegative) return false;
    }

  
    Line diag1 = getLineFromPoints(vertices[0], vertices[2]);
    Line diag2 = getLineFromPoints(vertices[1], vertices[3]);

    Point intersection;
    if (!findIntersection(diag1, diag2, intersection)) return false;

    return isPointInsideBoundingBox(intersection);
}


double Quadrilateral::getSideLength(size_t i, size_t j) const {
    return sqrt(pow(vertices[i].getX() - vertices[j].getX(), 2) + 
             pow(vertices[i].getY() - vertices[j].getY(), 2));
}


bool Quadrilateral::canCircumscribe(double tolerance) const {
    double ab = getSideLength(0, 1);
    double bc = getSideLength(1, 2);
    double cd = getSideLength(2, 3);
    double da = getSideLength(3, 0);

    return fabs((ab + cd) - (bc + da)) < tolerance;
}
