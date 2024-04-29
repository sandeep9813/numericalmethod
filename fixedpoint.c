#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001

float g(float x) {
    return 1 + 1 / x;
}

int main() {
    float x0, x1;

    printf("Enter an initial guess: ");
    scanf("%f", &x0);

    int iterations = 0;
    do {
        x1 = g(x0);
        printf("Iteration %d: Root = %.4f\n", iterations + 1, x1);
        x0 = x1;
        iterations++;
    } while (fabs(x1 - x0) > EPSILON && iterations < 1000);

    printf("Root = %.4f\n", x1);
    printf("Number of iterations = %d\n", iterations);

    return 0;
}
