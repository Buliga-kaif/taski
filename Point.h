#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <limits>
#include <cmath>

/**
 * @class Point
 * @brief Класс для работы с точкой в двумерном пространстве.
 */
class Point {
private:
    float x = 0.0f; ///< Координата X
    float y = 0.0f; ///< Координата Y
    static constexpr float EPSILON = std::numeric_limits<float>::epsilon(); ///< Погрешность

public:
    Point(float x = 0, float y = 0);
    float getX() const;
    float getY() const;
    void display() const;

    // Операторы
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;

    // Ввод/вывод
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
};

#endif
