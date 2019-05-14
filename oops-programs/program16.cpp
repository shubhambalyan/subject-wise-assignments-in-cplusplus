/* Create a class template for list that can store names or numbers of students. Also
perform the operations like insert, delete, update and display by either overloading
template functions or using generic template functions. */

 #include<iostream>
 using namespace std;
 #include<conio.h>
 
 template<class T>
 
 class student
 {
       T list[30];
   public:
       void insert(int num);
       T delete_record(student<T> &s1, int &num);
       void update(student<T> &s1, int &num);
       void display(int num);
 };
 template<class T>
 void student<T>::insert(int num){
            for(int i=0;i<num;i++)
            cin>>list[i];
}
            
 template<class T>
 void student<T>::display(int num){
            for(int i=0;i<num;i++)
            cout<<list[i]<<endl;
            }
 
 template<class T> 
  void student<T>::update(student<T> &s1, int &num)
  {
      int flag=0;
      T check;
      cout<<"\nEnter the element to be updated: ";
      cin>>check;
      for(int i=0;i<num;i++)
          {
                   if(s1.list[i]==check)
                     {
                          cout<<"\nEntry Exists..."; flag++;
                          cout<<"\nEnter the new Entry: ";
                          cin>>check;
                          s1.list[i]=check;
                          cout<<"\nEntry updated...";
                          break;}
          }
      if(flag==0)
        { cout<<"\nNo Such entry..."; }
  }     
  
  template<class T>
  T student<T>::delete_record(student<T> &s1, int &num)
 {
      int flag=0;
      T check;
      cout<<"\nEnter the element to be deleted: ";
      cin>>check;
      for(int i=0;i<num;i++)
          {
                   if(s1.list[i]==check)
                     {
                          cout<<"\nRecord Exists and deleted";
                          flag++;
                          for(int j=i;j<num-1;j++)
                          {
                             s1.list[j]=s1.list[j+1];
                             }
                             
                             num-=1;                         
                     }
                 
          }
      if(flag==0)
        cout<<"\nNo Such Record...";
        return num;
 }    
 
 int main()
 {
     student <int> s;
     int num,choice;
     cout<<"\nEnter the no. of Students: ";
     cin>>num;
     cout<<"\nEnter the roll nos. of qualified students: \n";
        s.insert(num);
     do
     {
     cout<<"\nSelect: \n1.Update \n2.Delete\n3.Exit";
     cout<<"\nEnter your choice: ";
     cin>>choice;
     switch(choice)
     {
                   case 1: s.update(s,num);
                           break;
                   case 2: num=s.delete_record(s,num);
                           break;
                   case 3: break;                             
     }
     }while(choice!=3);
     cout<<"\nThe final list of roll numbers is: \n";
        s.display(num);        
     student <double> s1;
     cout<<"\nEnter their phone numbers: ";
        s1.insert(num);
     do
     {
     cout<<"\nSelect: \n1.Update \n2.Delete\n3.Exit\n";
     cout<<"\nEnter your choice: ";
     cin>>choice;
     switch(choice)
     {
                   case 1: s1.update(s1,num);
                           break;
                   case 2: num=s1.delete_record(s1,num);
                           break;                             
                   case 3: break;
     }
     }while(choice!=3);
     cout<<"\nThe final list of phone numbers is: \n";
        s1.display(num);     
     getch();
     return 0;
}
