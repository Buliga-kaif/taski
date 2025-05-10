#include "Segment.h"
#include <cassert>
#include <sstream>
#include <iostream>

void test_segment_creation() {
    Point p1(1, 2);
    Point p2(3, 4);
    Segment s(p1, p2);
    assert(std::abs(s.calculate_ordinate(2) - 3.0f < 1e-6);
}

void test_same_points() {
    try {
        Point p1(5, 5);
        Point p2(5, 5);
        Segment s(p1, p2);
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Points cannot be the same");
    }
}

void test_vertical_segment() {
    Point p1(2.0f, 3.0f);
    Point p2(2.0f + 1e-7f, 5.0f);
    Segment s(p1, p2);
    assert(std::abs(s.calculate_ordinate(2.0f) - 3.0f < 1e-6);
}

void test_shift_left() {
    Point p1(1, 1);
    Point p2(3, 3);
    Segment s(p1, p2);
    s.shift_left(1.0f);
    assert(std::abs(s.getLeft().getX() - 0.0f) < 1e-6);
    assert(std::abs(s.getRight().getX() - 2.0f) < 1e-6);
}

void test_read_segment() {
    std::istringstream iss("10 20 30 40");
    Segment s = Segment::read_segment(iss);
    assert(std::abs(s.getLeft().getX() - 10.0f) < 1e-6);
    assert(std::abs(s.getLeft().getY() - 20.0f) < 1e-6);
}

int main() {
    test_segment_creation();
    test_same_points();
    test_vertical_segment();
    test_shift_left();
    test_read_segment();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
