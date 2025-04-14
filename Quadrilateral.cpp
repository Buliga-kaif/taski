#include "Quadrilateral.h"
#include <cmath>
#include <stdexcept>

Quadrilateral::Quadrilateral(const std::vector<Point>& points) : vertices(points) {
    if (vertices.size() != 4) {
        throw std::invalid_argument("4точки");
    }
}

double Quadrilateral::crossProduct(const Point& p1, const Point& p2, const Point& p3) const {
    return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - 
           (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}

bool Quadrilateral::isConvex() const {
    bool isPositive = false;
    bool isNegative = false;

    for (size_t i = 0; i < vertices.size(); ++i) {
        double crossProd = crossProduct(vertices[i], 
                                       vertices[(i+1) % 4], 
                                       vertices[(i+2) % 4]);
        if (crossProd > 0) {
            if (isNegative) return false;
            isPositive = true;
        }
        else if (crossProd < 0) {
            if (isPositive) return false;
            isNegative = true;
        }
    }
    return true;
}

double Quadrilateral::getSideLength(size_t i, size_t j) const {
    return std::sqrt(std::pow(vertices[i].getX() - vertices[j].getX(), 2) + 
                    std::pow(vertices[i].getY() - vertices[j].getY(), 2));
}

bool Quadrilateral::canCircumscribe() const {
    double ab = getSideLength(0, 1);
    double bc = getSideLength(1, 2);
    double cd = getSideLength(2, 3);
    double da = getSideLength(3, 0);
    
    return std::abs((ab + cd) - (bc + da)) < 1e-9;
}
