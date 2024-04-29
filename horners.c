#include <stdio.h>

// Function to evaluate a polynomial using Horner's method
float horner(float poly[], int n, float x) {
    float result = poly[0]; // Initialize result with the coefficient of highest degree term

    // Evaluate the polynomial using Horner's method
    for (int i = 1; i <= n; i++) {
        result = result * x + poly[i];
    }

    return result;
}

int main() {
    int n; // Degree of polynomial
    printf("Enter the degree of polynomial: ");
    scanf("%d", &n);

    float poly[n+1]; // Array to store coefficients of polynomial
    printf("Enter the coefficients of polynomial from highest degree term to constant term:\n");
    for (int i = 0; i <= n; i++) {
        printf("Coefficient of x^%d: ", n-i);
        scanf("%f", &poly[i]);
    }

    float x; // Value of x for which polynomial needs to be evaluated
    printf("Enter the value of x: ");
    scanf("%f", &x);

    // Evaluate the polynomial using Horner's method
    float result = horner(poly, n, x);

    printf("Result: %.2f\n", result);

    return 0;
}
