
#ifndef DEQUE_H
#define DEQUE_H

#include <initializer_list>
#include <string>
#include <sstream>

class Deque {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* front;
    Node* back;
    size_t size;
    
    void clear(); 

public:
    // Конструкторы и деструктор
    Deque();
    Deque(const Deque& other);
    Deque(Deque&& other);
    Deque(std::initializer_list<int> init);
    ~Deque();
    
    // Операторы присваивания
    Deque& operator=(const Deque& other);
    Deque& operator=(const Deque&& other);
    
    // Операторы ввода/вывода
    Deque& operator<<(int value); 
    Deque& operator>>(int& value); 

    // Основные методы
    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();
    int peek_front() const;
    int peek_back() const;
    bool isEmpty() const;
    size_t getSize() const;
    std::string toString() const;
};

#endif
