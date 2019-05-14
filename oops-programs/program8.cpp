/*Create a savings_account class that maintains the details of customers like name,
phone number, accno, balance. Ensure that the variables are protected with proper
specifiers such that only the user’s personal details can be modified directly. Perform
deposit, withdrawal, statement print, and pin change operations by checking for
minimum balance and other conditions. Create a new account for the same user by
copying the basic details of the user using a copy constructor.*/

 #include<iostream.h>
 #include<conio.h>
 #include<stdio.h>
 
 class saving_account
 {       
       long int acc_no;
       float balance;
       char pin[];
       float deposit;
      float withdraw;       
    public:
       saving_account()
       {
            acc_no=0; balance=0; }
       saving_account(saving_account&copy)
       {
            strcpy(name,copy.name);
            strcpy(gender,copy.gender);
            phone=copy.phone;
            }
            
       char name[50];
       long int phone;
       char gender[1];
       struct statement
       {
             char type[15];
             float amount;
       }s[25];
       
       void input();
       void pin_change();
       int deposits(int r);
       int withdrawal(int r);
       void statement_print(int r);
       void print_personal();
 };
 
 saving_account a;
 void saving_account::input()
 {
      cout<<"\nEnter the Name: ";
      cin>>name;
      cout<<"\nEnter the phone no.: ";
      cin>>phone;
      cout<<"\nEnter the gender(M/F): ";
      cin>>gender;
      cout<<"\nEnter the account no.: ";
      cin>>acc_no;
      cout<<"\nEnter the balance: ";
      cin>>balance;
      cout<<"\nEnter the pin: ";
      for(int i=0;i<4;i++)
     {
         pin[i]=getch();
         printf("*");
     }
 }
 
 int saving_account::deposits(int r)
{
         
     cout<<"\nEnter the amount to be deposited: ";
     cin>>deposit;
     strcpy(s[r].type,"Deposit");
     s[r].amount=deposit;
     balance+=deposit;
     return ++r;
}

int saving_account::withdrawal(int r)
{
     cout<<"\nEnter the amount to be withdrawn: ";
     cin>>withdraw;
     strcpy(s[r].type,"Withdrawn");
     s[r].amount=withdraw;
     if(balance>withdraw)
       {
            cout<<"\nWithdrawal Possible.....";
            balance-=withdraw;
       }
     else
       {
       cout<<"\nWithdrawal not Possible.....";
       getch();
       exit(0);
       }
     return ++r;
}

void saving_account::statement_print(int r)
{
     int i;
     cout<<"\nAccount no. : ";
     cout<<acc_no;
     cout<<"\nThe statement print is as follows: \n";
     for(i=1;i<r;i++)
     {
                     cout<<i<<".";
                     cout<<s[i].type;
                     cout<<"\t"<<s[i].amount<<endl;
     }
     cout<<"\nThe Final balance is: ";
     cout<<balance;     
}
 
 void saving_account::pin_change()
 {
      char pin1[3];
      a:
      cout<<"\nEnter the old pin: ";
      cin>>pin1;
      if(strcmp(pin,pin1)==0)
      {
         cout<<"\nEnter the new pin: ";
         for(int i=0;i<4;i++)
          {
                 pin1[i]=getch();
                 printf("*");
          }         
         strcpy(pin,pin1);
         cout<<"\nPin changed...";
      }
      else
       {
         cout<<"\nWrong pin...";
         goto a;
       }
 }
 
 void saving_account::print_personal()
 {
      cout<<"\nName: "<<name<<"\nPhone no.: "<<phone<<"\nGender: "<<gender;
 }
 
 int main()
{
    a.input();
    int wish,p=1;
    char choice;
    do
  {
    cout<<"\nThe options are as follows: ";
    cout<<"\n1.Deposit\n2.Withdrawal\n3.Print Statement\n4.Pin Change";
    cout<<"\nEnter your choice: ";
    cin>>wish;
    
    switch(wish)
    {
                case 1: p=a.deposits(p); 
                        break;
                case 2: p=a.withdrawal(p); 
                        break;
                case 3: a.statement_print(p);
                        break;
                case 4: a.pin_change();
                        break;
                default: cout<<"\nNo such option.....";  
                        break;
    }
    cout<<"\nDo you want to continue(y/n): ";
    cin>>choice;
  }while(choice=='y');
  cout<<"\nCreating a new Account for the same user...";
  saving_account copy(a);
  cout<<"\nThe Basic details of the new account: ";
  copy.print_personal();
 getch();
 return 0;
}
