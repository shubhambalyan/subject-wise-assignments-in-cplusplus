#include<stdio.h>
#include<conio.h>
int fact(int n);
void main()
{
 int r[100],n[100],result,i,num;
 clrscr();
 printf("\n computing ncr\n");
 printf("\n Enter the number of computations");
 scanf("%d",&num);
 printf("\n Enter %d different value of for n",num);
 for(i=0;i<num;i++)
 scanf("%d",&n[i]);
 printf("\n Enter %d different number of r",num);
 for(i=0;i<num;i++)
 scanf("%d",&r[i]);
 printf("\n\t n\t r\t ncr");
 for(i=0;i<num;i++)
 {
  if(n[i]==0)
  {
   printf("\n\t %d\t %d",n[i],r[i]);
   printf("\t please enter valid value for n");
  }
  else if(n[i]<r[i])
  {
   printf("\n\t %d\t %d",n[i],r[i]);
   printf("Please enter valid value for n&r");
  }
  else
  {
   result=fact(n[i])/(fact(n[i]-r[i])*fact(r[i]));
   printf("\n\t %d\t %d\t %d",n[i],r[i],result);
  }
 }
 getch();
}
 int fact(int n)
 {
  if(n==0)
  {
   return 1;
  }
  else
  {
   return(n*fact(n-1));
  }
 }