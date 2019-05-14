/*Create an class that stores details about the computer (Assembled/branded, RAM,
HDD, processor speed, price etc.,). Use constructors to initialize the object and a
destructor that deducts the count of object each time the object is passed to destroy
function. Also use copy constructor to create a system with the configuration same as
that’s of an existing system.*/

 #include<iostream.h>
 #include<conio.h>
 int count=0;
 class computer
 {
       float RAM;
       float speed;
       float price;
       int hard_disk;
     public:
            computer()
            {
                      RAM=0;
                      speed=0;
                      price=0;
                      hard_disk=0;
                      }
            
        computer(float RAM,float speed,float price,int hard_disk)
        {
              this->RAM=RAM;
              this->speed=speed;
              this->price=price;
              this->hard_disk=hard_disk;
              count++;
        }
        ~computer()
        {
             count--;
             cout<<"\nNo. of objects available: "<<count;
        }
        computer(computer&c)
        {
              count++;
              cout<<"\nCopy Constructor called!!!";
              RAM=c.RAM;
              speed=c.speed;
              price=c.price;
              hard_disk=c.hard_disk;
        }
        void destroy(computer*c)
        {
             delete c;
        }
        void display();
 };
 
 void computer::display()
 {
      cout<<"\nRAM\tSpeed\tHard Disk\tPrice\n";
      cout<<RAM<<"\t"<<speed<<"\t"<<hard_disk<<"\t\t"<<price;
 }
 
 int main()
 {
     computer c1(1.25,3.5,29000,100),c2(2.25,5.6,31000,250),c3(4.0,7.5,42000,500);
     //computer c2(2.25,5.6,31000,250);
     //computer c3(4.0,7.5,42000,500);
     computer*obj1,*obj2,*obj3;
      
     obj1=new computer;
     obj2=new computer;
     obj3=new computer;
     
    obj1=&c1;
     obj2=&c2;
     obj3=&c3;
     cout<<"\n::Standard Values::";
     cout<<"\nThe values of the respective objects are... ";
     cout<<"\nC1";
     obj1->display();
     cout<<"\nC2";
     obj2->display();
     cout<<"\nC3";
     obj3->display();
     computer c4(c1);
     cout<<"\nDeleting the objects...";
     obj1->destroy(obj1);
     obj2->destroy(obj2);
     obj3->destroy(obj3);
     cout<<"\nValues in the copy constructor...";
     c4.display();
     getch();
     return 0;
}
