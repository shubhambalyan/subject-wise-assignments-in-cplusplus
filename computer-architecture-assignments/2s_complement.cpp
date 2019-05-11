// Program to find 2's complement of a binary number

#include<stdio.h>
#include<conio.h>
#include<string.h> 
void complement (char *a);
int main()
{
 char a[16];
 int i;
 printf("Enter the binary number: ");
 gets(a);
 complement(a);
 getch();
 return 0;
}

void complement (char *a)
{
 int l, i, c=0;
 char b[16];
 l=strlen(a);
 for (i=l-1; i>=0; i--)
 {
         if (a[i]=='0')
            b[i]='1';
         else
            b[i]='0';
 }
 for(i=l-1; i>=0; i--)
 {
         if(i==l-1)
         {
              if (b[i]=='0')
                 b[i]='1';
              else
              {
                 b[i]='0';
                 c=1;
              }
         }
         else
         {
              if(c==1 && b[i]=='0')
              {
                   b[i]='1';
                   c=0 ;
              }
              else if (c==1 && b[i]=='1')
              {
                   b[i]='0';
                   c=1;
              }
         }
  }
b[l]='\0';
delay(200);
printf("The 2's complement is %s", b);
}
