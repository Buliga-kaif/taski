int main(void) {
    setlocale(LC_ALL, "");

    size_t n = inputSizeT("Введите размер массива: ");
    int k = inputInt("Введите число k: ");
    int* array = allocateAndCheckMemory(n);
    int* newArray = allocateAndCheckMemory(n); 

    int useRandom = inputInt("Заполнить массив случайными числами? (1 - да, 0 - нет): ");
    fillArray(array, n, useRandom);

    printf("Массив:\n");
    printArray(array, n);

    long long product = productOfEven(array, n);
    printf("Произведение четных элементов: %lld\n", product >= 0 ? product : 0);

    
    for (size_t i = 0; i < n; ++i) {
        newArray[i] = array[i]; 
    }
    processArray(array, n, newArray, k);

    printf("Массив после процесса:\n");
    printArray(newArray, n);

    free(array);
    free(newArray);

    return 0;
}

void fillArray(int* array, const size_t size, const int useRandom) {
    if (array == NULL || size == 0) {
        printf("Ошибка: некорректный массив или размер.\n");
        return;
    }

    int minRange = 0;
    int maxRange = 0;

    if (useRandom) {
        while (1) {
            minRange = inputInt("Введите минимальное значение для случайных чисел: ");
            maxRange = inputInt("Введите максимальное значение для случайных чисел: ");
            if (minRange <= maxRange) {
                break;
            }
            else {
                printf("Ошибка: минимальное значение не должно превышать максимальное. Попробуйте снова.\n");
            }
        }

        srand((unsigned)time(NULL));
        for (size_t i = 0; i < size; ++i) {
            array[i] = minRange + rand() % (maxRange - minRange + 1);
        }
    }
    else {
        for (size_t i = 0; i < size; ++i) {
            array[i] = inputInt("Введите элемент: ");
        }
    }
}

void printArray(const int* array, const size_t size) {
    if (array == NULL || size == 0) {
        printf("Ошибка: некорректный массив или размер.\n");
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

long long productOfEven(const int* array, const size_t size) {
    if (array == NULL || size == 0) {
        printf("Ошибка: некорректный массив или размер.\n");
        return -1;
    }

    long long product = 1;
    bool foundEven = false;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] % 2 == 0) {
            product *= array[i];
            foundEven = true;
        }
    }
    return foundEven ? product : -1;
}

int hasPositiveModulo(const int* array, const size_t size, const int k) {
    if (array == NULL || size == 0) {
        printf("Ошибка: некорректный массив или размер.\n");
        return 0;
    }

    if (k == 0) {
        printf("Ошибка: деление на ноль.\n");
        return 0;
    }

    for (size_t i = 0; i < size; ++i) {
        if (array[i] > 0 && array[i] % k == 2) {
            return 1;
        }
    }
    return 0;
}

void replaceOddIndicesWithSquares(const int* array, int* newArray, const size_t size) {
    if (array == NULL || newArray == NULL || size == 0) {
        printf("Ошибка: некорректные массивы или размер.\n");
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        if (i % 2 != 0) {
            newArray[i] = i * i;
        }
        else {
            newArray[i] = array[i];
        }
    }
}

void processArray(const int* array, const size_t size, int* newArray, const int k) {
    if (array == NULL || newArray == NULL || size == 0) {
        printf("Ошибка: некорректные массивы или размер.\n");
        return;
    }

    if (hasPositiveModulo(array, size, k)) {
        printf("Есть положительные числа с остатком 2.\n");
    }
    else {
        printf("Положительных чисел с остатком 2 нет.\n");
    }

    replaceOddIndicesWithSquares(array, newArray, size);

    for (size_t i = 0; i < size; ++i) {
        if (newArray[i] % 2 == 0) {
            printf("Первый четный элемент найден: %d\n", newArray[i]);
            break;
        }
    }
}

int inputInt(const char* prompt) {
    int value = 0;
    printf("%s", prompt);
    if (scanf("%d", &value) != 1) {
        perror("Ошибка ввода");
        abort();
    }
    while (getchar() != '\n');
    return value;
}

size_t inputSizeT(const char* prompt) {
    size_t value = 0;
    printf("%s", prompt);
    if (scanf("%zu", &value) != 1 || value == 0) {
        perror("Ошибка ввода");
        abort();
    }
    while (getchar() != '\n');
    return value;
}

int* allocateAndCheckMemory(size_t size) {
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    return array;
}

