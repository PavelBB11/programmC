#include <math.h>
double calculateP(double a, double b, double c) {
    return a + b + c;
}

double calculateS(double a, double b, double c) {
    double p = calculateP(a, b, c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
