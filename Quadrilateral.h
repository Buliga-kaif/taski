#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <vector>
#include <stdexcept>
#include "Point.h"

/**
 * @class Quadrilateral
 * @brief Класс для работы с четырёхугольниками и анализа их свойств.
 */
class Quadrilateral {
private:
    static constexpr double EPSILON = 1e-9; // Допустимая погрешность
    std::vector<Point> vertices;

    /**
     * @struct Line
     * @brief Прямая в форме Ax + By + C = 0.
     */
    struct Line {
        double A = 0, B = 0, C = 0;
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
     * - Если передано не 4 точки.
     * - Если обнаружены совпадающие точки.
     * - Если три точки лежат на одной прямой.
     */
    Quadrilateral(const std::vector<Point>& points);

    /**
     * @brief Проверяет, является ли четырёхугольник выпуклым.
     * @return true, если четырёхугольник выпуклый.
     */
    bool isConvex() const;

    /**
     * @brief Проверяет, можно ли описать окружность вокруг четырёхугольника.
     * @param tolerance Допустимая погрешность (по умолчанию EPSILON).
     * @return true, если AB + CD = BC + DA с заданной погрешностью.
     */
    bool canCircumscribe(double tolerance = EPSILON) const;
};

#endif
