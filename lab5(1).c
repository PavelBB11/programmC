//Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double 
//(значения n и элементы массивов ввести с консоли).
//А также ввести с консоли знак операции: '+', '-' или '*'. 
//Написать функцию, вычисляющую сум-му, разность или произведение данных матриц (их передать по указателю) и
//возвра-щающую указатель на массив-результат. Разместить эту функцию в отдельном модуле 
//(отличном от того, где располагается функция main()). Выдать на консоль значения по-лученного вектора.

 
#include <stdio.h> 
#include <stdlib.h> 
#include "matrix_operations.h" 
 
int main() { 
    int n; 
    printf("Введите размерность матрицы: "); 
    scanf("%d", &n); 

    double** matrix1 = (double**)malloc(n * sizeof(double*)); 
    for (int i = 0; i < n; i++) { 
        matrix1[i] = (double*)malloc(n * sizeof(double)); 
        for (int j = 0; j < n; j++) { 
            printf("Введите элемент матрицы 1[%d][%d]: ", i, j); 
            scanf("%lf", &matrix1[i][j]); 
        } 
    } 
 
    double** matrix2 = (double**)malloc(n * sizeof(double*)); 
    for (int i = 0; i < n; i++) { 
        matrix2[i] = (double*)malloc(n * sizeof(double)); 
        for (int j = 0; j < n; j++) { 
            printf("Введите элемент матрицы 2[%d][%d]: ", i, j); 
            scanf("%lf", &matrix2[i][j]); 
        } 
    } 
 
    char operation; 
    printf("Введите знак операции (+, -, *): "); 
    scanf(" %c", &operation); 
  
    double** result = calculate(matrix1, matrix2, n, operation); 
 
    printf("Результат:\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            printf("%lf ", result[i][j]); 
        } 
        printf("\n"); 
    } 
 
    for (int i = 0; i < n; i++) { 
        free(matrix1[i]); 
        free(matrix2[i]); 
        free(result[i]); 
    } 
    free(matrix1); 
    free(matrix2); 
    free(result); 
 
    return 0; 
}
