#include<stdio.h>
#include<conio.h>
int isprime(int num);
void main()
{
 int m,n,i;
 clrscr();
 printf("Enter the range of the number to print prime number");
 scanf("%d%d",&m,&n);
 printf("Prime number between given range are");
 for(i=m;i<n;i++)
 {
  if(isprime(i))
  {
   printf("%d\t",i);
  }
 }
 getch();

}
 int isprime(int num)
 {
  int flag=1,i;
  if(num==1)
  flag=0;
  else
  {
   for(i=2;i<num;i++)
   {
    if(num%i==0)
    {

     flag=0;
     break;
    }
   }
  }
  return flag;
 }