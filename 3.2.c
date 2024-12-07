#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <locale.h>


/*
 * @brief Вычисляет следующее значение в последовательности.
 * @param k Параметр последовательности.
 * @return Значение следующего члена последовательности.
 */
float recurrence_relation(const float k);
/*
 * @brief Суммирует последовательность до достижения заданной точности.
 * @param e Точность, с которой нужно учитывать члены последовательности.
 * @return Сумма всех членов, модуль которых больше или равен e.
 */
float sum_e(const float e);
/*
 * @brief Вычисляет сумму первых n членов последовательности.
 * @param n Количество членов для суммирования.
 * @return Сумма первых n членов.
 */
float sum_n(const int n);
/*
 * @brief Запрашивает и получает ввод целого числа.
 * @return Введенное пользователем целое число.
 * @throws EXIT_FAILURE при ошибке ввода.
 */
int input(void);
/*
 * @brief Получает и проверяет, что введенное число больше нуля.
 * @return Проверенное положительное целое число.
 * @throws EXIT_FAILURE, если число не больше нуля.
 */
int check_above_zero(void);
/*
 * @brief Запрашивает и получает ввод числа с плавающей точкой.
 * @return Введенное пользователем число.
 * @throws EXIT_FAILURE при ошибке ввода.
 */
float input_e(void);
/*
 * @brief Получает и проверяет, что введенное число положительное.
 * @return Проверенное положительное число с плавающей точкой.
 * @throws EXIT_FAILURE, если число не положительное.
 */
float check_e(void);

/*
 * @brief Главная функция программы.
 * @details Устанавливает локаль, получает ввод от пользователя и вычисляет суммы ряда.
 * @return 0, если программа завершилась успешно.
 */
int main(void) {
    setlocale(LC_ALL, "Rus");

    puts("Введите верхний порог:");
    int n = check_above_zero();

    puts("Введите погрешность:");
    float e = check_e();

    printf("Сумма %d членов: %f\n", n, sum_n(n));
    printf("Сумма членов с погрешностью: %f\n", sum_e(e));

    return 0;
}

float recurrence_relation(const float k) {
    return (-1) * (1.0 / (k + 1)) * pow(((k + 1) / k), 4);
}


float sum_e(const float e) {
    float current_ = 1;
    float sum = 0;

    for (int i = 1; fabs(current_) >= e + DBL_EPSILON; i++) {
        sum += current_;
        current_ *= recurrence_relation(i);
    }
    return sum;
}


float sum_n(const int n) {
    float current_ = 1;
    float sum = current_;

    for (int i = 1; i < n; i++) {
        current_ *= recurrence_relation(i);
        sum += current_;
    }
    return sum;
}


int input(void) {
    int input_ = 0;
    if (scanf("%d", &input_) != 1) {
        printf("Input error\n");
        exit(EXIT_FAILURE);
    }
    return input_;
}


int check_above_zero(void) {
    int input_ = input();
    if (input_ <= 0) {
        puts("Error Input\n");
        exit(EXIT_FAILURE);
    }
    return input_;
}


float input_e(void) {
    float input = 0.0;
    if (scanf("%f", &input) != 1) {
        printf("Input error\n");
        exit(EXIT_FAILURE);
    }
    return input;
}


float check_e(void) {
    float input_ = input_e();
    if (input_ <= 0) {
        puts("Error Input\n");
        exit(EXIT_FAILURE);
    }
    return input_;
}

