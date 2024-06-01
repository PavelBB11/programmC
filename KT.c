//Создать файл input.txt в который поместить № случайных чисел, размера, заданного пользователем с консоли. 
//Отчистить массивы. 
//Закрыть файл.
//
// 1) Открыть input.txt файл и прочитать значения, 
//все числа которые делятся на 5 заменить на слово «ПЯТЬ», на 7 на слово «СЕМЬ».
//А которые делятся на 7 и 5 5 на слово «ПЯТЬСЕМЬ», 
//вывести результат в файл output.txt.

//2) Из фала input.txt сформировать матрицу путем преобразования вектора pa N BM столбцов (лишние цифры не брать, если ровных столбцов не получается). 
//Посчитать сумму строк и столбцов. 
//Вывести матрицу на экран и результаты сложения.

//Замерить время работы программы и вывести на экран.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
//объявляем переменные для замера времени
    clock_t start, end;
    double cpu_time_used;

    start = clock();
//запрос количества чисел
    int count;
    printf("Введите количество чисел: ");
    scanf("%d", &count);
 //создать файл input и заполнить его случайными числами
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d ", rand() % 100);
    }

    fclose(file);
//открыть файл input, проверить значения, заменить числа и вывести результат в файл output.txt
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
 //сформировать матрицу, вычислить сумму строк и столбцов, вывести матрицу и результаты
    file = fopen("input.txt", "r");

    int matrix[100][100];
    int rows = 0, cols = 0;

    while (fscanf(file, "%d", &matrix[rows][cols]) != EOF) {
        cols++;
        if (cols == 3) { 
            rows++;
            cols = 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
//вычисление суммы строк и столбцов
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
//вычисление времени работы программы и вывод результата   
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Время выполнения программы: %f секунд\n", cpu_time_used);

    return 0;
}
