#include <stdio.h>

int main() {
    int array[2][2];

    printf("Введите значения массива:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    printf("Квадрат матрицы:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", array[i][j] * array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
