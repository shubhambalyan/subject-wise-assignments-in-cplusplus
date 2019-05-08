#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>

int main()
{
    int data[20],gen[10],m,n;
    cout<<"\nTotal bits in dataword: "); cin>>n;
    cout<<"\nEnter the dataword(0/1): ";
    for(i=0;i<n;i++)
    cin>>data[i];
    cout<<"\nTotal bits in generating codeword: "); cin>>m;
    cout<<"\nEnter the generating codeword(0/1): ";
    for(i=0;i<m;i++)
    cin>>gen[i];
    for(i=n;i<m+n;i++)
      data[i]=0;
    for(i=0;i<m+n;i++)
       cout<<data[i];
    getch();
    return 0;
}
    
