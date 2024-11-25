#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>

/*
 * @brief Вычисляет вес (силу тяжести) объекта
 * @param mass Масса объекта в килограммах
 * @param g Ускорение свободного падения в м/с²
 * @return Возвращает вес объекта в ньютонах
 */
double getWeight(const double mass, const double g);

/*
 * @brief Вводит число с проверкой
 * @return Введенное число типа double
 * Выводит сообщение об ошибке и завершает программу в случае некорректного ввода.
 */
double input(void);

/*
 * @brief Главная функция программы
 * Запрашивает у пользователя массу объекта и рассчитывает его вес
 * с использованием фиксированного значения ускорения свободного падения.
 * Результат выводится на экран.
 * @return 0, если программа завершилась успешно.
 */
int main(void) {
    printf("Enter mass:\t");
    const double mass = input();
    const double g = 9.81; 
    printf("Weight:\t%lf\n", getWeight(mass, g));
    printf("gravity:\t%lf\n", getWeight(mass, g));
    return 0;
}

double input(void) {
    double number = 0.0; 
    if (!scanf_s("%lf", &number)) {
        printf("Input Error\n");
        exit(EXIT_FAILURE);
    }
    return number;
}

double getWeight(const double mass, const double g) {
    return (mass * g);
}

