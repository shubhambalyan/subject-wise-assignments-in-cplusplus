#include<stdio.h>
#include<conio.h>
void main()
{
 int i=0,j=0;
 char str1[100],str2[100];
 clrscr();
 printf("Enter the word:");
 gets(str1);
 printf("Enter word is %s\n",str1);
 while(str1[i]!='\0')
 {
  str2[j]=str1[i];
  i++;
  j++;
 }
 str2[j]='\0';
 printf("Copied string is %s\n",str2);
 getch();
}