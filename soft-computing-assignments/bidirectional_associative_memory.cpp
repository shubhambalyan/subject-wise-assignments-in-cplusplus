#include<iostream.h>
#include<conio.h>
#include<windows.h>
using namespace std;
int main()
{
    cout<<"\tBAM Network To Associate Two Letters with Bipolar Input-Output Vectors\n";
    int m,n;
    start:
    cout<<"\nEnter the number of elements in the Display Matrix (e.g. 4X4=16): ";
    cin>>m;
    n=m;
    int A[1][30],B[1][30];
    cout<<"\nEnter the 1X"<<m<<" Matrix for First Letter:\n";
    for(int i=0;i<1;i++)
     {
            for(int j=0;j<m;j++)
             {
                    cin>>A[i][j];
                    if(A[i][j]==0)
                      exit(0);
             }
     }
    cout<<"\nEnter the 1X"<<n<<" Matrix for Second Letter:\n";
    for(int i=0;i<1;i++)
     {
            for(int j=0;j<n;j++)
             {
                    cin>>B[i][j];
                    if(B[i][j]==0)
                      exit(0);
             }
     }
     int T1[2][2],T2[2][2];
     cout<<"\nEnter the Targets for First Letter:\n";
     for(int i=0;i<1;i++)
     {
            for(int j=0;j<2;j++)
             {
                    cin>>T1[i][j];
                    if(T1[i][j]==0)
                      exit(0);
             }
     }
     cout<<"\nEnter the Targets for Second Letter:\n";
     for(int i=0;i<1;i++)
     {
            for(int j=0;j<2;j++)
             {
                    cin>>T2[i][j];
                    if(T2[i][j]==0)
                      exit(0);
             }
     }
    cout<<"\nEnter the Dimensions for the Matrix used: \n";
    int row,col;
    cout<<"\nRows: "; cin>>row;
    cout<<"\nColumns: "; cin>>col;
    cout<<"\nDisplaying First Letter: \n";
    Sleep(2000);
    int k=0;
    for(int i=1;i<=row;i++)
    {
            for(int j=1;j<=col;j++)
            {
                    if(A[0][k]==1)
                      cout<<"*"<<" ";
                    else 
                      cout<<""<<" ";
                    k++;
            }
        cout<<"\n";
    }
    cout<<"\nDisplaying Second Letter: \n";
    Sleep(2000);
    k=0;
    for(int i=1;i<=row;i++)
    {
            for(int j=1;j<=col;j++)
            {
                    if(B[0][k]==1)
                      cout<<"*"<<" ";
                    else 
                      cout<<""<<" ";
                    k++;
            }
        cout<<"\n";
    }
    int choice;
    cout<<"Are the Letters Correct ( 1 for Yes/ 0 for No): ";
    cin>>choice;
    if(choice==0)
     goto start;
    int AA[30][1],BB[30][1];
    for(int i=0;i<1;i++)
     {
            for(int j=0;j<m;j++)
            {
                    AA[j][i]=A[i][j];
                    
            }
      }
     for(int i=0;i<1;i++)
     {
            for(int j=0;j<m;j++)
            {
                    BB[j][i]=B[i][j];
            }
      }
    int W1[20][5],W2[20][5],sum;
    cout<<"\nCalculating Weight Matrix for First letter...\n";
    Sleep(2000);
    for(int i=0;i<m;i++)
      for(int j=0;j<2;j++)
           W1[i][j]=0;
      for(int i=0;i<m;i++)
      { 
          for(int j=0;j<2;j++)
          {  
             sum=0;
             for(int k=0;k<1;k++)
               sum=sum+AA[i][k]*T1[k][j];
           W1[i][j]=sum;
          }
      }
    sum=0;
    cout<<"\nCalculating Weight Matrix for Second letter...\n";
    Sleep(2000);
    for(int i=0;i<m;i++)
      for(int j=0;j<2;j++)
           W2[i][j]=0;
      for(int i=0;i<m;i++)
      { 
          for(int j=0;j<2;j++)
          {  
             sum=0;
             for(int k=0;k<1;k++)
               sum=sum+BB[i][k]*T2[k][j];
           W2[i][j]=sum;
          }
      }
    cout<<"\nThe Total Weight Matrix is: \n";
    Sleep(2000);
    int W[20][5];
    for(int i=0;i<m;i++)
     {
            for(int j=0;j<2;j++)
            {
                  W[i][j]=W1[i][j]+W2[i][j];
                  cout<<W[i][j]<<"  ";
            }
            cout<<endl;
     }
    cout<<"\n\nTesting the Network with Test Vectors as the First Letter...\n\n";
    Sleep(5000);
    int Y1[2][5],Y2[2][5];
    for(int i=0;i<1;i++)
      for(int j=0;j<2;j++)
           Y1[i][j]=0;
      for(int i=0;i<1;i++)
      { 
          for(int j=0;j<2;j++)
          {  
             sum=0;
             for(int k=0;k<m;k++)
               sum=sum+A[i][k]*W[k][j];
           Y1[i][j]=sum;
           cout<<Y1[i][j]<<"  ";
          }
          cout<<endl;
      }   
    cout<<"\n\nOn Applying Activation Function, We have: \n\n";
    for(int i=0;i<1;i++)
     for(int j=0;j<2;j++)
       {
             if(Y1[i][j]>0)
                Y1[i][j]=1;
             else
                Y1[i][j]=-1;
             cout<<Y1[i][j]<<"  ";
       }
    
    
    cout<<"\n\nTesting the Network with Test Vectors as the Second Letter...\n\n";
    Sleep(5000);
    for(int i=0;i<1;i++)
      for(int j=0;j<2;j++)
           Y2[i][j]=0;
      for(int i=0;i<1;i++)
      { 
          for(int j=0;j<2;j++)
          {  
             sum=0;
             for(int k=0;k<m;k++)
               sum=sum+B[i][k]*W[k][j];
           Y2[i][j]=sum;
           cout<<Y2[i][j]<<"  ";
          }
          cout<<endl;
      }   
    cout<<"\n\nOn Applying Activation Function, We have: \n\n";
    for(int i=0;i<1;i++)
     for(int j=0;j<2;j++)
       {
             if(Y2[i][j]>0)
                Y2[i][j]=1;
             else
                Y2[i][j]=-1;
             cout<<Y2[i][j]<<"  ";
       }
    cout<<"\n\nIs the Correct Response Obtained (1 for Yes/ 0 for No): ";
    cin>>choice;
    if(choice==0)
     goto start;
    getch();
    return 0;
}
