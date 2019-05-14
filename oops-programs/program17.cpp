/* Create a class powered device (type(electronic/mechanical), power range(10W-
20W), self_powered/adapter) and inherit it in two classes scanner (no.of pages per
second, resolution, size, cost, brand) and printer (brand, dpi, color/b/w, pages per
second, laser/inkjet). Create another class named copier that inherits the features of
printer and scanner along with additional features (storage capacity, stored copy
printing speed). Ensure that the duplicate copies of powered_device object don’t exist
in copier. */

 #include<iostream>
 using namespace std;
 #include<conio.h>
 #include<stdio.h>
 
 class powered_device
 {
    protected:
       char type[20];
       char range[15];
       char recharge[20];
    public:
       void accept()
       {
            cout<<"\nType(electronic/mechanical): ";  fflush(stdin); gets(type);
            cout<<"\nPower Range: ";  fflush(stdin); gets(range);
            cout<<"\nRecharge Type(self/adaptor): ";  fflush(stdin); gets(recharge);
       }
       void display()
       {
            cout<<"\n\nDEVICE--->";
            cout<<"\nType: ";  puts(type);
            cout<<"\nPower Range: ";  puts(range);
            cout<<"\nRecharge Type: ";  puts(recharge);
       }
 };
 
 class scanner: virtual public powered_device
 {
     protected:
       int pages;
       float cost;
       char brand[20];
       char resolution[20];
     public:
        void accept()
        {
             cout<<"\nNo. of pages/second: "; cin>>pages;
             cout<<"\nResolution: "; cin>>resolution;
             cout<<"\nBrand: "; cin>>brand;
             cout<<"\nCost: "; cin>>cost;
             }
        void display()        
        {
             cout<<"\n\nSCANNER--->";
             cout<<"\nNo. of pages/second: "<<pages;
             cout<<"\nResolution: "<<resolution;
             cout<<"\nBrand: "<<brand;
             cout<<"\nCost: "<<cost;
             }
 };
 
 class printer: virtual public powered_device
 {
       protected:
            int pages;
            char color_type[10];
            char brand[20]; 
            char type[15];
       public:
            void accept()            
             {
                cout<<"\nNo. of pages/second: "; cin>>pages;
                cout<<"\nColor type(color/B/W): "; cin>>color_type;
                cout<<"\nBrand: "; cin>>brand;
                cout<<"\nType(Inkjet/Laser): "; cin>>type;
             }
            void display()            
             {
                  cout<<"\n\nPRINTER--->";
                cout<<"\nNo. of pages/second: "<<pages;
                cout<<"\nColor type: "<<color_type;
                cout<<"\nBrand: "<<brand;
                cout<<"\nType: "<<type;
             }
 };
 
 class copier: public scanner, public printer
 {
       float capacity;
       int speed;
    public:
       void accept()
       {
            cout<<"\nStorage Capacity(in KB): "; cin>>capacity;
            cout<<"\nPrinting speed(no. of pages/second): "; cin>>speed;
            }
       void display()
       {
            powered_device::display();
            scanner::display();
            printer::display();
            cout<<"\n\nCOPIER--->";
            cout<<"\nStorage Capacity(in KB): "<<capacity;
            cout<<"\nPrinting speed: "<<speed;
            }
                 
 };
 
 int main()
 {
     copier c;
     cout<<"\nEnter the Basic Details of the Device...\n";
     c.powered_device::accept();
     cout<<"\nEnter the Details for the Scanner...\n";
     c.scanner::accept();
     cout<<"\nEnter the Details for the printer...\n";
     c.printer::accept();
     cout<<"\nEnter the Details for the copier...\n";
     c.accept();
     cout<<"\nThe Final Details are: ";
     c.display();
     getch();
     return 0;
 }
