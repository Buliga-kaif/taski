#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>

/*
 * @brief Функция для вычисления значения функции y при аргументе x.
 * @param x Значение аргумента x.
 * @return Результат вычисления значения функции y при аргументе x.
 */
double y(const double x) {
    return 0.29 * pow(x, 3) + x - 1.2502;
}

/*
 * @brief Функция проверки правильности ввода границ интервала.
 * @param leftBoarder Значение левой границы интервала.
 * @param rightBoarder Значение правой границы интервала.
 */
void checkBoardersOfInterval(const double leftBoarder, const double rightBoarder) {
    if (leftBoarder > rightBoarder) {
        printf("Input error (the left border should not be greater than the right one)\n");
        exit(EXIT_FAILURE);
    }
}

/*
 * @brief Функция ввода числа типа double с консоли.
 * @return Возвращает введенное с консоли число типа double.
 */
double inputDouble() {
    double number = 0.0;
    while (scanf("%lf", &number) != 1) {
        printf("Input error. Please enter a number: ");
        while (getchar() != '\n');
    }
    return number;
}

/*
 * @brief Функция для проверки существования функции y при аргументе x.
 * @param x Значение аргумента x.
 * @return Результат проверки существования функции y при аргументе x.
 */
bool isFunctionExists(const double x) {
    return isfinite(y(x));
}

/*
 * @brief Точка входа в программу.
 * @return Возвращает 0 в случае успешного выполнения программы.
 */
int main(void) {
    printf("Enter the left border of the interval:\t");
    const double leftBoarder = inputDouble();

    printf("Enter the right border of the interval:\t");
    const double rightBoarder = inputDouble();
    checkBoardersOfInterval(leftBoarder, rightBoarder);

    printf("Enter the interval step:\t");
    double dx;
    while ((dx = inputDouble()) <= 0.0) {
        printf("Step must be positive. Please enter again:\t");
    }

    printf("x\t\t y\n");
    printf("-----------------------\n");

    for (double x = leftBoarder; x <= rightBoarder + DBL_EPSILON; x += dx) {
        if (!isFunctionExists(x))
            printf("%.2lf\t It is impossible to calculate\n", x);
        else
            printf("%.2lf\t %.5lf\n", x, y(x));
    }

    return 0;
}
