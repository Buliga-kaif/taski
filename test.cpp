#include <gtest/gtest.h>
#include "Segment.h"
#include <sstream>

TEST(SegmentTest, Creation) {
    Point p1(1, 2), p2(3, 4);
    Segment s(p1, p2);
    EXPECT_NEAR(s.calculate_ordinate(2), 3.0f, Segment::EPSILON);
}

TEST(SegmentTest, SamePoints) {
    EXPECT_THROW(Segment(Point(5, 5), Point(5, 5)), std::invalid_argument);
}

TEST(SegmentTest, VerticalSegment) {
    Segment s(Point(2, 3), Point(2, 5));
    EXPECT_NEAR(s.calculate_ordinate(2), 3.0f, Segment::EPSILON);
}

TEST(SegmentTest, ShiftLeft) {
    Segment s(Point(1, 1), Point(3, 3));
    s.shift_left(1.0f);
    EXPECT_NEAR(s.getLeft().getX(), 0.0f, Segment::EPSILON);
    EXPECT_NEAR(s.getRight().getX(), 2.0f, Segment::EPSILON);
}

TEST(SegmentTest, ReadSegment) {
    std::stringstream iss("10 20 30 40");
    Segment s = Segment::read_segment(iss);
    EXPECT_NEAR(s.getLeft().getX(), 10.0f, Segment::EPSILON);
    EXPECT_NEAR(s.getLeft().getY(), 20.0f, Segment::EPSILON);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
