 #include <stdio.h>
#include <math.h>

#define EPSILON 0.0001

float f(float x) {
    return x*x*x - 3*x - 2;
}

float df(float x) {
    return 3*x*x - 3;
}

int main() {
    float x0, x1;

    printf("Enter the initial guess: ");
    scanf("%f", &x0);

    int iterations = 0;
    float error;
    do {
        x1 = x0 - f(x0) / df(x0);
        iterations++;
        error = fabs(f(x1));
        printf("Iteration %d: Root = %.4f, Error = %.4f\n", iterations, x1, error);
        x0 = x1;
    } while (error > EPSILON && iterations < 1000);

    printf("Root = %.4f\n", x1);
    printf("Number of iterations = %d\n", iterations);

    return 0;
}

