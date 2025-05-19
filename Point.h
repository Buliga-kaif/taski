#ifndef POINT_H
#define POINT_H

/**
 * @class Point
 * @brief Класс, представляющий точку в двумерном пространстве.
 */
class Point {
private:
    double x, y;
public:
    Point(double x = 0, double y = 0);
    double getX() const;
    double getY() const;
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
};

#endif


