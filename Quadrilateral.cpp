include "Quadrilateral.h"
#include <cmath>
#include <stdexcept>

Quadrilateral::Quadrilateral(const std::vector<Point>& points) : vertices(points) {
    if (vertices.size() != 4) {
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
}

double Quadrilateral::crossProduct(const Point& p1, const Point& p2, const Point& p3) const {
    return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - 
           (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}

bool Quadrilateral::isConvex() const {
    bool hasPositive = false;
    bool hasNegative = false;

    for (size_t i = 0; i < vertices.size(); ++i) {
        const Point& p1 = vertices[i];
        const Point& p2 = vertices[(i + 1) % 4];
        const Point& p3 = vertices[(i + 2) % 4];

        double cp = crossProduct(p1, p2, p3);
        if (cp > 0) {
            if (hasNegative) return false;
            hasPositive = true;
        } else if (cp < 0) {
            if (hasPositive) return false;
            hasNegative = true;
        }
    }
    return true;
}

double Quadrilateral::getSideLength(size_t i, size_t j) const {
    return std::sqrt(
        std::pow(vertices[i].getX() - vertices[j].getX(), 2) + 
        std::pow(vertices[i].getY() - vertices[j].getY(), 2)
    );
}

bool Quadrilateral::canCircumscribe() const {
    double ab = getSideLength(0, 1);
    double bc = getSideLength(1, 2);
    double cd = getSideLength(2, 3);
    double da = getSideLength(3, 0);

    return std::abs((ab + cd) - (bc + da)) < 1e-9;
}
