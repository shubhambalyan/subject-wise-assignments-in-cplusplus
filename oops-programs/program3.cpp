/* Create a class that holds the details of the mobile phone like brand, imei, no of sim
cards, phone numbers etc.,.
Allow user to login with their mobile no. Use a function that sends a message from that
mobile. Maintain the details of the message as a static member inside the send message
function and display each time all the messages sent from that mobile.*/
 
 #include<iostream.h>
 #include<conio.h>
 int var=1;
 class mobile
 {
       char brand[20];
       long int imei;
       int sims;
       float phone_no;
       static char message[100][200];
       
     public:
       /*float getPhone()
       {
             return phone_no;
       }*/
       
       void input();
       int login(mobile m[10],int);
       void send_msg(mobile m[10],int no, int num);
       void display(mobile m[10],int,int);
 };
 mobile m[10],mpass;
 
 char mobile::message[100][200];
 
 void mobile::input()
 {
      cout<<"\nEnter the phone no.: ";
      cin>>phone_no;
      cout<<"\nEnter the brand: ";
      cin>>brand;
      cout<<"\nEnter the number of SIMs: ";
      cin>>sims;
      cout<<"\nEnter the IMEI no.: ";
      cin>>imei;
 }
 
 int mobile::login(mobile m[10],int num)
 {
      float check_no;
      int flag=0;
      a:
      cout<<"\nEnter the mobile number: ";
      cin>>check_no;
      for(int i=1;i<=num;i++)
      {
              if(m[i].phone_no==check_no)
                {  cout<<"\nLogin Successful..."; 
                   flag=i; 
                   return flag; }
       }
       cout<<"\nInvalid Number...";
       goto a;    
 }
  
 void mobile::send_msg(mobile m[10],int no, int num)
 {
    float mob_no;
    int flag=0;
    a:
    cout<<"\nEnter the recipient's no.: ";
    cin>>mob_no;
    for(int i=1;i<=num;i++)
    {
      if(m[i].phone_no==mob_no)
        {  cout<<"\nNumber Exists..."; flag++;  break; }
      
    }
    if(flag==0)
       {
          cout<<"\nNo such number exists...";
          goto a;
       }
    cout<<"\nEnter the message(max. 200 characters): ";
    fflush(stdin);
    gets(m[no].message[var]);
    var=var+1;  
  } 
  
 void mobile::display(mobile m[10],int choice, int num)
 {
     cout<<"\nOutbox: ";
     if(choice==1)
     cout<<message[1];
     else
     cout<<message[2];
     cout<<"\nInbox: ";
     if(choice==1)
     cout<<message[2];
     else
     cout<<message[1];     
 }
  
  int main()
  {
      char ch='y';
      int no=-1,num,choice;
      
      cout<<"\nHow many mobile phones do you want to register: ";
      cin>>num;
      cout<<"\nEnter the details of the mobile phones...";
      for(int i=1;i<=num;i++)
      {
            m[i].input();
      }
      while(ch=='y')
      {
           cout<<"\nLOGIN...";
           no=mpass.login(m,num);
           cout<<"\nDo you want to send a message(y/n): ";
           cin>>ch;
           if(ch=='y')
                   mpass.send_msg(m,no,num);
           else
                   break;
           cout<<"\nDo you wish to continue: ";
           cin>>ch;
      }
      do
    {
      cout<<"\nDisplay Messages of: \n";
      for(int i=0;i<num;i++)
      {
              cout<<i+1<<".Mobile "<<i+1<<endl;
      }
      cout<<"\nEnter your choice: ";
      cin>>choice;
      switch(choice)
      {
                    case 1: mpass.display(m,choice,num);
                            break;
                    case 2: mpass.display(m,choice,num);
                            break;
                    default: cout<<"\nNo such option...";
                             break;
      }
      cout<<"\nDo you wish to continue: ";
      cin>>ch;
     }while(ch=='y');
      getch();
      return 0;
  }                                                                           
   
      
       
