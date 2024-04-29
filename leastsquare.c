#include <stdio.h>

#define MAX_POINTS 10

void leastSquaresFit(float x[], float y[], int n, float *A, float *B);

int main() {
    int n;
    float x[MAX_POINTS], y[MAX_POINTS], A, B;

    printf("Enter the number of data points (maximum %d): ", MAX_POINTS);
    scanf("%d", &n);

    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    leastSquaresFit(x, y, n, &A, &B);

    printf("The least squares fit line equation is: Y = %.2f + %.2fX\n", A, B);

    return 0;
}

void leastSquaresFit(float x[], float y[], int n, float *A, float *B) {
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    // Calculate the sums
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Calculate the slope (B)
    *B = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);

    // Calculate the intercept (A)
    *A = (sumY - (*B) * sumX) / n;
}
