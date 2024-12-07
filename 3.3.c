#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <float.h>


/*
 * @brief Функция для ввода числа.
 * @return Введенное пользователем число типа double.
 */
double input(void);

/*
 * @brief Получает положительное число из ввода.
 * @return Положительное число типа double, введенное пользователем.
 * Программа завершится с ошибкой, если число не положительное.
 */
double get_above_zero(void);

/*
 * @brief Получает число больше указанного минимума.
 * @param min Минимально допустимое значение.
 * @return Число, больше чем min.
 * Программа завершится с ошибкой, если число не удовлетворяет условию.
 */
double get_above_min(const double min);

/*
 * @brief Вычисляет значение синуса угла.
 * @param x Угол в радианах.
 * @return Значение синуса угла.
 */
double func(const double x);

/*
 * @brief Вычисляет сумму ряда с заданной точностью.
 * @param x Аргумент ряда.
 * @param e Точность вычисления.
 * @return Сумма ряда.
 */
double summm(const double x, const double e);

/*
 * @brief Основная точка входа в программу.
 * Программа запрашивает у пользователя нижний и верхний пределы диапазона,
 * шаг и точность для вычисления суммы ряда. Затем она выводит таблицу значений
 * функции синуса и соответствующую сумму ряда для каждого значения от a до b.
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
    for (double x = a; x <= b + DBL_EPSILON; x += h) {
        printf("%10.1f | %15.6f | %15.6f\n", x, func(x), summm(x, epsilon));
    }

    return 0;
}

double input(void) {
    double input = 0;
    while (scanf("%lf", &input) != 1) {
        printf("Некорректное значение. Повторите ввод:\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    return input;
}

double get_above_zero(void) {
    double input_ = input();
    if (input_ <= 0.0) {
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
    double sum = 0;
    int n = 1;

    while (fabs(term) > e) {
        sum += term;
        term *= -x * x / ((2 * n) * (2 * n + 1)); 
    }

    return sum;
}

