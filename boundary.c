#include <stdio.h>
#include <math.h>

 
float f(float x, float y) {
    return x * y;  
}

 
float rungeKutta(float x0, float y0, float h, float xn) {
    float k1, k2, k3, k4;
    float y = y0;

    while (x0 < xn) {
        k1 = h * f(x0, y);
        k2 = h * f(x0 + h/2, y + k1/2);
        k3 = h * f(x0 + h/2, y + k2/2);
        k4 = h * f(x0 + h, y + k3);

        y += (k1 + 2*k2 + 2*k3 + k4) / 6;
        x0 += h;
    }

    return y;
}

 
float shootingMethod(float x0, float y0, float xn, float y_target, float h, float tol, int max_iter) {
    float y = y0;
    int iter = 0;

    while (iter < max_iter) {
        float y_end = rungeKutta(x0, y0, h, xn);

        if (fabs(y_end - y_target) < tol) {
            return y_end;
        }

         
        y0 = y0 + (y_target - y_end) / (xn - x0);
        iter++;
    }

    printf("Maximum number of iterations reached.\n");
    return -1;  
}

int main() {
    float x0 = 0, y0 = 1;  
    float xn = 1;  
    float y_target = exp(0.5);  
    float h = 0.01;  
    float tol = 0.0001;  
    int max_iter = 100;  

    float y_final = shootingMethod(x0, y0, xn, y_target, h, tol, max_iter);
    
    if (y_final != -1) {
        printf("Solution: y(%f) = %.6f\n", xn, y_final);
    }

    return 0;
}
