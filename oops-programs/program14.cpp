/* Create a c++ program that Create a base class person and derived classes general
public, government official and VVIP. Maintain a static array of objects using inside the
persons class. Access the shared memory from all the classes to store and retrieve data.
Reserve zones in that array such that they are to be used by appropriate category of
people. Ensure that the space is available in each zone before you create a dynamic object
of each type and store it inside the shared array.*/

 #include<iostream>
 using namespace std;
 #include<conio.h>
 
 class person
 {
       protected:
             int ssn;
             char name[30];
             char address[50];
             double phone;
       public:
             void accept();
             void display();
             static person *p[10];
 };
 
 person *person::p[]={NULL};
 
 void person::accept()
 {
      cout<<"\nSSN no.: "; cin>>ssn;
      cout<<"\nName: "; fflush(stdin); gets(name);
      cout<<"\nAddress: "; fflush(stdin); gets(address);
      cout<<"\nPhone no.: "; cin>>phone;
 }
 
 void person::display()
 {
      cout<<"\nSSN no.: "<<ssn;
      cout<<"\nName: "; puts(name);
      cout<<"\nAddress: "; puts(address);
      cout<<"\nPhone no.: "<<phone;
 }
 
 class general_public:public person
 {
 };
 class government:public person
 {
 };
 class vvip:public person
 {
 };

 int main()
 {
    int choice;
    do
    {
    cout<<"\nMenu---";
    cout<<"\n1.General Public\n2.Government Official\n3.VVIP\n4.Exit\n";
    cout<<"\nChoice: ";
    cin>>choice;
    switch(choice)
    {
         	case 1 : for(int i=0;i<=2;i++)
		              {
                           if(person::p[i]!=NULL)
                              cout<<"\nNo Space Available\n";                          
		                   else
		                    {
			                   person::p[i]=new general_public;
			                   person::p[i]->accept();
			                   cout<<"\nRecord Inserted\n";
			                   break;
		                     }
		              }
		             break;
	        case 2 : for(int i=3;i<=5;i++)
	                  {
		                  if(person::p[i]!=NULL)
                              cout<<"\nNo Space Available\n";                          
		                   else
		                    {
			                   person::p[i]=new government;
			                   person::p[i]->accept();
			                   cout<<"\nRecord Inserted\n";
			                   break;
		                     }
		               }
		             break;
	        case 3 : for(int i=6;i<=8;i++)
		             {
		                  if(person::p[i]!=NULL)
                              cout<<"\nNo Space Available\n";                          
		                   else
		                    {
			                   person::p[i]=new vvip;
			                   person::p[i]->accept();
			                   cout<<"\nRecord Inserted\n";
			                   break;			                   
		                     }
		             }
		             break;
	        case 4 : break;
	        default:cout<<"No such choice...\n";
	}
    }while(choice!=4);
    
    cout<<"\nDisplay---\n";
    for(int i=0;i<=8;i++)
    {
         if(person::p[i]!=NULL)
		    {
			  person::p[i]->display();
            }
    }
	
	getch();
	return 0;
    }
