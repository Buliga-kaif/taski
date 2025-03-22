#include "Quadrilateral.h"
#include <cmath>
#include <stdexcept>

Quadrilateral::Quadrilateral(const std::vector<Point>& points) : vertices(points) {
    if (vertices.size() != 4) {
        throw std::invalid_argument("Exactly four points are required to form a quadrilateral.");
    }
}

double Quadrilateral::crossProduct(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool Quadrilateral::isConvex() {
    bool isPositive = false;

    for (size_t i = 0; i < vertices.size(); ++i) {
        double crossProd = crossProduct(vertices[i], vertices[(i+1) % 4], vertices[(i+2) % 4]);
        if (crossProd > 0) {
            if (isPositive == false) {
                isPositive = true;
            }
        } else if (crossProd < 0) {
            if (isPositive == true) {
                return false; // Sign change detected; not convex
            }
        }
    }
    return true; // All cross products have the same sign
}

bool Quadrilateral::canCircumscribe() {
    // A quadrilateral can be circumscribed if the sum of the lengths of the opposite sides are equal
    double side1 = std::sqrt(std::pow(vertices[0].x - vertices[1].x, 2) + std::pow(vertices[0].y - vertices[1].y, 2));
    double side2 = std::sqrt(std::pow(vertices[2].x - vertices[3].x, 2) + std::pow(vertices[2].y - vertices[3].y, 2));
    double side3 = std::sqrt(std::pow(vertices[1].x - vertices[2].x, 2) + std::pow(vertices[1].y - vertices[2].y, 2));
    double side4 = std::sqrt(std::pow(vertices[3].x - vertices[0].x, 2) + std::pow(vertices[3].y - vertices[0].y, 2));

    return (side1 + side3) == (side2 + side4);
}
