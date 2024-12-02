#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

/*
 * @brief Главная функция программы.
 *
 * Основная цель программы — вычисление значения функции y на основе заданного x.
 *
 * @return Возвращает 0 в случае успешного выполнения программы.
 */
double inputDouble(void);
double calculateY(const double x, const double a);
/*
 * @brief Главная функция программы.
 *
 * В этой функции выполняется ввод пользователя, проводится вычисление
 * на основе указанной функции и выводится результат.
 * Программа запрашивает значение x у пользователя, использует функцию
 * `calculateY` для выполнения вычислений и выводит результат на экран.
 * @return Возвращает 0 в случае успешного выполнения программы.
 */


int main(void) {
    setlocale(LC_ALL, "");
    const double a = 2.0;
    printf("Введите значение x: ");
    const double x = inputDouble();
    const double y = calculateY(x, a);
    printf("Результат y = %lf\n", y);
    return 0;
}

/*
 * @brief Функция для ввода числа типа double с консоли.
 *
 * @return Возвращает введённое пользователем число типа double.
 */
double inputDouble(void) {
    double number = 0.0;
    int success;
    do {
        success = scanf("%lf", &number);
        if (success != 1) {
            printf("Неверный ввод. Пожалуйста, введите число: ");
            while (getchar() != '\n'); 
        }
    } while (success != 1);
    return number;
}

/*
 * @brief Функция для вычисления значения функции y в зависимости от аргумента x и параметра a.
 *
 * @param x Значение аргумента функции.
 * @param a Параметр a, используемый в вычислениях.
 * @return Значение y, вычисленное на основе введённых x и a.
 */
double calculateY(const double x, const double a) {
    if (x > 2) {
        return exp(a * x) * cos(x);
    }
    else if (x < 1) {
        return 1;
    }
    else {
        return a * pow(x, 2) * log(x);
    }
}
