#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>  

void fillArray(int* array, size_t size, int useRandom);
void printArray(const int* array, size_t size);
long long productOfEven(const int* array, size_t size);
void replaceOddIndexWithSquares(int* array, size_t size);
int hasPositiveModuloK(const int* array, size_t size, int k);

int main() {
    setlocale(LC_ALL, "");
    size_t n;
    int k;
    printf("Введите размер массива: ");
    scanf("%zu", &n);

    printf("Введите число k: ");
    scanf("%d", &k);

    int* array = (int*)malloc(n * sizeof(int));
    if (!array) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    int useRandom;
    printf("Заполнить массив случайными числами? (1 - да, 0 - нет): ");
    scanf("%d", &useRandom);

    fillArray(array, n, useRandom);
    printf("Массив:\n");
    printArray(array, n);

    long long product = productOfEven(array, n);
    printf("Произведение четных элементов: %lld\n", product);

    replaceOddIndexWithSquares(array, n);
    printf("Массив после замены нечетных индексов:\n");
    printArray(array, n);

    int hasPositive = hasPositiveModuloK(array, n, k);
    printf("Есть ли положительные элементы, делящиеся на %d с остатком 2: %s\n", k, hasPositive ? "Да" : "Нет");

    free(array);
    return 0;
}

void fillArray(int* array, size_t size, int useRandom) {
    if (useRandom) {
        srand(time(NULL));
        for (size_t i = 0; i < size; ++i) {
            array[i] = rand() % 31 - 15; // Random numbers between -15 and 15
        }
    }
    else {
        for (size_t i = 0; i < size; ++i) {
            printf("Введите элемент %zu: ", i + 1);
            scanf("%d", &array[i]);
        }
    }
}

void printArray(const int* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

long long productOfEven(const int* array, size_t size) {
    long long product = 1;
    int foundEven = 0;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] % 2 == 0) {
            product *= array[i];
            foundEven = 1;
        }
    }
    return foundEven ? product : 0;
}

void replaceOddIndexWithSquares(int* array, size_t size) {
    for (size_t i = 1; i < size; i += 2) { // Start at index 1 for odd indices
        array[i] = i * i;
    }
}

int hasPositiveModuloK(const int* array, size_t size, int k) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] > 0 && array[i] % k == 2) {
            return 1;
        }
    }
    return 0;
}
