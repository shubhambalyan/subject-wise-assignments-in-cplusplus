#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 float a,b,c,d,x1,x2,rp,ip;
 clrscr();
 printf("Enter the coefficient");
 scanf("%f%f%f",&a,&b,&c);
 if(a*b*c==0)
 printf("Roots cannot be found");
 else
 {
  d=((b*b)-(4*a*c));
  if(d==0)
  {
   printf("Roots are equal");
   x1=(-b/(2*a));
   x2=(-b/(2*a));
   printf("root1=%f,root2=%f",x1,x2);
  }
  else if(d>0)
  {
   printf("Roots are real & distinct");
   x1=(-b+(sqrt(d))/(2*a));
   x2=(-b-(sqrt(d))/(2*a));
   printf("root1=%f,root2=%f",x1,x2);
  }
  else
  {
   printf("Roots are imaginary");
   x1=(-b/(2*a));
   x2=(sqrt(fabs(d)))/2*a;
   printf("root1=%f+i%f",x1,x2);
   printf("root2=%f-i%f",x1,x2);
  }
 }
 getch();
}