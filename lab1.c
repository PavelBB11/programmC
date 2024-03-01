#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b, c, D=0, x1, x2;
    int x;
    do {
    
    printf("Введите коэффициент при a: ");
    scanf("%lf", &a);
    printf("Введите коэффициент при b: ");
    scanf("%lf", &b);
    printf("Введите коэффициент при c: ");
    scanf("%lf", &c);
    
    D = b*b - 4*a*c;
    printf("D = %lf\n", D);
    
    if (D>0) {
        x1=(-b+sqrt(D))/(2*a);
        x2=(-b-sqrt(D))/(2*a);
    printf("x1=%lf\nx2=%lf\n", x1, x2);
     
    }
    if (D==0) {
        x1=(-b/(2*a));
    }
    if (D<0) {
        printf("Корней нет\n");
    }
    printf("Для повторения работы программы введите 1:\n");
    scanf("%d", &x); 
    } while(x==1);
    return 0;
}
