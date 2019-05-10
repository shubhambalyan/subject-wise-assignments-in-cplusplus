#include<stdio.h>
#include<conio.h>
void main()
{
 char str[100];
 int ca=0,ce=0,ci=0,cc=0,co=0,cu=0;
 int i=0;
 clrscr();
 printf("Enter a string statement\n");
 gets(str);
 printf("The entered string is %s\n",str);
 while(str[i]!='\0')
 {
  switch(str[i])
  {
   case 'a':
   case 'A':ca++;break;
   case 'e':
   case 'E':ce++;break;
   case 'i':
   case 'I':ci++;break;
   case 'o':
   case 'O':co++;break;
   case 'u':
   case 'U':cu++;break;
   default:if(str[i]!='\0')
   cc++;
  }i++;
 }
 printf("Frequency of vowels\n");
 printf("a=%d\n",ca);
 printf("e=%d\n",ce);
 printf("i=%d\n",ci);
 printf("o=%d\n",co);
 printf("u=%d\n",cu);
 printf("default=%d\n",cc);
 getch();
}
