#include <stdio.h>
int countSetBitsLong(long num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int countSetBitsDouble(double num) {
    int count = 0;
    unsigned long *ptr = (unsigned long *)&num;
    unsigned long bits = *ptr;
    while (bits) {
        count += bits & 1;
        bits >>= 1;
    }
    return count;
}

int main() {
    long longNum;
    double doubleNum;

    printf("Введите значение типа long: ");
    scanf("%ld", &longNum);

    printf("Введите значение типа double: ");
    scanf("%lf", &doubleNum);

    int setBitsLong = countSetBitsLong(longNum);
    int setBitsDouble = countSetBitsDouble(doubleNum);

    printf("Количество установленных в единицу битов для числа типа long: %d\n", setBitsLong);
    printf("Количество установленных в единицу битов для числа типа double: %d\n", setBitsDouble);

    return 0;
}
