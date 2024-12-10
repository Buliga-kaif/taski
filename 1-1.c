#include <stdio.h>
#include <math.h>

/**
 * @brief Функция a принимает два аргумента x и y и возвращает вычисленное значение.
 *
 * @param x Первый аргумент.
 * @param y Второй аргумент.
 */
double getA(const double x, const double y);

/**
 * @brief Функция b принимает три аргумента x, y и z и возвращает вычисленное значение.
 *
 * @param x Первый аргумент.
 * @param y Второй аргумент.
 * @param z Третий аргумент.
 * @return Вычисленное значение по формуле.
 */
double getB(const double x,const  double y,const double z);
/*
 * @brief Главная функция программы.
 * Функция main инициализирует значения переменных x, y, z и вычисляет результаты функций getA и getB.
 * Затем выводит значения x, y, z, результат getA и результат getB на стандартный вывод.
 * @return Возвращает 0 при успешном завершении программы.
 */
int main() {
    const double x = 1.426;
    const double y = -1.22;
    const double z = 3.5;
  
    printf("%lf\n%lf\n%lf\n%lf\n%lf\n", x, y, z, getA(x, y, z), getB(x, y, z));

    return 0; 
}

double GetA(const double x, const double y) {
    return (2 * cos(x - (M_PI / 6))) / (0.5 + sin(y) * sin(y));
}

double GetB(const double x, const double y, const double z) {
    return (1 + pow(z, 2)) / (3 + (pow(z, 2) / 5)); 
}
