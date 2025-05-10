#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    float x, y;

public:
    Point(float x = 0, float y = 0);
    void display() const;
    float getX() const;
    float getY() const;
};

#endif
