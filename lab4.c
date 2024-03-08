#include <stdio.h>
#include "triangle.c"

int main() {
    double a, b, c;

    printf("Введите значения длин сторон треугольника:\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    if (a + b > c && a + c > b && b + c > a) {
        double perimeter = calculateP(a, b, c);
        double area = calculateS(a, b, c);

        printf("Периметр треугольника: %.2lf\n", perimeter);
        printf("Площадь треугольника: %.2lf\n", area);
    } else {
        printf("Треугольник с такими сторонами не существует.\n");
    }

    return 0;
}
