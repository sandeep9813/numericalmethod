 #include <stdio.h>
 
#include <math.h>

#define f1(x, y, z) ((-17 + 7*y + 10*z) / 2)
#define f2(x, y, z) ((14 - 5*x - 3*z))
#define f3(x, y, z) ((7 - x - 10*y) / 9)

int main() {
    float x0=0, y0=0, z0=0, x1, y1, z1;
    int count = 1;
 

    printf("\nCount\tx\ty\tz\n");
    do {
        x1 = f1(x0, y0, z0);
        y1 = f2(x1, y0, z0);
        z1 = f3(x1, y1, z0);

        printf("%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);

        count++;
        x0 = x1;
        y0 = y1;
        z0 = z1;

    } while (count <= 5);

    printf("\nFinal approximation: \n");
    printf("x = %0.3f\ny = %0.3f\nz = %0.3f\n", x1, y1, z1);

   
    return 0;
}