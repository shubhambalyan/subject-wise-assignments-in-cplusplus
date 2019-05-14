/* Create a class telephone_directory (name, occupation, phone, address) and an
virtual function search (), that searches the object contents in a linear fashion. Extend
the class in a specific class called doctor (qualification, clinic, visiting time) and
override the virtual function such that it searches using binary search. Also create
another class lawyer (qualification, civil/criminal, cases attended, contact_no,
office_address) that extends the telephone_directory such that it wont override the
virtual function. Search for a doctor and a lawyer by taking the option from the user. */

 #include<iostream>
 using namespace std;
 #include<conio.h>
 #include<stdio.h>
 #include<graphics.h>
 int i=-1,j=-1;
 
 class tele_directory
 {
    protected:
       char name[20],occupation[20],address[50];
       float phone;
    public:       
       void accept()
       {
            cout<<"\nName: "; fflush(stdin); gets(name);
            cout<<"\nOccupation: "; fflush(stdin); gets(occupation);
            cout<<"\nAddress: "; fflush(stdin); gets(address);
            cout<<"\nPhone no.: "; cin>>phone;
            }
       void display()
       {
            cout<<"\nName: "; puts(name);
            cout<<"\nOccupation: "; puts(occupation);
            cout<<"\nAddress: "; puts(address);
            cout<<"\nPhone no.: "<<phone;
            }
       virtual int search(float phone_no);

       
 };

 class doctor: public tele_directory
 {
       char clinic[20];
       char time[20];
       char qual[20];
    public:
       void accept()
       {
            tele_directory::accept();
            cout<<"\nQualification: "; cin>>qual;
            cout<<"\nClinic Name: "; fflush(stdin); gets(name);
            cout<<"\nTimings: "; cin>>time;
            }
       void display()
       {
            tele_directory::display();
            cout<<"\nQualification: "<<qual;
            cout<<"\nClinic Name: "; puts(name);
            cout<<"\nTimings: "<<time;
            }       
       int search(float phone_no);

 }d[10];

 int tele_directory::search(float phone_no)
        {               
               for(int k=0;k<=i;k++)
               {
                       if(d[k].phone==phone_no){
                         cout<<"\nThe Record Exists...";
                         d[k].display();
                         return k;
                         }
               }
            return -1;
        }
 
 int doctor:: search(float phone_no)
       {
            int low=0,high=i,mid;            
            while(low<=high)
            {
               mid=(low+high)/2;
               if(d[mid].phone==phone_no){
                                          cout<<"\nRecord Exists...";
                                          d[mid].display();   return 1;
                                          }
               else if(phone_no<d[mid].phone)
                      high=mid-1;
               else
                      low=mid+1;
           }
           return -1;
       } 
 
 class lawyer: public tele_directory
 {
       int cases;
       char type[20];
       char qual[20];
    public:
       void accept()
       {
            tele_directory::accept();
            cout<<"\nQualification: "; cin>>qual;
            cout<<"\nType(Criminal/Civil): "; fflush(stdin); gets(type);
            cout<<"\nCases Attended: "; cin>>cases;
            }
       void display()
       {
            tele_directory::display();
            cout<<"\nQualification: "<<qual;
            cout<<"\nType: "; puts(type);
            cout<<"\nCases Attended: "<<cases;
            }
       void search_lawyer(float phone_no);
               
 }l[10];
       
  void lawyer::search_lawyer(float phone_no){
               int flag=0;               
               for(int k=0;k<=j;k++)
               {
                       if(l[k].phone==phone_no){
                         cout<<"\nThe Record Exists...";
                         l[k].display();
                         flag=1;
                         }
                 }
                 if(flag==0)
                    cout<<"\nNo such record...";
                }
       
  int main()
  {
        textbackground(LIGHTBLUE);
		textcolor(GREEN);
      char ch='y';
      cout<<"\nEnter the Doctor Records: ";
      while(ch=='y')
      {
            i++;
            d[i].accept();
            cout<<"\nEnter more records(y/n): ";
            cin>>ch;
      }
      ch='y';
      cout<<"\nEnter the Lawyer Records: ";
      while(ch=='y')
      {
            j++;
            l[j].accept();
            cout<<"\nEnter more records(y/n): ";
            cin>>ch;
      }
      
      cout<<"\nSearching Operation.....";
      int choice,temp;
      float phone_no;
      do
      {
          cout<<"\nSelect--- \n1.Doctor\n2.Lawyer\n3.Exit";
          cout<<"\nChoice: ";
          cin>>choice;
          switch(choice)
          {
                        case 1: cout<<"\nEnter the phone no. of the doctor to be searched: ";
                                cin>>phone_no;
                                temp=d[10].search(phone_no);
                                if(temp==-1)
                                   cout<<"\nRecord not found...";
                                break;
                        case 2: cout<<"\nEnter the phone no. of the lawyer to be searched: ";
                                cin>>phone_no;
                                l[10].search_lawyer(phone_no);
                                break;
                        case 3: break;
          }
       }while(choice!=3);
       getch();
       return 0;
 }
