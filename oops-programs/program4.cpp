/* Create a class ID_card that maintains the details in an ID card. Perform insert, update,
delete and display operation through functions that takes input through reference
parameter. */

 #include<iostream>
 using namespace std;
 #include<conio.h>
 #include<stdio.h>
 class ID_card
 {
       char reg_no[10];
       char name[25];
       char branch[10];
     public:
       void insert();
       void update(ID_card c1[], int &num);
       int delete_record(ID_card c2[], int &num);
       void display();
 };
 
 void ID_card::insert()
 {
      cout<<"\nEnter the Reg no.: ";
      cin>>reg_no;
      cout<<"\nEnter the Name: ";
      cin>>name;
      cout<<"\nEnter the Branch: ";
      cin>>branch;
 }
 
 void ID_card::display()
 {
      cout<<"\nReg no.: ";
      cout<<reg_no;
      cout<<"\nName: ";
      cout<<name;
      cout<<"\nBranch: ";
      cout<<branch;
 }
 
 void ID_card::update(ID_card c2[], int &num)
 {
      int choice,i,flag=0;
      char reg_no2[10];
      cout<<"\nEnter the Reg no. of the student whose record do you want to update: ";
      cin>>reg_no2;
      for(i=0;i<num;i++)
          {
                   if(strcmp(c2[i].reg_no,reg_no2)==0)
                     {cout<<"\nRecord Exists"; flag++;
                          break;}
          }
      if(flag==0)
        { cout<<"\nNo Such Record..."; getch(); exit(0); }
      cout<<"\nMenu for Updating...";
      cout<<"\n1.Reg no. \n2.Name \n3.Branch\n";
      cout<<"\nWhat would you like to update(select the option): ";
      cin>>choice;
      switch(choice)
      {
                    case 1: cout<<"\nEnter the new registration no.: ";
                            cin>>reg_no;
                            strcpy(c2[i].reg_no,reg_no);
                            cout<<"\nReg no. updated...";
                            break;
                    
                    case 2: cout<<"\nEnter the new name: ";
                            cin>>name;
                            strcpy(c2[i].name,name);
                            cout<<"\nName updated...";
                            break;
                            
                    case 3: cout<<"\nEnter the new Branch: ";
                            cin>>branch;
                            strcpy(c2[i].branch,branch);
                            cout<<"\nBranch updated...";
                            break;
                    
                    default: cout<<"\nNo such option...";
                             break;
      }
 }     
      
 int ID_card::delete_record(ID_card c1[], int &num)
 {
      int flag=0,i,j;
      char reg_no1[10];
      cout<<"\nEnter the Reg no. of the student whose record do you want to delete: ";
      cin>>reg_no1;
      for(i=0;i<num;i++)
          {
                   if(strcmp(c1[i].reg_no,reg_no1)==0)
                     {
                          cout<<"\nRecord Exists"<<" and deleted";
                          flag++;
                          for(j=i;j<num-1;j++)
                          {
                             strcpy(c1[j].reg_no,c1[j+1].reg_no);
                             strcpy(c1[j].name,c1[j+1].name);
                             strcpy(c1[j].branch,c1[j+1].branch);
                             }
                             
                             num-=1;                         
                     }
                 
          }
      if(flag==0)
        { cout<<"\nNo Such Record..."; getch(); exit(0); }
        return num;
 }    
 
 int main()
 {
     ID_card c[25];
     int num,choice;
     char ch='y';
     cout<<"\nEnter the number of students in the class: ";
     cin>>num;
     for(int i=0;i<num;i++)
        c[i].insert();
     do
     {
     cout<<"\nSelect any of the following fields(if you want to) :";
     cout<<"\n1.Update \n2.Delete\n";
     cout<<"\nEnter your choice: ";
     cin>>choice;
     switch(choice)
     {
                   case 1: c[10].update(c,num);
                           break;
                   case 2: num=c[10].delete_record(c,num);    //the calling object will also experience change
                           break;                             //ex:- c[0].upate(c,num).......will reflect change in c[0] also along with
                                                                  //the one you want say c[4];
                   default: cout<<"\nNO"; break;
     }
     cout<<"\nDo you wish to continue: ";
     cin>>ch;
     }while((ch=='y')||(ch=='Y'));
     cout<<"\nThe final Data is as follows: ";
     for(int i=0;i<num;i++)
        c[i].display();
        
     getch();
     return 0;
}
     
