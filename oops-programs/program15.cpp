/* Create a class employee that maintains the details like empid, years of exp,
address, phone). Create separate class for type of skills the employee possesses like
carpentry (what type of wood, years, type of creations, tools used), masonry ( type of
constructions, years), Driving(license no, years of exp, types of vehicles). Make the
employee class to inherit the three classes and have the details that are relevant for the
employee. Have constructors to initialize all the classes and maintain the status in
employee according to the skills(111- means have all skills). If a skill status is 0, then
have the default values initialized with constructor. */

 #include<iostream>
 using namespace std;
 #include<conio.h>
 #include<stdio.h>
 
 class carpentry
 {
       char type[20];
       char creation[40];
       char tool[20];
    public:
       carpentry(char type[]=" ",char creation[]=" ",char tool[]=" ")
       {
            strcpy(this->type,type);
            strcpy(this->creation,creation);
            strcpy(this->tool,tool);
       }
       void display()
       {
            cout<<"\n\nCARPENTRY ---> ";
            cout<<"\nType of Wood: "; puts(type);
            cout<<"\nType of creation: "; puts(creation);
            cout<<"\nTool used: "; puts(tool);
       }
 };
 
 class masonry
 {
       char type[30];
    public:
       masonry(char type[]=" ")
       {
             strcpy(this->type,type);
       }
       void display() {
            cout<<"\n\nMASONRY ---> ";
            cout<<"\nType of Construction: "; puts(type);
            }
 };
 
 class driving
 {
       int license;
       char type[40];
    public:
       driving(int license=0,char type[]=" ")
       {
              strcpy(this->type,type);
              this->license=license;
       }
       void display()
       {
            cout<<"\n\nDRIVING ---> ";
            cout<<"\nLicense no.: "<<license;
            cout<<"\nType of Vehicle: "; puts(type);
       }
 };              
 
 class employee: public carpentry, public masonry, public driving
 {
       int empID;
       int years;
       char address[50];
       double phone;
    public:
       employee(int empID=0,int years=0,char address[]=" ",double phone=0.0,char type_c[]=" ",
                char creation[]=" ",char tool[]=" ",char type_m[]=" ",int license=0,char type_d[]=" ")
                :carpentry(type_c,creation,tool),masonry(type_m),driving(license,type_d)
                {
                        this->empID=empID;
                        this->years=years;
                        strcpy(this->address,address);
                        this->phone=phone;
                }
       void display();
 };
 
 void employee::display()
 {
      cout<<"\nEmp. ID:"<<empID;
      cout<<"\nYears of Experience: "<<years;
      cout<<"\nAddress: "; puts(address);
      cout<<"\nPhone no.: "<<phone;
      carpentry::display();
      masonry::display();
      driving::display();
 }
 
 int main()
 {
      int skill1,skill2,skill3;
      cout<<"\nEnter the Skills of the Employee( 1 for YES/ 0 for NO): ";
      cout<<"\nCarpentry: "; cin>>skill1;
      cout<<"\nMasonry: "; cin>>skill2;
      cout<<"\nDriving: "; cin>>skill3;
      cout<<"\nThe Details are: \n";
      if(skill1==0&&skill2==0&&skill3==0)
         { employee e(111,5,"New Delhi",99716);  e.display(); }
      else if(skill1==0&&skill2==0&&skill3==1)
         { employee e(111,5,"New Delhi",99716,"","","","",1234,"Car"); e.display();}
      else if(skill1==0&&skill2==1&&skill3==0)
         { employee e(111,5,"New Delhi",99716,"","","","Dry Set"); e.display();}
      else if(skill1==0&&skill2==1&&skill3==1)
         { employee e(111,5,"New Delhi",99716,"","","","Dry Set",1234,"Car"); e.display();}
      else if(skill1==1&&skill2==0&&skill3==0)
         { employee e(111,5,"New Delhi",99716,"Oak","Furniture","Chisel"); e.display();} 
      else if(skill1==1&&skill2==0&&skill3==1)
         { employee e(111,5,"New Delhi",99716,"Oak","Furniture","Chisel","",1234,"Car"); e.display(); }
      else if(skill1==1&&skill2==1&&skill3==0)
         { employee e(111,5,"New Delhi",99716,"Oak","Furniture","Chisel","Dry Set"); e.display();} 
      else if(skill1==1&&skill2==1&&skill3==1)
         { employee e(111,5,"New Delhi",99716,"Oak","Furniture","Chisel","Dry Set",1234,"Car"); e.display();}
      else
          cout<<"\nWrong Status...";
      getch();
      return 0;
}
