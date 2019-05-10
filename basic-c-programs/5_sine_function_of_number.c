#include<stdio.h>
#include<math.h>
int fact(int n);
void main()
{
 float term=1.0,val,rad,x;
 int i,neg=1,n;
 clrscr();
 printf("Enter the degree of x\n");
 scanf("%f",&x);
 rad=(3.142857/180)*x;
 val=rad;
 for(i=3;i<=13;i=i+2)
 {
  neg=neg*(-1);
  term=(pow(rad,i)/fact(i))*neg;
  val=val+term;
 }
   printf("\n sin(%f) computed by program is %f",x,val);
   printf("\n sin(%f) computed by buildin function is %f",x,sin(rad));
   getch();
}

int fact(int n)
   {
    int fact1=1,i;
    for(i=1;i<=n;i++)
    {
     fact1=fact1*i;
    }
    return fact1;
}
