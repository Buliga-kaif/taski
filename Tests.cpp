#include "Deque.h"
#include <cassert>

void testEmptyDeque() {
    Deque dq;
    assert(dq.isEmpty());
    assert(dq.getSize() == 0);
}

void testPushPop() {
    Deque dq;
    dq.push_front(10);
    assert(dq.peek_front() == 10);
    dq.push_back(20);
    assert(dq.peek_back() == 20);
    assert(dq.pop_front() == 10);
    assert(dq.pop_back() == 20);
    assert(dq.isEmpty());
}

void testInitializerList() {
    Deque dq = {1, 2, 3};
    assert(dq.toString() == "[1, 2, 3]");
}

void testCopyAssignment() {
    Deque dq1 = {5, 6, 7};
    Deque dq2 = dq1;
    assert(dq2.toString() == "[5, 6, 7]");
}

int main() {
    testEmptyDeque();
    testPushPop();
    testInitializerList();
    testCopyAssignment();
    return 0;
}
