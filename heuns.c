#include <stdio.h>

 
float dydx(float x, float y) {
    return (2*y)/x; 
}

 
void heunsMethod(float x0, float y0, float h, float xn) {
    float x = x0;
    float y = y0;
    float k1, k2;

    printf("x\t   y\n");
    printf("%0.3f\t%0.3f\n", x, y);

    while (x < xn) {
   
        k1 = h * dydx(x, y);
   
        k2 = h * dydx(x + h, y + k1);
        
   
        y = y + 0.5 * (k1 + k2);
        x = x + h;

        printf("%0.3f\t%0.3f\n", x, y);
    }
}

int main() {
    float x0, y0, h, xn;

    
    printf("Enter initial value of x: ");
    scanf("%f", &x0);
    printf("Enter initial value of y: ");
    scanf("%f", &y0);
    printf("Enter step size (h): ");
    scanf("%f", &h);
    printf("Enter the final value of x: ");
    scanf("%f", &xn);

   
    heunsMethod(x0, y0, h, xn);

    return 0;
}
