#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <float.h> 

/*
 * @brief Главная функция программы.
 *
 * Программа запрашивает размеры кирпича и отверстия, и определяет,
 * сможет ли кирпич пройти через отверстие.
 *
 * @return Возвращает 0 в случае успешного выполнения программы.
 */
double inputDouble(void);
/*
 * @brief Функция для проверки возможности прохождения кирпича через отверстие.
 * @return Возвращает true, если кирпич может пройти через отверстие, иначе false.
 */
bool canPass(double x, double y, double z, double r, double s);
/*
 * @brief Главная функция программы.
 *
 * Программа запрашивает размеры кирпича (x, y, z) и отверстия (r, s),
 * после чего определяет, может ли кирпич пройти через отверстие.
 * Пользователь вводит размеры с консоли.
 * @return Возвращает 0 в случае успешного выполнения программы.
 */


int main(void) {
    setlocale(LC_ALL, "");

    printf("Введите размеры кирпича (x, y, z): \n");

    printf("x: ");
    double x = inputDouble();

    printf("y: ");
    double y = inputDouble();

    printf("z: ");
    double z = inputDouble();

    printf("Введите размеры отверстия (r, s): \n");

    printf("r: ");
    double r = inputDouble();

    printf("s: ");
    double s = inputDouble();

    if (canPass(x, y, z, r, s)) {
        printf("Кирпич пройдет через отверстие.\n");
    }
    else {
        printf("Кирпич не пройдет через отверстие.\n");
    }

    return 0;
}

/*
 * @brief Функция для ввода числа типа double с консоли с проверкой корректности.
 *
 * @return Возвращает введённое пользователем положительное число типа double.
 */
double inputDouble(void) {
    double number = 0.0;
    while (scanf("%lf", &number) != 1 || number <= DBL_EPSILON) {
        printf("Ошибка ввода. Пожалуйста, введите положительное число: ");
        while (getchar() != '\n'); 
    }
    return number;
}


bool canPass(double x, double y, double z, double r, double s) {
    return (x <= r && y <= s) || (x <= s && y <= r) ||
        (x <= r && z <= s) || (x <= s && z <= r) ||
        (y <= r && z <= s) || (y <= s && z <= r);
}
