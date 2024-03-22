//matrix_operations.c

#include "matrix_operations.h"
 
double** calculate(double** matrix1, double** matrix2, int n, char operation) {
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            if (operation == '+') {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            } else if (operation == '-') {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            } else if (operation == '*') {
                result[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }
    return result;
}
