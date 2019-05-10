#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
 int n,i;
 float a[100],sum,variance=0,mean,sd;
 float *ptr;
 clrscr();
 printf("\n Enter the no of elements:");
 scanf("%d",&n);
 printf("\n Enter %d elements",n);
 for(i=0;i<n;i++)
 scanf("%f",&a[i]);
 ptr=a;
 for(i=0;i<n;i++)
 {
  sum=sum+(*ptr);
  ptr++;
 }
 mean=sum/n;
 ptr=a;
 for(i=0;i<n;i++)
 {
  variance=variance+pow((*ptr-mean),2);
  ptr++;
 }
 variance=variance/n;
 sd=sqrt(variance);
 printf("Sum=%f\n mean=%f\n sd=%f\n",sum,mean,sd);
 getch();
}