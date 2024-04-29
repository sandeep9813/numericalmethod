 #include<stdio.h>
#include<math.h>

 
#define f1(x,y,z)  (95-11*y+4*z)/83
#define f2(x,y,z)  (104-7*x-13*z)/52
#define f3(x,y,z)  (71-3*x+8*y)/29

 
int main()
{
    float x0=0, y0=0, z0=0, x1, y1, z1;
    int count=1;

    printf("Count\tx\ty\tz\n");
    do
    {
   
        x1 = f1(x0,y0,z0);
        y1 = f2(x0,y0,z0);
        z1 = f3(x0,y0,z0);
        printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);

        count++;

         
        x0 = x1;
        y0 = y1;
        z0 = z1;
    }while(count <= 5);

    printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);

    return 0;
}
