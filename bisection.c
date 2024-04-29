 #include<stdio.h>
#include<math.h>
#include<stdlib.h>

float f(float x) {
    float y;
    y = 4*pow(x, 3) - 2*x -6;
    return y;
}

int main() {
    float x1, x2, x0, error = 0.0001;
    int i = 0;

    printf("\nEnter two initial guesses: ");
    scanf("%f%f", &x1, &x2);

    if (f(x1) * f(x2) > 0) {
        printf("\nWrong Input!!");
        exit(0);
    } else {
        printf("iteration roots \t error \n");
        do {
            x0 = (x1 + x2) / 2;
            if (f(x0) * f(x1) > 0)
                x1 = x0;
            else
                x2 = x0;
            
            
            float currentError = fabs(f(x0));
            i++;
            
            
            printf(" %d \t %lf \t %lf\n", i, x0, currentError);
        } while (fabs(f(x0)) > error);
    }

    printf("\nRoot = %lf", x0);
    printf("\nNumber of iterations = %d", i);

    return 0;
}

