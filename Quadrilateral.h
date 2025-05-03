#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <vector>
#include "Point.h"

/**
 * @class Quadrilateral
 * @brief Представляет четырёхугольник и предоставляет методы для анализа его свойств.
 */
class Quadrilateral {
private:
    std::vector<Point> vertices;

    /**
     * @struct Line
     * @brief Уравнение прямой в форме Ax + By + C = 0.
     */
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
    /**
     * @brief Конструктор четырёхугольника.
     * @param points Вектор из 4 точек.
     * @throws std::invalid_argument:
     * - Если точек не 4.
     * - Если точки совпадают.
     * - Если три точки коллинеарны.
     */
    Quadrilateral(const std::vector<Point>& points);
    
    /**
     * @brief Проверяет выпуклость четырёхугольника.
     * @return true, если выпуклый.
     */
    bool isConvex() const;
    
    /**
     * @brief Проверяет возможность описания окружности.
     * @param tolerance Допустимая погрешность (по умолчанию 1e-9).
     * @return true, если условие Птолемея выполняется.
     */
    bool canCircumscribe(double tolerance = 1e-9) const;
};

#endif
