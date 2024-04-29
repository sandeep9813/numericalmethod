 #include <stdio.h>
#include <math.h>

#define EPSILON 0.0001

float f(float x) {
    return x*x - 5*x + 6;
}

int main() {
    float x0, x1, x2;

    printf("Enter two initial guesses: ");
    scanf("%f%f", &x0, &x1);

    int iterations = 0;
    float error;
    do {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        error = fabs(f(x2));
        printf("Iteration %d: Root = %.4f, Error = %.4f\n", iterations + 1, x2, error);
        x0 = x1;
        x1 = x2;
        iterations++;
    } while (error > EPSILON && iterations < 1000);

    printf("Root = %.4f\n", x2);
    printf("Number of iterations = %d\n", iterations);

    return 0;
}
