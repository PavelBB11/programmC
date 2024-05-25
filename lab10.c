#include <stdio.h>

#define MAXIMUM(a, n) ({ \
    int i; \
    int max = (a)[0]; \
    for (i = 1; i < n; i++) { \
        if ((a)[i] > max) { \
            max = (a)[i]; \
        } \
    } \
    max; \
})

int main() {
    int size;
    printf("Введите количество чисел: ");
    scanf("%d", &size);

    int numbers[size];
    printf("Введите числа через пробел: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    int maxNumber = MAXIMUM(numbers, size);
    printf("Максимальное число: %d\n", maxNumber);

    return 0;
}
