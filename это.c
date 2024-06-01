#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Запросить у пользователя количество чисел
    int count;
    printf("Введите количество чисел: ");
    scanf("%d", &count);

    // Создать файл input.txt и заполнить его случайными числами
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d ", rand() % 100); // запись случайных чисел в файл
    }

    fclose(file);

    // Открыть файл input.txt и прочитать значения, заменить числа и вывести результат в файл output.txt
    file = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        if (number % 5 == 0 && number % 7 == 0) {
            fprintf(outputFile, "ПЯТЬСЕМЬ ");
        } else if (number % 5 == 0) {
            fprintf(outputFile, "ПЯТЬ ");
        } else if (number % 7 == 0) {
            fprintf(outputFile, "СЕМЬ ");
        } else {
            fprintf(outputFile, "%d ", number);
        }
    }

    fclose(file);
    fclose(outputFile);

    // Сформировать матрицу из файла input.txt, вычислить сумму строк и столбцов, вывести матрицу и результаты сложения
    file = fopen("input.txt", "r");

    int matrix[100][100]; // Максимальный размер матрицы
    int rows = 0, cols = 0;

    // Заполнение матрицы из файла
    while (fscanf(file, "%d", &matrix[rows][cols]) != EOF) {
        cols++;
        if (cols == 3) { // Задайте нужное количество столбцов
            rows++;
            cols = 0;
        }
    }

    // Вывод матрицы на экран
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Вычисление суммы строк и столбцов
    int rowSum, colSum;
    for (int i = 0; i < rows; i++) {
        rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        printf("Сумма строки %d: %d\n", i+1, rowSum);
    }

    for (int j = 0; j < cols; j++) {
        colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        printf("Сумма столбца %d: %d\n", j+1, colSum);
    }

    fclose(file);

    // Замерить время работы программы и вывести на экран
    return 0;
}
