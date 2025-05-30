#include <gtest/gtest.h>
#include "Deque.h"

class DequeTest : public ::testing::Test {
protected:
    void SetUp() override {
        dq.push_front(30);
        dq.push_front(20);
        dq.push_front(10);
        dq.push_back(40);
    }

    Deque dq;
};

TEST_F(DequeTest, Initialization) {
    Deque empty;
    EXPECT_TRUE(empty.isEmpty());
    EXPECT_EQ(empty.getSize(), 0);
}

TEST_F(DequeTest, PushOperations) {
    EXPECT_EQ(dq.peek_front(), 10);
    EXPECT_EQ(dq.peek_back(), 40);
    EXPECT_EQ(dq.getSize(), 4);
}

TEST_F(DequeTest, PopOperations) {
    EXPECT_EQ(dq.pop_front(), 10);
    EXPECT_EQ(dq.pop_back(), 40);
    EXPECT_EQ(dq.getSize(), 2);
}

TEST_F(DequeTest, BoundaryConditions) {
    Deque empty;
    EXPECT_THROW(empty.pop_front(), std::out_of_range);
    EXPECT_THROW(empty.peek_back(), std::out_of_range);
}

TEST_F(DequeTest, CopySemantics) {
    Deque copy = dq;
    EXPECT_EQ(copy.toString(), "[10, 20, 30, 40]");
    
    copy.pop_front();
    EXPECT_NE(copy.toString(), dq.toString());
}

TEST_F(DequeTest, MoveSemantics) {
    Deque moved = std::move(dq);
    EXPECT_EQ(moved.toString(), "[10, 20, 30, 40]");
    EXPECT_TRUE(dq.isEmpty());
}

TEST_F(DequeTest, StreamOperators) {
    std::stringstream ss;
    ss << dq;
    EXPECT_EQ(ss.str(), "[10, 20, 30, 40]");

    int val;
    dq >> val;
    EXPECT_EQ(val, 10);
}

TEST_F(DequeTest, InitializerList) {
    Deque init = {1, 2, 3, 4};
    EXPECT_EQ(init.toString(), "[1, 2, 3, 4]");
}
