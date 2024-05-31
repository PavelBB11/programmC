#include <stdio.h>

void printDigitsForward(int n) {
    if (n == 0) {
        return;
    }
    printDigitsForward(n / 10);
    printf("%d ", n % 10);
}

void printDigitsBackward(int n) {
    if (n == 0) {
        return;
    }
    printf("%d ", n % 10);
    printDigitsBackward(n / 10);
}

int main() {
    int num;
    printf("Введите натуральное число: ");
    scanf("%d", &num);
    
    printf("Цифры в обычном порядке: ");
    printDigitsForward(num);
    
    printf("\nЦифры в обратном порядке: ");
    printDigitsBackward(num);
    
    return 0;
}
