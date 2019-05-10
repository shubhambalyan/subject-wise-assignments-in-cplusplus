#include<stdio.h>
#include<conio.h>
void main()
{
 int year;
 clrscr();
 printf("Enter the year\n");
 scanf("%d",&year);
 if(year%4==0&&year%100!=0)
 {
  printf("The %d is a leap year");
 }
 else if(year%400==0)
 {
  printf("The %d is a century leap year");
 }
 else
 {
  printf("The %d is not a leap year");
 }
 getch();
}