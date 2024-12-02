#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <float.h>

// Прототипы функций
double input(void);
double get_above_zero(void);
double get_above_min(const double min);
double func(const double x);
double summm(const double x, const double e);

double func(const double x) {
    return sin(x);
}
/*
 * @brief Основная точка входа в программу.
 *
 * Программа выводит таблицу значений функции синуса и соответствующую сумму ряда,
 * вычисленную с указанной точностью для заданного диапазона и шага.
 *
 * Последовательность действий следующая:
 * 1. Запрашивает у пользователя ввод нижнего предела диапазона, который должен быть больше нуля.
 * 2. Запрашивает верхний предел диапазона, который должен быть больше, чем нижний предел.
 * 3. Запрашивает шаг, который должен быть больше нуля.
 * 4. Запрашивает точность для вычисления суммы ряда, которая также должна быть больше нуля.
 * 5. Вычисляет и выводит таблицу значений функции sin(x) и суммы ряда для каждого шага x от a до b.
 *
 * @return Код завершения программы (0 для успешного выполнения).
 */
int main(void) {
    setlocale(LC_ALL, "Russian");

    puts("Введите нижний порог:");
    const double a = get_above_zero();
    puts("Введите верхний порог:");
    const double b = get_above_min(a);
    puts("Введите шаг:");
    const double h = get_above_zero();
    puts("Введите точность:");
    const double epsilon = get_above_zero();

    printf("        X  |              Y  |            SUM\n");
    for (double x = a; x <= b; x += h) {  // Условие исправлено
        printf("%10.1f | %15.6f | %15.6f\n", x, func(x), summm(x, epsilon));
    }

    return 0;
}

double input(void) {
    double input = 0;
    while (scanf("%lf", &input) != 1) {  // Корректная обработка ввода
        printf("Некорректное значение. Повторите ввод:\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);  // Очистка входного потока
    }
    return input;
}

double get_above_zero(void) {
    double input_ = input();
    if (input_ <= 0.0) {  // Простая проверка на ноль
        printf("Некорректное значение\n");
        exit(EXIT_FAILURE);
    }
    return input_;
}

double get_above_min(const double min) {
    double input_ = input();
    if (input_ < min) {
        printf("Некорректное значение\n");
        exit(EXIT_FAILURE);
    }
    return input_;
}

double summm(const double x, const double e) {
    double term = x;
    double sum = term;
    int n = 1;

    while (fabs(term) > e) {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }

    return sum;
}
