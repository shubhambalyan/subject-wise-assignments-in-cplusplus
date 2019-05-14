/* Create a c++ program that has a class product (prod_id, name, price), which is
inherited by other classes viz., belt (length, color, width), shoes (size, formal/casual,
laced/non laced) and caps(diameter, water proof/not, color). List out the products
available to the user and allow the user to select the products and the quantity. Overload *
operator for multiplying quantity with objects and overload + operator to add all the
objects to find the total cost. Finally display the total amount, quantity of each product
with their brands, price etc. */
              
 #include<iostream>
 using namespace std;
 #include<conio.h>
 
 class belt;
 class cap;
 class shoes;
 
 class product
 {
   protected:
       char prod_id[10];
       char name[30];
       float price;
       float qty_price;
   public:
       float total;
       void accept()
       {
          cout<<"\nProduct ID: "; cin>>prod_id;
          cout<<"\nName:"; fflush(stdin); gets(name);
          cout<<"\nPrice: "; cin>>price;
       }
       void display()
       {
          cout<<"\nProduct ID: "<<prod_id;
          cout<<"\nName:"; puts(name);
          cout<<"\nPrice: "<<price;
       }
       
       friend void operator+(product p1, cap c1);
 };
 
 class belt: public product
 {
       float length;
       char color[20];
       float width;
   public:
       void accept_belt()
       {
          cout<<"\nLength(in cm): "; cin>>length;
          cout<<"\nColor:"; fflush(stdin); gets(color);
          cout<<"\nWidth(in cm): "; cin>>width;
       }
       void display_belt()
       {
          cout<<"\nLength(in cm): "<<length;
          cout<<"\nColor:"; puts(color);
          cout<<"\nWidth(in cm): "<<width;
       }
       float operator*(int num)
       {
            qty_price=price*num;
            return qty_price;
       }
       friend product operator+(belt b1, shoes s2);
 }b;
 
 class shoes: public product
 {
       int size;
       char type[10];
       char lace_type[20];
   public:
       void accept_shoes()
       {
          cout<<"\nSize: "; cin>>size;
          cout<<"\nType(Formal/Casual):"; fflush(stdin); gets(type);
          cout<<"\nLace Type(Laced/Non-Laced): "; fflush(stdin); gets(lace_type);
       }
       void display_shoes()
       {
          cout<<"\nSize: "<<size;
          cout<<"\nType:"; puts(type);
          cout<<"\nLace Type: "; puts(lace_type);
       }
       float operator*(int num)
       {
            qty_price=price*num;
            return qty_price;
       }
       friend product operator+(belt b1, shoes s2);
 }s;
 product operator+(belt b1, shoes s2)
 {
      product prod;
      prod.total=b1.qty_price + s2.qty_price;
      return prod;
 }
 
 class cap: public product
 {
       float diameter;
       char color[20];
       char type[15];
   public:
       void accept_cap()
       {
          cout<<"\nDiameter(in cm): "; cin>>diameter;
          cout<<"\nType (Waterproof/not Waterproof):"; fflush(stdin); gets(type);
          cout<<"\nColor: "; fflush(stdin); gets(color);
       }
       void display_cap()
       {
          cout<<"\nDiameter(in cm): "<<diameter;
          cout<<"\nType:"; puts(type);
          cout<<"\nColor: "; puts(color);
       }
       float operator*(int num)
       {
            qty_price=price*num;
            return qty_price;
       }
            friend void operator+(product p1, cap c1);
 }c;
 
 void operator+(product p1,cap c1)
 {
      p1.total+=c1.qty_price;
      cout<<p1.total;
 }
 
 int main()
 {
     
     float i,j,k;
     int n1,n2,n3;
     
     cout<<"\n.....Accepting the Details.....\n";
     cout<<"\n\nBELT--->\n";
     b.accept();
     b.accept_belt();
     
     cout<<"\n\nSHOES--->\n";
     s.accept();
     s.accept_shoes();
     
     cout<<"\n\nCAPS--->\n";
     c.accept();
     c.accept_cap();
     
     cout<<"\nEnter the Quantity: ";
     cout<<"\nBelt: "; cin>>n1;
     cout<<"\nShoes: "; cin>>n2;
     cout<<"\nCaps: "; cin>>n3;
     
     i=b.operator*(n1);
     j=s.operator*(n2);
     k=c.operator*(n3);
     
     cout<<"\n.....Printing the Details.....\n";
     
     cout<<"\n\nBELT--->\n";
     b.display();
     b.display_belt();
     cout<<"\nPrice for "<<n1<<" belts: "<<"Rs."<<i;
     
     cout<<"\n\nSHOES--->\n";
     s.display();
     s.display_shoes();
     cout<<"\nPrice for "<<n2<<" shoes: "<<"Rs."<<j;
     
     cout<<"\n\nCAPS--->\n";
     c.display();
     c.display_cap();
     cout<<"\nPrice for "<<n3<<" caps: "<<"Rs."<<k;   
     
     cout<<"\nTotal cost: ";
     
     product temp;
     temp=operator+(b,s);
     operator+(temp,c); 
             
     getch();
     return 0;
 }
