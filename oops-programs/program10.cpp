/* Create a class teacher {teacher name, ID, department, subject currently handled} and
student class{student name, regno, subjects, teacher, marks(cae1,cae2,assignment), log}
such that the teacher class id made a friend of student class. Allow the teacher class to
update the student information like marks and also maintain an entry in the student class
log field everytime an updation takes place. This log should maintain the details like
teacher code, updated fields etc. */

 #include<iostream.h>
 #include<conio.h>
 #include<stdio.h>
 int c1=0,c2=0;
 class teacher
 {
       int ID;
       char tname[30];
       char dept[10];
       char current_subject[20];
     public:
       void accept();
       void display();
       void update(int);
 }t[10];
 
 class student
 {       
       char sname[30];
       int marks[3];
       char subject[3][30];
       char sub_teacher[3][30];    
    public:
           char reg_no[10];
           student()
      {
             marks[0]=marks[1]=marks[2]=0;
      }
      struct log
       {
             int code;
             char field[30];
             int num;
       }g[20];
       void accept();
       void display(int);
       friend class teacher;
 }s[10];
 
 void teacher::accept()
 {
      cout<<"\nTeacher ID: ";   cin>>ID;
      cout<<"\nName: ";   fflush(stdin);  gets(tname);
      cout<<"\nDept: ";   fflush(stdin);  gets(dept);
      cout<<"\nSubject: ";  fflush(stdin);  gets(current_subject);
 }
 
 void teacher::display()
 {
      cout<<"\nTeacher ID: "<<ID;
      cout<<"\nName: ";   puts(tname);
      cout<<"\nDept: ";   puts(dept);
      cout<<"\nSubject: ";  puts(current_subject);
 }
 
 void student::accept()
 {
      cout<<"\nReg no.: ";     cin>>reg_no;
      cout<<"\nName: ";  fflush(stdin);  gets(sname);
      for(int i=0;i<3;i++)
      {
              cout<<"\nSubject "<<i+1<<": ";   cin>>subject[i];
              cout<<"\nTeacher: ";   fflush(stdin);   gets(sub_teacher[i]);
              cout<<"\nMarks...."<<"CAE1: "; cin>>marks[0];
              cout<<"\tCAE2: "; cin>>marks[1];
              cout<<"\tAssignment: "; cin>>marks[2];
      }
 }
 
 void student::display(int num)
 {
      cout<<"\nReg no.: "<<reg_no;
      cout<<"\nName: ";  puts(sname);
      for(int i=0;i<3;i++)
      {
              cout<<"\nSubject "<<i+1<<": "<<subject[i];
              cout<<"\nTeacher: "; puts(sub_teacher[i]);
              cout<<"\nMarks.... "<<"CAE1: "<<marks[0];
              cout<<"\tCAE2: "<<marks[1];
              cout<<"\tAssignment: "<<marks[2];
      }
      //cout<<"\n>>> Marks Log <<<";
      //for(int i=0;i<
        // cout<<"\nTeacher's code: ";cout<<g[num].code;
         //cout<<"\nField: ";puts(g[num].field);
         //cout<<"\tMarks: "<<g[num].num;      
 }
      
 void teacher::update(int i)
 {
      int choice,flag=0;
      cout<<"\n...Update Information...\n";
      a:
      cout<<"Teacher's code: ";
      cin>>s[i].g[i].code;
      for(int j=0;j<c1;j++)
      if(s[i].g[i].code==t[j].ID)
        { cout<<"\nTeacher Exists..."; break; flag=j;}
      else
        goto a;
      
              cout<<"\nSelect the field: ";
              cout<<"\n1.CAE1\n2.CAE2\n3.Assignment.";
              cout<<"\nChoice: ";
              cin>>choice;
              switch(choice)
              {
                            case 1: cout<<"\nNew Marks: ";
                                    cin>>s[flag].g[i].num;
                                    s[flag].marks[0]=s[i].g[i].num;
                                    //strcpy(s[i].g[i].field,"CAE1"); 
                                    break;
                            case 2: cout<<"\nNew Marks: ";
                                    cin>>s[flag].g[i].num;
                                    s[flag].marks[1]=s[i].g[i].num;
                                    //strcpy(s[i].g[i].field,"CAE2");
                                    break;
                            case 3: cout<<"\nNew Marks: ";
                                    cin>>s[flag].g[i].num;
                                    s[flag].marks[2]=s[i].g[i].num;
                                    //strcpy(s[i].g[i].field,"Assignment");
                                    break;
                            default: cout<<"\nNo Such option...";
                                     break;
              }
 }
 
 int main()
 {
     int choice,flag=0;
     char ch,temp[10];
     
     do
     {
          cout<<"\n.....MENU.....";
          cout<<"\n1.Insert Teacher\n2.Insert Student\n3.Display Teacher\n4.Display Student\n5.Update Student";
          cout<<"\nChoice: ";
          cin>>choice;
          switch(choice)
          {
                        case 1: t[c1].accept();
                                c1++;
                                break;
                        case 2: s[c2].accept();
                                c2++;
                                break;
                        case 3: for(int i=0;i<c1;i++)
                                    t[i].display();
                                break;
                        case 4: for(int i=0;i<c2;i++)
                                    s[i].display(i);
                                break;
                        case 5: cout<<"\nEnter the reg no. to be updated...";
                                cin>>temp;
                                for(int i=0;i<c2;i++)
                                 {
                                        if(strcmp(temp,s[i].reg_no)==0)
                                           t[i].update(i);
                                        else
                                           flag++;
                                 }
                                 if(flag!=0)
                                   cout<<"\nRecord Not Found...";
                                 break;
                        default: cout<<"\nNo such option...";
                                 break;
           }
           cout<<"\nWish to continue: ";
           cin>>ch;
     }while(ch=='y');
  getch();
  return 0;
 }
