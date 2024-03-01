#include <stdio.h>

int main() {
    double array[3][3];
    double sum_main_diagonal = 0;
    double sum_secondary_diagonal = 0;

    // Ввод значений массива с консоли
    printf("Введите значения массива:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("array[%d][%d]: ", i, j);
            scanf("%lf", &array[i][j]);
        }
    }

    // Вычисление суммы элементов на главной диагонали
    for (int i = 0; i < 3; i++) {
        sum_main_diagonal += array[i][i];
    }

    // Вычисление суммы элементов на побочной диагонали
    for (int i = 0; i < 3; i++) {
        sum_secondary_diagonal += array[i][2 - i];
    }

    // Вывод суммы элементов на главной и побочной диагоналях
    printf("Сумма элементов на главной диагонали: %lf\n", sum_main_diagonal);
    printf("Сумма элементов на побочной диагонали: %lf\n", sum_secondary_diagonal);

    return 0;
}
