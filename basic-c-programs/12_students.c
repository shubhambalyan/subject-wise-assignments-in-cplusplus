#include<stdio.h>
#include<conio.h>
struct student
{char roll[10];
char name[20];
int marks;
char grade[5];
};
void main()
{
struct student s[100];
int found=0, n,i;int choice=1;char key[100];
clrscr();
printf("Enter the number of students");
scanf("%d",&n);
printf("Enter the information of %d student\n",n);
for(i=0;i<n;i++)
{
printf("enter the details of student %d\n",i+1);
printf("enter the roll number\n");
scanf("%s",s[i].roll);
printf("enter the name\n");
scanf("%s",s[i].name);
printf("enter the marks\n");
scanf("%d",&s[i].marks);
printf("enter the grade\n");
scanf("%s",s[i].grade);
printf("\n");
}
printf("Displaying information of student\n\n");
printf("\nroll \tName \tMarks \tgrade\n");
for(i=0;i<n;i++)
{
printf("%s\t",s[i].roll);
printf("%s\t",s[i].name);
printf("%d\t",s[i].marks);
printf("%s\t",s[i].grade);
printf("\n");
}
while(choice)
	{
	printf("\nenter the name of student to display marks:\n");
	scanf("%s",key);
	for(i=0;i<n;i++)
		{
		if(strcmp(key,s[i].name)==0)
			{
			found=1;
			printf("\nMarks of %s student is %d",s[i].name,s[i].marks);
			}
		}

 if(found==0)
 {
 printf("no record found of%s student",s[i].name);
 }
 found=0;
 printf("\n\n press 0 to exit and 1 to continue\n");
 scanf("%d",&choice);
 getch();
 //return 0;
}
}