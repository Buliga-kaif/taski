#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <locale.h>

/*
 * @brief Функция счета рекуррентного соотношения.
 * @param k значение параметра k.
 * @return Возвращает следующий член последовательности.
 */
float recurrence_relation(const float k) {
    return (-1) * (1.0 / (k + 1)) * pow(((k + 1) / k), 4);
}

/*
 * @brief Функция подсчёта суммы ряда с заданной точностью.
 * @param e значение точности.
 * @return Возвращает сумму членов последовательности, по модулю не меньших e.
 */
float sum_e(const float e) {
    float current_ = 1;
    float sum = 0;

    for (int i = 1; fabs(current_) >= e + DBL_EPSILON; i++) {
        sum += current_;
        current_ *= recurrence_relation(i);
    }
    return sum;
}

/*
 * @brief Функция подсчёта суммы первых n членов ряда.
 * @param n количество членов.
 * @return Возвращает сумму первых n членов последовательности.
 */
float sum_n(const int n) {
    float current_ = 1;
    float sum = current_;

    for (int i = 1; i < n; i++) {
        current_ *= recurrence_relation(i);
        sum += current_;
    }
    return sum;
}

/*
 * @brief Функция проверки корректного ввода.
 * @remarks При неправильном вводе программа будет закрыта с кодом ошибки EXIT_FAILURE.
 * @return Возвращает введённое значение при успешном вводе.
 */
int input(void) {
    int input_ = 0;
    if (scanf("%d", &input_) != 1) {
        printf("Input error\n");
        exit(EXIT_FAILURE);
    }
    return input_;
}

/*
 * @brief Функция проверки ввода значения выше нуля.
 * @remarks При неправильном вводе программа будет закрыта с кодом ошибки EXIT_FAILURE.
 * @return Возвращает введённое значение, если оно выше нуля.
 */
int check_above_zero(void) {
    int input_ = input();
    if (input_ <= 0) {
        puts("Error Input\n");
        exit(EXIT_FAILURE);
    }
    return input_;
}

/*
 * @brief Функция проверки ввода значения погрешности.
 * @remarks При неправильном вводе программа будет закрыта с кодом ошибки EXIT_FAILURE.
 * @return Возвращает введённое значение, если оно положительное.
 */
float input_e(void) {
    float input = 0.0;
    if (scanf("%f", &input) != 1) {
        printf("Input error\n");
        exit(EXIT_FAILURE);
    }
    return input;
}

/*
 * @brief Функция проверки на положительное значение погрешности.
 * @remarks При неправильном вводе программа будет закрыта с кодом ошибки EXIT_FAILURE.
 * @return Возвращает введённое значение, если оно положительное.
 */
float check_e(void) {
    float input_ = input_e();
    if (input_ <= 0) {
        puts("Error Input\n");
        exit(EXIT_FAILURE);
    }
    return input_;
}

/*
 * @brief Точка входа.
 * @return Возвращает 0 при успешном завершении работы.
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

