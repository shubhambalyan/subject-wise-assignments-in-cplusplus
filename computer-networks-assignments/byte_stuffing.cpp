#include<stdio.h>
#include<conio.h>
int main()
{
int i,j=0;
char str[100],str2[100],flag,esc;
printf("\nEnter the string: ");
gets(str);
printf("\nEnter the flag: ");
scanf("%c",&flag);
printf("\nEnter the stuffing bit: ");
fflush(stdin);
scanf("%c",&esc);
printf("\nByte stuffing\n");
str2[j]=flag;
j++;
for(i=0;str[i];i++)
{
   if(str[i]==flag)
   {
      str2[j]=esc;
      j++;
   }
   else if(str[i]==esc)
   {
      str2[j]=esc;
      j++;
   }
   str2[j]=str[i];
   j++;
}
str2[j]=flag;
j++;
str2[j]='\0';
puts(str2);
printf("\nByte Destuffing\n");
for(j=0;str2[j];j++)
{
   str2[0]='\0';
   if(str2[j]==esc&&(str2[j+1]==flag||str2[j+1]==esc))
   {
        printf("%c",str2[j+1]);
        j++;
   }
   else if(str2[j]==flag&&str2[j+1]=='\0')
   {
       goto end;
   }
   else
       printf("%c",str2[j]);
}
end:
getch();
return 0;
}
