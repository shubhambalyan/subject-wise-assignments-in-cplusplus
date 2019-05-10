#include<stdio.h>
#include<conio.h>
void main()
{
 int rem,rev=0,num,temp;
 clrscr();
 printf("Enter any number");
 scanf("%d",&num);
 temp=num;
 while(num!=0)
 {
  rem=num%10;
  rev=rev*10+rem;
  num=num/10;
 }
 printf("Reversed number=%d",rev);
 if(temp==rev)
 printf("It is a palindrome");
 else
 printf("It is not a palindrome");
 getch();
}