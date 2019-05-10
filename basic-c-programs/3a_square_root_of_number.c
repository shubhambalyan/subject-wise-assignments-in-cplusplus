#include<stdio.h>
#include<conio.h>
void main()
{
 float N,sqrt,temp;
 clrscr();
 printf("Enter the value of N");
 scanf("%f",&N);
 sqrt=N/2;
 temp=0;
 while(sqrt!=temp)
 {
  temp=sqrt;
  sqrt=((N/sqrt)+sqrt)/2;
 }
  printf("Square root=%f",sqrt);
  getch();
}