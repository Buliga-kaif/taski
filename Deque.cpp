#include "Deque.h"
#include <stdexcept>
#include <sstream>

Deque::Deque() : front(nullptr), back(nullptr), size(0) {}

Deque::Deque(const Deque& other) : Deque() {
    Node* current = other.front;
    while (current) {
        push_back(current->data);
        current = current->next;
    }
}

Deque::Deque(std::initializer_list<int> init) : Deque() {
    for (int val : init) push_back(val);
}

Deque::~Deque() {
    clear();
}

void Deque::clear() {
    while (!isEmpty()) pop_front();
}

Deque& Deque::operator=(const Deque& other) {
    if (this != &other) {
        clear();
        Node* current = other.front;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }
    return *this;
}

void Deque::push_front(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = back = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

void Deque::push_back(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = back = newNode;
    } else {
        newNode->prev = back;
        back->next = newNode;
        back = newNode;
    }
    size++;
}

int Deque::pop_front() {
    if (isEmpty()) throw std::out_of_range("Deque is empty");
    Node* temp = front;
    int val = temp->data;
    front = front->next;
    if (front) front->prev = nullptr;
    else back = nullptr;
    delete temp;
    size--;
    return val;
}

int Deque::pop_back() {
    if (isEmpty()) throw std::out_of_range("Deque is empty");
    Node* temp = back;
    int val = temp->data;
    back = back->prev;
    if (back) back->next = nullptr;
    else front = nullptr;
    delete temp;
    size--;
    return val;
}


int Deque::peek_front() const {
    if (isEmpty()) throw std::out_of_range("Deque is empty");
    return front->data;
}

int Deque::peek_back() const {
    if (isEmpty()) throw std::out_of_range("Deque is empty");
    return back->data;
}


bool Deque::isEmpty() const { return size == 0; }
size_t Deque::getSize() const { return size; }

std::string Deque::toString() const {
    std::ostringstream oss;
    Node* current = front;
    oss << "[";
    while (current) {
        oss << current->data;
        if (current->next) oss << ", ";
        current = current->next;
    }
    oss << "]";
    return oss.str();
}

Deque& Deque::operator<<(int value) {
    push_back(value);
    return *this;
}

Deque& Deque::operator>>(int& value) {
    value = pop_front();
    return *this;
}
