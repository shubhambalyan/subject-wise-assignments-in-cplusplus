#include<stdio.h>
#include<conio.h>
#include<windows.h>
int main()
{
int i,count=0;
char arr[30];
printf("Enter the message: ");
scanf("%s",arr); 
printf("\nBit Stuffing \n");
Sleep(2000);
printf("01111110"); 
for(i=0;arr[i]; i++)
{
    if(arr[i]=='1')
        count++;
    else
        count=0;
printf("%c",arr[i]);
if(count==5)
    {
        printf("0");
        count=0;
    }
}
printf("01111110");
count=0;
printf("\nBit Destuffing\n");
Sleep(2000);
for(i=0;arr[i];i++)
{
     if(arr[i]=='1')
        count++;
     else
        count=0;
  printf("%c",arr[i]);
  if(count==5)
   {
         printf("");
         count=0;
   }
}
getch();
return 0;
}
