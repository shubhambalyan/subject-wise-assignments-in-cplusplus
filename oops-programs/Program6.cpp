/*Synthesize a C++ program that has two classes (one for employee and one for
student), have a separate class for address (with door no, street name, city, state) and
reuse address both for employee and student. Perform insert, delete and display
operations by taking choice of person (employee or student) from the user. Allow
user to have more than one address also. (c)*/

 #include<iostream>
 using namespace std;
 #include<conio.h>
 int num1=1,num2=1,a1=1,a2=1;
 
 class address;
 
 class employee
 {
       int ID;
       char name_emp[30];
       int age_emp;
    public:
       void input_emp(address a[]);
       void display_emp(address a[]);
       int delete_emp();
 }e[5];
 
 class student
 {
       char reg_no[10];
       char name_stud[30];
       int age_stud;
    public:
       void input_stud(address a[10]);
       void display_stud(address a[10]);
       int delete_stud();              
 }s[5];
 
 class address
 {
       int door_no;
       char street_name[20];
       char city[20];
       char state[20];
    public:
       friend class employee;
       friend class student;
 };
 
 void employee::input_emp(address a[10])
 {
      char ch;
      cout<<"\nID: ";
      cin>>ID;
      cout<<"\nName: ";     fflush(stdin);
      gets(name_emp);
      cout<<"\nAge: ";
      cin>>age_emp;
      do
      {
            cout<<"\nADDRESS:- ";
      cout<<"\nDoor no.: ";
      cin>>a[a1].door_no;
      cout<<"\nStreet name: ";    fflush(stdin);
      gets(a[a1].street_name);
      cout<<"\nCity: ";      fflush(stdin);
      gets(a[a1].city);
      cout<<"\nState: ";    fflush(stdin);
      gets(a[a1].state);
      a1++;
       cout<<"\nWant to enter another address for employee: ";
          cin>>ch;
      }while(ch=='y');
 }
 
 void employee::display_emp(address a[10])
 {
      cout<<"\nID: "<<ID;
      cout<<"\nName: "; puts(name_emp);
      cout<<"\nAge: "<<age_emp;
      cout<<"\nADDRESS:-";
      for(int i=1;i<a1;i++)
      {
              cout<<"\nDoor no.: "<<a[i].door_no;
      cout<<"\nStreet name: ";
      puts(a[i].street_name);
      cout<<"\nCity: ";
      puts(a[i].city);
      cout<<"\nState: ";
      puts(a[i].state);
      }
 }
 
 int employee::delete_emp()
 {
      int flag=0,i,j;
      int ID1;
      cout<<"\nEnter the ID no. of the employee whose record do you want to delete: ";
      cin>>ID1;
      for(i=1;i<=num1;i++)
          {
                   if(e[i].ID==ID1)
                     {
                          cout<<"\nRecord Exists and deleted...";
                          flag++;
                          for(j=i;j<=num1-1;j++)
                          {
                             e[j].ID=e[j+1].ID;
                             strcpy(e[j].name_emp,e[j+1].name_emp);
                             e[j].age_emp=e[j+1].age_emp;
                          }                             
                             num1-=1;                         
                     }                 
          }
      if(flag==0)
        { cout<<"\nNo Such Record..."; getch(); exit(0); }
        return num1;
 }
 
 void student::input_stud(address a[10])
 {
      char ch;
      cout<<"\nReg no.: ";
      cin>>reg_no;
      cout<<"\nName: ";   fflush(stdin);
      gets(name_stud);
      cout<<"\nAge: ";
      cin>>age_stud;
      do
      {
      cout<<"\nADDRESS:- ";
      cout<<"\nDoor no.: ";
      cin>>a[a2].door_no;
      cout<<"\nStreet name: ";    fflush(stdin);
      gets(a[a2].street_name);
      cout<<"\nCity: ";      fflush(stdin);
      gets(a[a2].city);
      cout<<"\nState: ";    fflush(stdin);
      gets(a[a2].state);
          a2++;
      cout<<"\nWant to enter another address for student: ";
      cin>>ch;
      }while(ch=='y');
 }
 
 void student::display_stud(address a[10])
 {
      cout<<"\nReg no.: "<<reg_no;
      cout<<"\nName: ";  puts(name_stud);
      cout<<"\nAge: "<<age_stud;
      cout<<"\nADDRESS:- ";
      for(int i=1;i<a2;i++)
      {
              cout<<"\nDoor no.: "<<a[i].door_no;
      cout<<"\nStreet name: ";
      puts(a[i].street_name);
      cout<<"\nCity: ";
      puts(a[i].city);
      cout<<"\nState: ";
      puts(a[i].state);
      }
 }
 
 int student::delete_stud()
 {
      int flag=0,i,j;
      char reg_no1[10];
      cout<<"\nEnter the Reg no. of the student whose record do you want to delete: ";
      cin>>reg_no1;
      for(i=1;i<=num2;i++)
          {
                   if(strcmp(s[i].reg_no,reg_no1)==0)
                     {
                          cout<<"\nRecord Exists and deleted...";
                          flag++;
                          for(j=i;j<=num2-1;j++)
                          {
                             strcpy(s[j].reg_no,s[j+1].reg_no);
                             strcpy(s[j].name_stud,s[j+1].name_stud);
                             s[j].age_stud=s[j+1].age_stud;
                          }                             
                             num2-=1;                         
                     }                 
          }
      if(flag==0)
        { cout<<"\nNo Such Record..."; getch(); exit(0); }
        return num2;
 }
 
 int main()
 {
     int choice;
     char ch;
     address a[10];
     do
  {
     cout<<"\n..........MENU..........";
     cout<<"\n1.Employee\n2.Student";
     cout<<"\nChoice: ";
     cin>>choice;
     switch(choice)
     {
                   case 1: do
                        {
                           cout<<"\n.....Menu for Employee.....";
                           cout<<"\n1.Insert Data\n2.Delete Data\n3.Display Records";
                           cout<<"\nChoice: ";
                           cin>>choice;
                           switch(choice)
                           {
                                         case 1: cout<<"\nEnter the details of the employee: ";
                                                 e[num1].input_emp(a);
                                                 num1++;  break;
                                         case 2: num1=e[0].delete_emp();
                                                 break;
                                         case 3: cout<<"\nThe details of employee are: ";
                                                 for(int i=1;i<num1;i++)
                                                     e[i].display_emp(a);
                                                 break;
                           }
                           cout<<"\nWish to continue: ";
                           cin>>ch;
                         }while(ch=='y');
                           break;
                           
                   case 2: do
                        { 
                           cout<<"\n.....Menu for Student.....";
                           cout<<"\n1.Insert Data\n2.Delete Data\n3.Display Records";
                           cout<<"\nChoice: ";
                           cin>>choice;
                           switch(choice)
                           {
                                         case 1: cout<<"\nEnter the details of the student: ";
                                                 s[num2].input_stud(a);
                                                 num2++;  break;
                                         case 2: num2=s[0].delete_stud();
                                                 break;
                                         case 3: cout<<"\nThe details of student are: ";
                                                 for(int i=1;i<num2;i++)
                                                     s[i].display_stud(a);
                                                 break;
                           }
                           cout<<"\nWish to continue: ";
                           cin>>ch;
                         }while(ch=='y');
                           break;
                   
                           
                   default: cout<<"\nNA...";   break;
      }
      cout<<"\nWish to continue for another type of person: ";
      cin>>ch;
    }while(ch=='y');
    getch();
    return 0;
}
