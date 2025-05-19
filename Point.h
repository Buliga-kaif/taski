
#ifndef POINT_H
#define POINT_H

#include <limits>

class Point {
private:
    float x, y;
    static constexpr float EPSILON = std::numeric_limits<float>::epsilon();

public:
    Point(float x = 0, float y = 0);
    float getX() const;
    float getY() const;
    void display() const;
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
};

#endif
