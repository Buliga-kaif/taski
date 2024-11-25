#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>  

/*
 * @brief Функция ввода числа типа double с консоли.
 * @return Возвращает введенное пользователем положительное число типа double.
 */
double inputDouble() {
    double number = 0.0; // Инициализация переменной number значением 0.0
    while (scanf("%lf", &number) != 1 || number <= 0) {
        printf("Ошибка ввода. Пожалуйста, введите положительное число: ");
        while (getchar() != '\n'); // Очистка буфера ввода
    }
    return number;
}

/*
 * @brief Точка входа в программу.
 * @return Возвращает 0 в случае успешного выполнения программы.
 */
int main() {
    setlocale(LC_ALL, "");
    double x, y, z; 
    double r, s;    
    // Ввод размеров кирпича
    printf("Введите размеры кирпича (x, y, z): \n");

    printf("x: ");
    x = inputDouble();

    printf("y: ");
    y = inputDouble();

    printf("z: ");
    z = inputDouble();

    // Ввод размеров отверстия
    printf("Введите размеры отверстия (r, s): \n");

    printf("r: ");
    r = inputDouble();

    printf("s: ");
    s = inputDouble();

    // Проверка возможности прохождения кирпича через отверстие
    if ((x <= r && y <= s) || (x <= s && y <= r) ||
        (x <= r && z <= s) || (x <= s && z <= r) ||
        (y <= r && z <= s) || (y <= s && z <= r)) {
        printf("Кирпич пройдет через отверстие.\n");
    }
    else {
        printf("Кирпич не пройдет через отверстие.\n");
    }

    return 0;
}
