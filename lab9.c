#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char expression[100];
    printf("Введите арифметическое выражение: ");
    fgets(expression, 100, stdin);

    char* token = strtok(expression, " ");
    double result = 0;
    int isUnary = 1;  

    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            isUnary = 0;  
        } else if (strcmp(token, "-") == 0) {
            isUnary = 0;  
        } else {
            double number = atof(token);
            if (isUnary) {
                result = number;  
            } else {
                result = (expression[0] == '+') ? result + number : result - number;  
            }
            isUnary = 1;  
        }
        token = strtok(NULL, " ");
    }

    printf("Результат: %lf\n", result);
    return 0;
}
