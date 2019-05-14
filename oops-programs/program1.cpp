/* Create a class that registers your details by taking reg.no, name, age and mail id.
Create a function that prevents duplicate entries of objects based on reg.no. */

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class student
{
      char reg_no[15];
      char name[25];
      int age;
      char email_id[30];
    public:       
       char*getreg_no()
       {
             return reg_no;
       }
       
       void input();
       void inputreg();
};

void student :: inputreg()
{
     cout<<"\nEnter the Registration no. : ";
     cin>>reg_no;
}

void student :: input()
{
     
     cout<<"\nEnter the Name: ";
     cin>>name;
     cout<<"\nEnter the age: ";
     cin>>age;
     cout<<"\nEnter the Email ID: ";
     cin>>email_id;
}


int duplicate(student s1[],int num)
{
     int j;
     for(j=0;j<num;j++)
     {
          if(strcmp(s1[num].getreg_no(),s1[j].getreg_no())==0)
            break;
     }
     return j;
}

int main()
{
    student s[10];
    int num,i,flag;
    cout<<"Enter the number of students in the class: ";
    cin>>num;
    for(i=0;i<num;i++)
    {
              s[i].inputreg();
              flag=duplicate(s,i);
              if(flag!=i)
                cout<<"\nDuplicate Record.....";
              else
                {
                    cout<<"\nNew Record.....";
                    s[i].input();
                }
    }
   
    getch();
    return 0;
}
