/* Create a class which maintains information like username, password, age, mailid,
phone number, accepted friends list, etc.,. Declare a friend function inside the class.
Create 3 users such that the first user is friend with 2 and 3 (update friend list of user 1
with user names of 2 and 3). If the user1 logs in, he should see the personal
information of 2 and 3, likewise 2 and 3 should see personal info of 1. However, 2
can’t see the personal information of 3 and vise versa. */

 #include<iostream.h>
 #include<conio.h>
// #include<stdio.h>
 
 class facebook
 {
       int user;
       int password;
       int age;
       char mail_id[50];
       float phone_no;
       char friend_list[][20];
    public:
       void input();
       void display(int i);
       int login(facebook*f);
       friend void accepted_friends(facebook*f,int num);
 };
 
 void facebook::input()
 {
      cout<<"\nUser (1/2/3): "; cin>>user;
      cout<<"\nPassword: "; cin>>password;
      cout<<"\nAge: "; cin>>age;
      cout<<"\nMail ID: "; cin>>mail_id;
      cout<<"\nPhone no.: "; cin>>phone_no;
 }
 
 void facebook::display(int i)
 {
      facebook f1[4];
      cout<<"\nUser: "<<f1[i].user;
      cout<<"\nAge: "<<f1[i].age;
      cout<<"\nMail ID: "<<f1[i].mail_id;
      cout<<"\nPhone no.: "<<f1[i].phone_no;
 }
 
 int facebook::login(facebook*f)
 {
     f=new facebook;
      int user1,flag=0;
      int password1;
      a:
      cout<<"\nUser (1/2/3): ";
      cin>>user1;
      cout<<"\nPassword: ";
      cin>>password1;
      for(int i=1;i<=3;i++)
      { 
            if((f[i].user==user1)&&(password1==f[i].password))
             {
                  cout<<"\nLogin Successful...";
                  flag=user1;
                  return flag;
             }
      }
      if(flag==0)
      {
                 cout<<"\nIncorrect User or Password...";
                 goto a;
      }
 }
 
 void accepted_friends(facebook*f,int num)
 {
      int i=0;
      char ch;
      cout<<"\nAccepted friend list: ";
      do
      {
            cout<<"\nFriend: ";
            cin>>f[num].friend_list[i];
            i++;
            cout<<"\nWant to add another friend: ";
            cin>>ch;
      }while(ch=='y');
 }
 
 int main()
 {
     facebook*f;
     f=new facebook;
     int user_active;
     char ch;
     cout<<"\n.....Creating a Facebook database for 3 users.....";
     for(int i=1;i<=3;i++)
     {
             f[i].input();
             accepted_friends(f,i);
     }
     do
     {
        cout<<"\nLOGIN...";
        user_active=f[0].login(f);     
        if(user_active==1)
         {
              f->display(2);
              f->display(3);
         }
        else if(user_active==2)
         {
              f->display(1);
         }
        else
         {
              f->display(1);
         }
        cout<<"\nWish to continue: ";
        cin>>ch;
      }while(ch=='y');
      delete f;
      getch();
      return 0;
 }    
        
        
             
