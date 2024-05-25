#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[100];
    printf("Введите выражение для вычисления: ");
    fgets(input, 100, stdin);

    char *token = strtok(input, " ");
    float result = 0;
    char operator = '+';

    while (token != NULL) {
        if (token[0] == '+' || token[0] == '-') {
            operator = token[0];
        } else {
            float number = strtof(token, NULL);
            if (operator == '+') {
                result += number;
            } else if (operator == '-') {
                result -= number;
            }
        }
        token = strtok(NULL, " ");
    }

    printf("Результат: %f\n", result);

    return 0;
}
