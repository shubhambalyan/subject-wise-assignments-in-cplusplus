/*Write a c++ program that maintains the date in (day/mon/year) format and
overload the ++ & -- operator to view previous or next date from today’s date. Ensure
that the day won’t exceed 30/31 for certain months.*/

 #include<iostream>
 using namespace std;
 #include<conio.h>
 
 class calendar
 {
       int day;
       int month;
       int year;
     public: 
       void accept();
       void display();
       void operator++();
       void operator--();
 };
 
 void calendar::accept()
 {
      a:
      cout<<"\nDay: "; cin>>day;
      if(day>31)
      {
         cout<<"\nInvalid Date!!!";
         goto a;
      }
      b:
      cout<<"\nMonth: "; cin>>month;
      if(month>12)
       {
         cout<<"\nInvalid Month!!!";
         goto b;
       }
      cout<<"\nYear: "; cin>>year;
 }
 
 void calendar::display()
 {
      cout<<"\nThe date is: "<<day<<"/"<<month<<"/"<<year;
 }
 
 void calendar::operator++()
 {
      switch(month)
      {
             case 1:
             case 3:
             case 5:
             case 7:
             case 8:
             case 10:  if(day==31)
                       {
                            day=1;
                            month++;
                       }
                       else
                            day++;
                       break;
             case 12:  if(day==31)
                       {
                            day=1;
                            month=1;
                            year++;
                       }
                       else
                            day++;
                       break;
             case 4:
             case 6:
             case 9:
             case 11: if(day==30)
                      {
                            day=1;
                            month++;
                      }
                      else
                            day++;
                      break;
             case 2: if((day==28)&&(year%4==0))
                        day++;
                     else if(day==29)
                      {
                          day=1;
                          month++;
                      }
                     else
                          day++;
                     break;
     }    
     display();                               
 }
 
 void calendar::operator--()
 {
      switch(month)
      {
             case 4:
             case 6:
             case 9:
             case 11: if(day==1)
                      {
                           day=31;
                           month--;
                      }
                      else
                           day--;
                      break;
             case 5:
             case 7:
             case 10:
             case 12: if(day==1)
                      {
                            day=30;
                            month--;
                      }
                      else
                            day--;
                      break;
             case 2:
             case 8: if(day==1)
                      {
                            day=31;
                            month--;
                      }
                      else
                            day--;
                      break;
             case 1: if(day==1)
                     {
                            day=31;
                            month=12;
                            year--;
                     }
                     else
                            day--;
                     break;
             case 3:  if((day==1)&&(year%4==0))
                      {
                            day=29;
                            month--;
                      }
                      else if((day==1)&&(year%4!=0))
                      {
                           day=28;
                           month--;
                      }
                      else
                           day--;
                      break;                 
        }    
     display();
 }
 
 int main() 
 {
     calendar c;
     int choice;
     do
     {
         cout<<"\nEnter the date: ";
         c.accept();
         c.display();
         cout<<"\n>>>>> MENU <<<<<";
         cout<<"\n1.Increement Date\n2.Decreement Date\n3.Exit";
         cout<<"\nChoice: ";
         cin>>choice;
         switch(choice)
         {
                       case 1: c.operator++();
                               break;
                               
                       case 2: c.operator--();
                               break;
         }
      }while(choice!=3);
      getch();
      return 0;
 }
