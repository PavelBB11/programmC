#include <stdio.h>

int main() {
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    double array[size][size];
    double sum_main_diagonal = 0;
    double sum_secondary_diagonal = 0;

    printf("Введите значения массива:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("array[%d][%d]: ", i, j);
            scanf("%lf", &array[i][j]);
        }
    }

    for (int i = 0; i < size; i++) {
        sum_main_diagonal += array[i][i];
    }

    for (int i = 0; i < size; i++) {
        sum_secondary_diagonal += array[i][size - 1 - i];
    }

    printf("Сумма элементов на главной диагонали: %lf\n", sum_main_diagonal);
    printf("Сумма элементов на побочнoй диагонали: %lf\n", sum_secondary_diagonal);

    return 0;
}
