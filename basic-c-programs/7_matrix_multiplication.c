#include<stdio.h>
#include<conio.h>
void main()
{
 int m,n,p,q,i,j,k,a[10][10],b[10][10],c[10][10],sum;
 clrscr();
 printf("Enter the size of matrix a\n");
 scanf("%d %d",&m,&n);
 printf("Enter the size of matrix b\n");
 scanf("%d %d",&p,&q);
 if(n!=p)
 {
  printf("Multiplication is not possible\n");
  getch();
  exit();
 }
 printf("Enter the elements of matrix a\n");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  scanf("%d",&a[i][j]);
 }
 printf("The matrix a is\n");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   printf("%d\t",a[i][j]);
  }
  printf("\n");
 }
 printf("Enter the elements of matrix b\n");
 for(i=0;i<p;i++)
 {
  for(j=0;j<q;j++)
  scanf("%d",&b[i][j]);
 }
 printf("The matrix b is\n");
 for(i=0;i<p;i++)
 {
  for(j=0;j<q;j++)
  {
   printf("%d\t",b[i][j]);
  }
  printf("\n");
 }
 for(i=0;i<m;i++)
 {
  for(j=0;j<q;j++)
  {
   sum=0;
   for(k=0;k<n;k++)
   {
    sum=sum+a[i][k]*b[k][j];
   }
   c[i][j]=sum;
  }
 }
  printf("The resultant matrix c is\n");
  for(i=0;i<m;i++)
  {
   for (j=0;j<q;j++)
   {
    printf("%d\t",c[i][j]);
   }
   printf("\n");
  }
  getch();
}