#include<stdio.h>
#include <string.h>
#include<conio.h>
char x[32];
char y[32];
char z[32];
int a;
int carry=0;
main()
{
	printf("Please input the first binary number.\n");
	scanf("%s", x);
	printf("Please input the second binary number.\n");
	scanf("%s", y);
	for(a=0;a<=31;a++)
	{
		if (x[a]=='0' && y[a]=='0' && carry==0)
		{
			z[a]='0';
			carry=0;
		}
		if (x[a]=='1' && y[a]=='0' && carry==0)
		{
			z[a]='1';
			carry=0;
		}
		if (x[a]=='0' && y[a]=='1' && carry==0)
		{
			z[a]='1';
			carry=0;
		}
		if (x[a]=='1' && y[a]=='1' && carry==0)
		{
			z[a]='0';
			carry=1;
		}
		if (x[a]=='1' && y[a]=='1' && carry==1)
		{
			z[a]='1';
			carry=1;
		}
		if (x[a]=='0' && y[a]=='0' && carry==1)
		{
			z[a]='1';
			carry=0;
		}
		if (x[a]=='0' && y[a]=='1' && carry==1)
		{
			z[a]='0';
			carry=1;
		}
		if (x[a]=='1' && y[a]=='0' && carry==1)
		{
			z[a]='0';
			carry=1;
		}
	}
	printf("\nThe answer is ");
	for(a=31;a>=0;a--)
		printf("%c", z[a]);
	getch();
}
