/*Create a C++ program that takes employee details like ID, first name, last name,
age and address. Create a class for student {name, course, regular/parttime, address}. Use
friend function to check that a student with same name and address can’t be a regular
student as well as an employee. (c)*/

 #include<iostream>
 using namespace std;
 #include<conio.h>
 #include<stdio.h>
 
 int num1=0,num2=0;
 
 class student;
 
 class employee
 {
       int ID;       
       int age;       
     public:
       char ename[15];
       char address1[80];
       void accept_emp();
       void display_emp();
       friend int check(employee e[],student s[]);
 };
 
 class student
 {
       char course[10];
     public:
       char sname[30];
       char address2[80];
       void accept_stud();
       void display_stud();
       void set_course();
       friend int check(employee e[],student s[]);
 };
 
 void employee::accept_emp()
{
	cout<<"\nID : ";
    cin>>ID;
	cout<<"\nName: ";
    cin>>ename;
	cout<<"\nAge: ";
    cin>>age;
	cout<<"\nAddress: ";
	fflush(stdin);
    gets(address1);
}

void employee::display_emp()
{
	cout<<"\nID: "<<ID;
	cout<<"\nName: "<<ename;
	cout<<"\nAge: "<<age;
	cout<<"\nAddress: ";
    puts(address1);
}

void student::accept_stud()
{
	cout<<"\nName: ";
    cin>>sname;
	cout<<"\nCourse(regular/parttime): ";
    cin>>course;
	cout<<"\nAddress: ";
	fflush(stdin);
    gets(address2);
}

void student::display_stud()
{
	cout<<"\nName: "<<sname;
	cout<<"\nCourse(regular/parttime): "<<course;
	cout<<"\nAddress: ";
    puts(address2);
}

void student::set_course()
{
     if(strcmp(course,"regular")==0)
        strcpy(course,"parttime");
}

int check(employee e[],student s[])
{
    int flag=0;
	for(int i=1;i<=num1;i++)
	    for(int j=1;j<=num2;j++)
		    if((strcmp(e[i].address1,s[j].address2)==0)&&(strcmp(e[i].ename,s[j].sname)==0))
		       return (++flag);
	return flag;   
}
 
int main()
{
    employee e[10];
    student s[10];
    int choice,flag=0;
    char ch;
    do
    {
         cout<<"\n>>>>>>>>>>MENU<<<<<<<<<<";
         cout<<"\n1.Employee Entry\n2.Student Entry\n3.Employee Display\n4.Student Display\n5.Exit";
         cout<<"\nEnter your choice: ";
         cin>>choice;
         switch(choice)
         {
                       case 1: num1++;
                               e[num1].accept_emp();
                               flag=check(e,s);
                               if(flag==1)
                                 {
                                          cout<<"\nRecord not Inserted...";
                                          num1--;
                                 }
                               else
                                          cout<<"\nNew Employee Record Inserted...";
                               break;
                                  
                       case 2: num2++;
                               s[num2].accept_stud();
                               flag=check(e,s);
                               if(flag==1)
                                  {
                                          s[num2].set_course();
                                          cout<<"\nNew Student Record Inserted...";
                                  }
                               else
                                  cout<<"\nNew Student Record Inserted...";
                               break;
                       
                       case 3: cout<<"\nDetails of employees: ";
                                for(int i=1;i<=num1;i++)
                                   e[i].display_emp();
                                break;
                       
                       case 4: cout<<"\nDetails of students: ";
                               for(int i=1;i<=num2;i++)
                                   s[i].display_stud();
                               break;
                               
                       case 5: exit(0);
                               break;
                       
                       default: cout<<"\nNo Such Option...";
          }
    cout<<"\nWant to continue: ";
    cin>>ch;
    }while((ch=='y')||(ch=='Y'));
    getch();
    return 0;
}
         
