#include <iostream>
#include "Deque.h"

int main() {
    // Создание дека через список инициализации
    Deque dq = {100, 200, 300};
    std::cout << "Initial Deque: " << dq.toString() << "\n";

    // Добавление элементов
    dq.push_front(50);
    dq << 400; // Использование оператора <<
    std::cout << "After pushes: " << dq.toString() << "\n";

    // Извлечение элементов
    int val;
    dq >> val; // Использование оператора >>
    std::cout << "Popped front: " << val << "\n";
    std::cout << "After pop: " << dq.toString() << "\n";

    // Просмотр элементов
    std::cout << "Front: " << dq.peek_front() 
              << ", Back: " << dq.peek_back() << "\n";

    return 0;
}
