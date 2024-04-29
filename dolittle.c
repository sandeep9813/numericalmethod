#include <stdio.h>

#define N 3

void doolittleDecomposition(float A[N][N], float L[N][N], float U[N][N]) {
    int i, j, k;

    // Initialize matrices L and U
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            U[i][j] = 0;
            if (i == j) {
                L[i][j] = 1;
            } else {
                L[i][j] = 0;
            }
        }
    }

    // Perform Doolittle decomposition
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            U[i][j] = A[i][j];
            for (k = 0; k < i; k++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }

        for (j = i + 1; j < N; j++) {
            L[j][i] = A[j][i];
            for (k = 0; k < i; k++) {
                L[j][i] -= L[j][k] * U[k][i];
            }
            L[j][i] /= U[i][i];
        }
    }
}

int main() {
    float A[N][N] = {{2,3,-1},
                     {3,2,1},
                     {1,-5,3}};
    float L[N][N], U[N][N];

    doolittleDecomposition(A, L, U);

    printf("Matrix L:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", L[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix U:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", U[i][j]);
        }
        printf("\n");
    }

    return 0;
}
