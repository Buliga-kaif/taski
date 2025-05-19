#include "Quadrilateral.h"
#include <cmath>
#include <algorithm>
#include <array>

Quadrilateral::Quadrilateral(const std::vector<Point>& points) : vertices(points) {
    if (vertices.size() != 4) {
        throw std::invalid_argument("Требуется ровно 4 точки");
    }

    for (size_t i = 0; i < vertices.size(); ++i) {
        for (size_t j = i + 1; j < vertices.size(); ++j) {
            if (vertices[i] == vertices[j]) {
                throw std::invalid_argument("Обнаружены совпадающие точки");
            }
        }
    }

    for (size_t i = 0; i < vertices.size(); ++i) {
        if (areCollinear(vertices[i], vertices[(i+1)%4], vertices[(i+2)%4])) {
            throw std::invalid_argument("Три точки лежат на одной прямой");
        }
    }
}

bool Quadrilateral::areCollinear(const Point& a, const Point& b, const Point& c) const {
    return std::abs(crossProduct(a, b, c)) < EPSILON;
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
    const double det = l1.A * l2.B - l2.A * l1.B;
    if (std::abs(det) < EPSILON) return false;

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

    return (p.getX() >= xmin - EPSILON && p.getX() <= xmax + EPSILON &&
            p.getY() >= ymin - EPSILON && p.getY() <= ymax + EPSILON);
}

bool Quadrilateral::isConvex() const {
    bool positive = false, negative = false;
    for (size_t i = 0; i < 4; ++i) {
        const double cp = crossProduct(vertices[i], vertices[(i+1)%4], vertices[(i+2)%4]);
        if (cp > EPSILON) positive = true;
        else if (cp < -EPSILON) negative = true;
        if (positive && negative) return false;
    }

  
    Line diag1 = getLineFromPoints(vertices[0], vertices[2]);
    Line diag2 = getLineFromPoints(vertices[1], vertices[3]);
    Point intersection;
    return findIntersection(diag1, diag2, intersection) && 
           isPointInsideBoundingBox(intersection);
}

bool Quadrilateral::canCircumscribe(double tolerance) const {
    std::array<double, 4> sides;
    for (size_t i = 0; i < 4; ++i) {
        sides[i] = getSideLength(i, (i + 1) % 4);
    }

    const double sumAB_CD = sides[0] + sides[2];
    const double sumBC_DA = sides[1] + sides[3];
    return std::abs(sumAB_CD - sumBC_DA) < tolerance;
}

double Quadrilateral::getSideLength(size_t i, size_t j) const {
    return std::hypot(
        vertices[i].getX() - vertices[j].getX(),
        vertices[i].getY() - vertices[j].getY()
    );
}
