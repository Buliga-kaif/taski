#include "Array.h"
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <stdexcept>

bool Array::containsDigitOne(int num) {
    std::string s = std::to_string(std::abs(num));
    return s.find('1') != std::string::npos;
}

Array::Array() : data(nullptr), size(0) {}

Array::Array(int n) : data(n > 0 ? std::make_unique<int[]>(n) : nullptr), size(n > 0 ? n : 0) {}

Array::Array(const Array& other) : data(other.size > 0 ? std::make_unique<int[]>(other.size) : nullptr), size(other.size) {
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Array::Array(Array&& other) noexcept : data(std::move(other.data)), size(other.size) {
    other.size = 0;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        size = other.size;
        data = other.size > 0 ? std::make_unique<int[]>(other.size) : nullptr;
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        size = other.size;
        other.size = 0;
    }
    return *this;
}

Array::~Array() = default;

void Array::fillRandom() {
    if (size == 0) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-10, 10);

    for (int i = 0; i < size; ++i) {
        data[i] = dis(gen);
    }
}

void Array::fillManual() {
    if (size == 0) return;

    std::cout << "Введите " << size << " целых чисел:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> data[i];
    }
}

void Array::task1() {
    if (size < 2) {
        std::cout << "Массив слишком мал для выполнения задачи 1.\n";
        return;
    }

    int maxNegative = -11;
    bool foundNegative = false;

    for (int i = 0; i < size; ++i) {
        if (data[i] < 0) {
            if (data[i] > maxNegative) {
                maxNegative = data[i];
                foundNegative = true;
            }
        }
    }

    if (foundNegative) {
        data[1] = maxNegative;
        std::cout << "Второй элемент заменён на максимальный отрицательный: " << maxNegative << "\n";
    } else {
        std::cout << "Отрицательных элементов нет. Второй элемент не изменён.\n";
    }
}

Array Array::task2(int K) const {
    if (size == 0) return Array();

    std::vector<int> temp;

    for (int i = 0; i < size; ++i) {
        if (containsDigitOne(data[i])) {
            temp.push_back(K);
        }
        temp.push_back(data[i]);
    }

    Array result(static_cast<int>(temp.size()));
    for (size_t i = 0; i < temp.size(); ++i) {
        result.data[i] = temp[i];
    }

    return result;
}

Array Array::task3() const {
    if (size == 0) return Array();

    Array result(size);

    for (int i = 0; i < size; ++i) {
        int index = i + 1;
        if (index % 2 == 0) {
            result.data[i] = data[i] * data[i];
        } else {
            if (index == 1) {
                result.data[i] = data[i];
            } else {
                result.data[i] = data[i] / index;
            }
        }
    }

    return result;
}

void Array::print(const std::string& title) const {
    std::cout << title << ": ";
    if (size == 0) {
        std::cout << "пуст\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

Array& Array::operator<<(int value) {
    return *this;
}

Array& Array::operator>>(int& value) {
    if (size == 0) throw std::out_of_range("Массив пуст");
    value = data[0];
    return *this;
}
