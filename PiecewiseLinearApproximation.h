#ifndef APPROXIMATION_H
#define APPROXIMATION_H
#include "Point.h"
#include <vector>
#include <initializer_list>

/**
 * @class PiecewiseLinearApproximation
 * @brief Абстрактный класс для кусочно-линейной аппроксимации.
 */
class PiecewiseLinearApproximation {
protected:
    std::vector<Point> points; 

public:
    PiecewiseLinearApproximation() = default;
    PiecewiseLinearApproximation(const std::vector<Point>& points);
    PiecewiseLinearApproximation(std::initializer_list<Point> points);

    virtual ~PiecewiseLinearApproximation() = default;

    /**
     * @brief Вычисление ординаты по абсциссе.
     * @param x Абсцисса.
     * @return Ордината y.
     */
    virtual float calculateY(float x) const = 0;

    /// @brief Добавление точки в коллекцию.
    virtual void addPoint(const Point& p);

    /// @brief Чтение точек из потока.
    virtual void readPoints(std::istream& is);
};

#endif
