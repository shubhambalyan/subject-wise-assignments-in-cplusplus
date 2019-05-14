/* Create a class account that maintains acc_no, name, and balance. Perform deposit,
withdrawal and statement print operations. (statement print must print all the
transactions that has taken place so for – use structures inside the class to maintain the
details about transactions)*/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

class account
{
      int acc_no;
      char name[40];
      float balance;
      float deposit;
      float withdraw;
    public:
      struct statement
       {
             char type[15];
             float amount;
       }s[25];
      void input();
      int deposits(int r);
      int withdrawal(int r);
      void statement_print(int r);
}a;

void account::input()
{
     cout<<"\nEnter the Account no. : ";
     cin>>acc_no;
     cout<<"\nEnter the Name: ";
     cin>>name;
     cout<<"\nEnter the Balance: ";
     cin>>balance;
}

int account::deposits(int r)
{
         
     cout<<"\nEnter the amount to be deposited: ";
     cin>>deposit;
     strcpy(s[r].type,"Deposit");
     s[r].amount=deposit;
     balance+=deposit;
     return ++r;
}

int account::withdrawal(int r)
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

void account::statement_print(int r)
{
     int i;
     cout<<"\nAccount no. : ";
     cout<<acc_no;
     cout<<"\nName: ";
     cout<<name;
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
     
int main()
{
    a.input();
    int wish,p=1;
    char choice;
    do
  {
    cout<<"\nThe options are as follows: ";
    cout<<"\n1.Deposit\n2.Withdrawal\n3.Print Statement";
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
                default: cout<<"\nNo such option.....";  
                        break;
    }
    cout<<"\nDo you want to continue(y/n): ";
    cin>>choice;
  }while(choice=='y');
 getch();
 return 0;
}
