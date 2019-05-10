#include<stdio.h>
#include<conio.h>
void main()
{
 int a[10],i,j,n,temp;
 clrscr();
 printf("Enter the no of element\n");
 scanf("%d",&n);
 printf("Enter the element\n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 printf("The stored array\n");
 for(j=0;j<n;j++)
 printf("%d\t",a[j]);
 getch();
}