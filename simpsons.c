  
#include<stdio.h>
 
#include<math.h>

 
 float f(float x)
 {
    return pow(x,3)+1;
 }

int main()
{
 float a,b, sum=0.0, h, k;
 int i, n;
  
 
 printf("Enter lower limit of integration: ");
 scanf("%f", &a);
 printf("Enter upper limit of integration: ");
 scanf("%f", &b);
 printf("Enter number of sub intervals: ");
 scanf("%d", &n);

  
 h = (b - a)/n;

 
 sum= f(a) + f(b);
 for(i=1; i<=n-1; i++)
 {
   if(i%2==0)
   {
 sum+=2*f(a+i*h);
   }
  else
  sum+=4*f(a+i*h);
 }
 sum= sum * h/3;
 printf("\nRequired value of integration is: %f",sum);
}
   