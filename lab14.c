#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

int fibonacci(int n) {
    if (n <= 0) {
        longjmp(buf, 1); 
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Введите число для вычисления суммы чисел Фибоначчи: ");
    scanf("%d", &n);

    if (setjmp(buf) == 0) {
        int result = fibonacci(n);
        printf("Сумма чисел Фибоначчи до %d: %d\n", n, result);
    } else {
        printf("Ошибка: неверное значение для вычисления суммы чисел Фибоначчи\n");
    }

    return 0;
}
