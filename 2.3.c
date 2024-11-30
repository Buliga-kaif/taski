#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

// Прототипы функций
double inputDouble(void);
bool canPass(double x, double y, double z, double r, double s);

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

double inputDouble(void) {
    double number = 0.0;
    while (scanf("%lf", &number) != 1 || number <= 0) {
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
