#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <string>

class Array {
private:
    std::unique_ptr<int[]> data;
    int size;

    static bool containsDigitOne(int num);

public:
    Array();
    explicit Array(int n);
    Array(const Array& other);
    Array(Array&& other) noexcept;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    ~Array();

    void fillRandom();
    void fillManual();

    void task1();
    Array task2(int K) const;
    Array task3() const;

    void print(const std::string& title = "Массив") const;
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }

    Array& operator<<(int value);
    Array& operator>>(int& value);

    const std::unique_ptr<int[]>& getData() const { return data; }
};

#endif
