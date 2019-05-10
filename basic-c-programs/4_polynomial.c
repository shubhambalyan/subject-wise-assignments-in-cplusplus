#include<stdio.h>
#include<conio.h>
void main()
{
 int i,n;
 int a[10],res=0,x;
 clrscr();
 printf("enter the degree of polynomial\n");
 scanf("%d",&n);
 printf("enter the co-efficient\n");
 for(i=n;i>=0;i--)
 {
  scanf("%d",&a[i]);
 }
  printf("enter the value of x\n");
  scanf("%d",&x);
  res=a[n]*x;
  for(i=n-1;i>0;i--)
  {
   res=(res+a[i])*x;
  }
  res=res+a[0];
  printf("result=%d\n",res);
  getch();
}