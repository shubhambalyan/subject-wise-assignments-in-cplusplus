/* Create a class that stores the details about a room in a hotel (private: room no,
type, cost). Create subclasses like Lounge(no.of people it can accommodate, A/C
type(centralized/window), food preference, recreational facilities (as a string array)) and
deluxe room(A/C or non A/C, single/double bedded). Create a class that maintains the
customer details (name, age, address, phoneno). Allow booking of the room by the
customer after checking the status of its availability. Overload the booking function such
that it can book a either a lounge or deluxe room for a customer.*/

 #include<iostream>
 using namespace std;
 #include<conio.h>
 #include<stdio.h>
 int l=0,d=5; 
 class room
 {
       int room_no;
       char type[10];
       float cost;
    public:
       void accept()
       {
            cout<<"\nRoom no.: "; cin>>room_no;
            cout<<"\nType(Lounge/Deluxe): "; fflush(stdin); gets(type);
            cout<<"\nCost: "; cin>>cost;
       }
       void display()
       {
            cout<<"\nRoom no.: "<<room_no;
            cout<<"\nType(Lounge/Deluxe): "; puts(type);
            cout<<"\nCost: "<<cost;
       }
 };
 
 class Lounge: public room
 {
       int no_of_people;
       char AC_type[20];
       char food[30];
       char facilities[5][30];
    public:
       void accept_lounge()
       {
            cout<<"\nAccomodation(no. of people): "; cin>>no_of_people;
            cout<<"\nAC type(Centralized/Window): "; fflush(stdin); gets(AC_type);
            cout<<"\nFood Preference: "; fflush(stdin); gets(food);
            cout<<"\nRecreational Facilities(max. of 3): ";
            for(int i=0;i<3;i++)
            {
                    fflush(stdin);
                    gets(facilities[i]);
            }
        }
       void display_lounge()
       {
            cout<<"\nAccomodation(no. of people): "<<no_of_people;
            cout<<"\nAC type(Centralized/Window): "; puts(AC_type);
            cout<<"\nFood Preference: "; puts(food);
            cout<<"\nRecreational Facilities: ";
            for(int i=0;i<3;i++)
                    puts(facilities[i]);
        }
 }lounge[10];
 
 class Deluxe: public room
 {
       char ac_type[10];
       char bed_type[10];
    public:
       void accept_deluxe()
       {
            cout<<"\nAC type(AC/Non-AC): "; fflush(stdin); gets(ac_type);
            cout<<"\nBed type(Single/Double): "; fflush(stdin); gets(bed_type);
       }
       void display_deluxe()
       {
            cout<<"\nAC type: "; puts(ac_type);
            cout<<"\nBed type: "; puts(bed_type);
       }
 }deluxe[10];
 
 class customer
 {
       char name[30];
       int age;
       char address[50];
       double phone;
    public:
       void accept_customer()
       {
            cout<<"\nName: "; fflush(stdin); gets(name);
            cout<<"\nAge: "; cin>>age;
            cout<<"\nAddress: "; fflush(stdin); gets(address);
            cout<<"\nPhone no.: "; cin>>phone;
       }
       void display_customer()
       {
            cout<<"\nName: "; puts(name);
            cout<<"\nAge: "<<age;
            cout<<"\nAddress: "; puts(address);
            cout<<"\nPhone no.: "<<phone;
       }
 }cust[10];
 
 void booking(double num)
 {
      if(l==num)
         cout<<"\nRooms not Available...";
      else
         {
               lounge[l].accept();
               lounge[l].accept_lounge();
               cust[l].accept_customer();
               cout<<"\nLounge Booked";
               ++l;
          }
  }
 
 void booking(int num)
 {
      if(d==num)
         cout<<"\nRooms not Available...";
      else
         {
               deluxe[d].accept();
               deluxe[d].accept_deluxe();
               cust[d].accept_customer();
               cout<<"\nDeluxe Room Booked";
               ++d;
          }
  }
   
 int main()
 {
     int choice;
     cout<<"\t\t\t***** RADISSON BLUE *****";
     do
     {
         cout<<"\nBooking Menu--->\n1.Lounge\n2.Deluxe\n3.Exit";
         cout<<"\nChoice: ";
         cin>>choice;
         switch(choice)
         {
                       case 1: booking(5.0);
                               break;
                       case 2: booking(10);
                               break;
                       case 3: break;
         }
     }while(choice!=3);
     do
     {
          cout<<"\nDisplaying Menu--->\n1.Lounge\n2.Deluxe\n3.Exit";
          cout<<"\nChoice: ";
          cin>>choice;
          switch(choice)
           { 
                       case 1: for(int i=0;i<l;i++)
                               {
                                     lounge[i].display();
                                     lounge[i].display_lounge();
                                     cust[i].display_customer();
                               }  
                               break;
                       case 2: for(int i=5;i<d;i++)
                               {
                                     deluxe[i].display();
                                     deluxe[i].display_deluxe();
                                     cust[i].display_customer();
                               } 
                               break;
                       case 3: exit(0);
           }
           }while(choice!=3);
     getch();
     return 0;
 }
