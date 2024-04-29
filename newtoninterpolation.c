  #include <stdio.h>

int main() {
    float x[100], f[100], xp;
    int i, j, n;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

     

    printf("Enter the data:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("f[%d] = ", i);
        scanf("%f", &f[i]);
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%f", &xp);

    float sum = f[0], mult = 1;

    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            f[j] = (f[j] - f[j - 1]) / (x[j] - x[j - i]);
        }
        mult *= (xp - x[i - 1]);
        sum += f[i] * mult;
    }

    printf("The interpolated value at x = %.2f is %.2f\n", xp, sum);

    return 0;
}