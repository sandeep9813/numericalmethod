 #include <stdio.h>
#include <math.h>

#define SIZE 10

int main() {
    float matrix[SIZE][SIZE], eigenVector[SIZE], newEigenVector[SIZE];
    float oldEigenValue, newEigenValue, error;
    int i, j, n, step = 1;

    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Matrix[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Enter the initial guess vector:\n");
    for (i = 0; i < n; i++) {
        printf("EigenVector[%d] = ", i + 1);
        scanf("%f", &eigenVector[i]);
    }

    oldEigenValue = 1;

    do {
        // Multiplication: matrix * eigenVector
        for (i = 0; i < n; i++) {
            newEigenVector[i] = 0;
            for (j = 0; j < n; j++) {
                newEigenVector[i] += matrix[i][j] * eigenVector[j];
            }
        }

        // Finding the largest element in the new vector as the new eigenvalue
        newEigenValue = newEigenVector[0];
        for (i = 1; i < n; i++) {
            if (fabs(newEigenVector[i]) > fabs(newEigenValue)) {
                newEigenValue = newEigenVector[i];
            }
        }

        // Normalization: eigenVector = newEigenVector / newEigenValue
        for (i = 0; i < n; i++) {
            eigenVector[i] = newEigenVector[i] / newEigenValue;
        }

        // Display
        printf("\nSTEP-%d:\n", step);
        printf("EigenValue = %f\n", newEigenValue);
        printf("EigenVector:\n");
        for (i = 0; i < n; i++) {
            printf("%f\t", eigenVector[i]);
        }

        // Update oldEigenValue for next iteration
        oldEigenValue = newEigenValue;
        step++;
    } while (step <= 5);

    printf("\n\nDominant EigenValue: %f\n", newEigenValue);
    printf("Corresponding EigenVector:\n");
    for (i = 0; i < n; i++) {
        printf("%f\t", eigenVector[i]);
    }

    return 0;
}
