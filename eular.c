 #include<stdio.h>

 
float fun(float x, float y) {
    float f;
    f = x+y+x*y;  
    return f;
}

int main() {
    float x0, y0, h, xn, x, y, k;

   
    printf("\nEnter x0, y0, h, xn: ");
    scanf("%f%f%f%f", &x0, &y0, &h, &xn);

    x = x0;
    y = y0;

 
    printf("\n  x\t  y\n");

  
    while (x <= xn) {
 
        k = h * fun(x, y);

    
        y = y + k;

    
        x = x + h;

         
        printf("%0.3f\t%0.3f\n", x, y);
    }

    return 0;
}
