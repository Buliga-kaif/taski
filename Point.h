#ifndef POINT_H
#define POINT_H
#include <limits>

/**
 * @class Point
 * @brief Класс для работы с точкой в двумерном пространстве.
 */
class Point {
private:
    double x = 0.0; ///< Координата X точки
    double y = 0.0; ///< Координата Y точки

public:
    /**
     * @brief Конструктор точки.
     * @param x Координата X (по умолчанию 0).
     * @param y Координата Y (по умолчанию 0).
     */
    Point(double x = 0, double y = 0);

    /// @brief Возвращает координату X.
    double getX() const;

    /// @brief Возвращает координату Y.
    double getY() const;

    /**
     * @brief Проверяет равенство двух точек.
     * @param other Сравниваемая точка.
     * @return true, если точки совпадают с учетом погрешности.
     */
    bool operator==(const Point& other) const;

    /// @brief Проверяет неравенство двух точек.
    bool operator!=(const Point& other) const;
};

#endif
