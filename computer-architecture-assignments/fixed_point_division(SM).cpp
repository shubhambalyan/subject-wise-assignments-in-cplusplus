// Submitted By: Shubham Balyan

// Signed-Magnitude Division using Restoration Method

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
#define SIZE 100

int decimalToBinary(int num, int*arr)
{
    int track,i=1;
    track=num;
    if(num==0)
    {
       arr[i]=0;
       ++i;
       arr[i]=0;
       return i;
    }
    while(track!=0)
    {
         arr[i]=track%2;
         track=track/2;
         i++;
    }
    return (i-1);
}

int BinaryToDecimal(int c,int d)
{
    int pow=1;
    int i=1;
    while(i<=d) 
    {
        pow=pow*c;
        i++;
    }
    return pow;
}

void BinaryAddition(int A[SIZE], int M[SIZE],int temp[SIZE],int len2,int&carry)
{
     int i,j;    
     for(i=len2;i>0;i--)
     {
          if(A[i]==0 && M[i]==0 && carry==0)
          {
             temp[i]=0;
             carry=0;
          }
          if(A[i]==1 && M[i]==0 && carry==0)
          {
             temp[i]=1;
             carry=0;
          }
          if(A[i]==0 && M[i]==1 && carry==0)
          {
             temp[i]=1;
             carry=0;
          }
          if(A[i]==1 && M[i]==1 && carry==0)
          {
             temp[i]=0;
             carry=1;
          }
          if(A[i]==1 && M[i]==1 && carry==1)
          {
             temp[i]=1;
             carry=1;
          }
          if(A[i]==0 && M[i]==0 && carry==1)
          {
             temp[i]=1;
             carry=0;
          }
          if(A[i]==0 && M[i]==1 && carry==1)
          {
             temp[i]=0;
             carry=1;
          }
          if(A[i]==1 && M[i]==0 && carry==1)
          {
             temp[i]=0;
             carry=1;
          }
    }
}

int main()
{
    int dividend,divisor,temp_dividend,temp_divisor;
    int AQ[SIZE],B[SIZE],len1,len2,p,q,r,y,temp[SIZE],i,j,L[SIZE],K[SIZE];
    printf("\n-------------------------------------------------------------------------------\n");
    printf("\t    Fixed Point Signed Magnitude Division Restoring Method");
    printf("\n-------------------------------------------------------------------------------\n");
    
    // Input Dividend. 
    printf("\n\nEnter the Dividend(in Decimal): ");
    scanf("%d",&dividend);
    if(dividend<0)
       temp_dividend=(int)(dividend + 2*fabs(dividend));
    else
       temp_dividend=dividend;
    len1=decimalToBinary(temp_dividend,AQ);
    for(i=len1,j=1;i>0,j<=len1;i--,j++)
         temp[j]=AQ[i];
    for(j=1;j<=len1;j++)
         AQ[j]=temp[j];       
    
    // Input Divisor.   
    printf("\nEnter the Divisor(in Decimal): ");
    scanf("%d",&divisor);
    
    // Check for Divide by Zero(0)
    if(divisor==0)
    {
          printf("\n\n\t\tDIVIDE BY ZERO ERROR !!!");
          getch();
          exit(0);
    }
    
    if(divisor<0)
       temp_divisor=(int)(divisor + 2*fabs(divisor));
    else
       temp_divisor=divisor;
    len2=decimalToBinary(temp_divisor,B);
    for(i=len2,j=1;i>0,j<=len2;i--,j++)
         temp[j]=B[i];
    for(j=1;j<=len2;j++)
         B[j]=temp[j];
                     
    p=2*len2;
    if(len1==p)
       printf("\nReady for Division....\n");
    else if(len1<(2*len2))
       {            
            q=p-len1;
            for(i=1;i<=q;i++)
                temp[i]=0;
            for(j=q+1,i=1;j<=p,i<=len1;j++,i++)
                temp[j]=AQ[i];
            for(i=1;i<=p;i++)
                AQ[i]=temp[i];
            len1=p;
        }
    else
       {
            if(len1%2==1)
              {
                   q=len1+1;
                   temp[1]=0;
                   for(j=2,i=1;j<=q,i<=len1;j++,i++)
                       temp[j]=AQ[i]; 
                   for(i=1;i<=q;i++)
                       AQ[i]=temp[i];
                   len1=q;
              }
            r=len1/2;
            if(len2!=r)
              {
                   q=r-len2;
                   for(j=1;j<=q;j++)
                       temp[j]=0;
                   for(j=q+1,i=1;j<=r,i<=len2;j++,i++)
                       temp[j]=B[i];
                   for(i=1;i<=r;i++)
                       B[i]=temp[i];
                   len2=r;
              }
        }             
    
    // Display Contents of AQ and B Registers.
    printf("\n-------------------------------------------------------------------------------\n");
    printf("\nContent of AQ Register: ");
    for(i=1;i<=len1;i++)
         printf("%d",AQ[i]);
    printf("\n\nContent of B Register: ");
    for(i=1;i<=len2;i++)
         printf("%d",B[i]);            
    printf("\n\n-------------------------------------------------------------------------------\n");
    
    // Divide AQ Register into A and Q register separately. 
    int A[SIZE],Q[SIZE],E=0,x;
    p=len1/2;
    for(i=1;i<=p;i++)
        A[i]=AQ[i];
    for(i=p+1;i<=len1;i++)
        Q[i]=AQ[i];    
        
    
    // Display Contents of E, A and Q Registers.
    printf("\nInitial Contents of E,A and Q Registers...\n");
    printf("\nE: %d",E);
    printf("\n\nA: ");
    for(i=1;i<=p;i++)
         printf("%d",A[i]);
    printf("\n\nQ: ");
    for(i=p+1;i<=len1;i++)
         printf("%d",Q[i]);
    printf("\n\n-------------------------------------------------------------------------------\n"); 
    
    // Initialise Qs Register and Sequence Counter(SC). 
    int Qs,As=0,Bs=0,SC=0; 
    if(dividend<0)
       As=1;   
    if(divisor<0)
       Bs=1;
    SC=len2;
    Qs= As*(!Bs) + (!As)*Bs;
    x=dividend/divisor;
    printf("\nSign of Quotient(Qs): ");
    if(Qs==1)
       printf("-");
    else
       printf("+");
    printf("\n\nSequence Counter(SC): %d",SC);      
    printf("\n\n-------------------------------------------------------------------------------\n");
    for(i=1;i<=p;i++)
         K[i]=A[i]; 
    for(i=p+1;i<=len1;i++)
         L[i]=Q[i];
    
    // Calculate 2's complement of B and store it in M Register.
    int M[SIZE],c=0;       
    len2=len2+1;
    for(i=len2-1;i>0;i--)
    {
        if(B[i]==0)
           M[i]=1;
        else
           M[i]=0;
    }
    for(i=len2-1;i>0;i--)
    {
        if(i==len2-1)
        {
            if(M[i]==0)
               M[i]=1;
            else
            {
               M[i]=0;
               c=1;
            }
        }
        else
        {
            if(c==1 && M[i]==0)
            {
                 M[i]=1;
                 c=0;
            }
            else if (c==1 && M[i]==1)
            {
                 M[i]=0;
                 c=1;
            }
         }
    }
    len2=len2-1;
    y=dividend%divisor;
    printf("\n2's complement of B: ");
    for(i=1;i<=len2;i++)
        printf("%d",M[i]); 
    
    // Checking for Divide Overflow.
    int EA[SIZE],carry=0,DVF=0;   
    BinaryAddition(A,M,EA,len2,carry);
    if(carry==1)
       E=1;
    else
       E=0;
    carry=0;
    printf("\n\nA + (B'+1): ");
    printf("%d ",E);
    for(i=1;i<=len2;i++)
        printf("%d",EA[i]);
        
    printf("\n\n-------------------------------------------------------------------------------\n");     
    printf("\n\t\t    ....CHECKING FOR DIVIDE OVERFLOW.....");
    if(E==1)
    {
            printf("\n\n\t\t\t\tA >= B");
            BinaryAddition(EA,B,EA,len2,carry);
            DVF=1;
    }
    else
    {
            printf("\n\n\t\t\t\tA < B");
            BinaryAddition(EA,B,EA,len2,carry);
            if(carry==1)
               E=1;
            else
               E=0;
            DVF=0;
    }
    if(DVF==1)
    {
            printf("\n\n\t\t\t....DIVIDE OVERFLOW....");  
            printf("\n\n\t\t    ...Process Of Division Terminates...");
            printf("\n\n\t\t\t    .....END.....");
            getch();  exit(0);
    }
    else
    {
            printf("\n\n\t\t\t....NO DIVIDE OVERFLOW....");  
    }
    
        
    // Performing Division of two Binary numbers.
    printf("\n\n-------------------------------------------------------------------------------\n"); 
    printf("\n\n\t\t.......DIVISION PROCESS GOING ON.......\n");
    int ch=1,g=1;    
    printf("\nDo you wish to continue(1 for yes/0 for no): ");
    scanf("%d",&ch);
    if(ch==0)
       {  getch(); exit(0); }
    
    
    for(j=1;j<=len2;j++)
        A[j]=EA[j];
        
    repeat:            // goto label

    // Shift left EAQ
    
    printf("\n\n-------------------------------------------------------------------------------\n");  
    printf("\nAt SC=%d",SC);
    printf("\n\nE: %d",E);
    printf("\n\nA: ");
    for(i=1;i<=p;i++)
         printf("%d",A[i]);
    printf("\n\nQ: ");
    for(i=p+1;i<=len1;i++)
         printf("%d",Q[i]);
    printf("\n\n-------------------------------------------------------------------------------\n"); 
    
    p=len1/2;
    E=A[1];
    for(j=1;j<p;j++)
        A[j]=A[j+1];
    A[p]=Q[p+1];
    for(j=p+1;j<len1;j++)
        Q[j]=Q[j+1];
    Q[len1]=0;
    
        
    end:
        
    // For E=0 Part
    if((E==0)&&(g!=0))
    {
              carry=0;
              BinaryAddition(A,M,EA,len2,carry);
              for(j=1;j<=len2;j++)
                  A[j]=EA[j];              
              if(carry==1)
                 E=1;
              else
                 E=0;
                 
              // Checking E again
              
              
              if(E==0)
              {
                    carry=0;
                    BinaryAddition(A,B,EA,len2,carry);
                    for(j=1;j<=len2;j++)
                        A[j]=EA[j];
                    if(carry==1)
                       E=1;
                    else
                       E=0;
                    SC=SC-1;
                    if(SC==0)
                    { 
                       g=0;
                       goto end;
                    }
                    else
                       goto repeat;
              }
              
              else
              {
                     Q[len1]=1;
                     SC=SC-1;
                     if(SC==0)
                     { 
                         g=0;
                         goto end;
                     }
                     else
                         goto repeat;
              }
    }
    
    // For E=1 Part
    else if((E==1)&&(g!=0))
    {
              carry=0;
              BinaryAddition(A,M,EA,len2,carry);
              for(j=1;j<=len2;j++)
                  A[j]=EA[j];
              Q[len1]=1;
              SC=SC-1;
              if(SC==0)
              { 
                  g=0;
                  goto end;
              }
              else
                  goto repeat;
    }
    
    // Printing the Final Result
    printf("\n\n-------------------------------------------------------------------------------\n"); 
    printf("\n\t\t**************RESULT***************");
    int h=(int)fabs(x);
    int a=decimalToBinary(h,L);
    for(i=a,j=1;i>0,j<=a;i--,j++)
         temp[j]=L[i];
    for(j=1;j<=a;j++)
         L[j]=temp[j];
    if(a!=len2)
     {
            int e=len2-a;
            for(i=1;i<=e;i++)
                temp[i]=0;
            for(i=e+1,j=1;i<=len2,j<=a;i++,j++)
                temp[i]=L[j];
            for(i=1;i<=len2;i++)
                L[i]=temp[i];
            a=len2;
     }
    for(j=p+1,i=1;j<=len1,i<=a;j++,i++)
        Q[j]=L[i];
    
    int remainder,quotient,dec=0,k=len2-1;    
    
    int w=(int)fabs(y);
    int b=decimalToBinary(w,K);
    for(i=b,j=1;i>0,j<=b;i--,j++)
         temp[j]=K[i];
    for(j=1;j<=b;j++)
         K[j]=temp[j];
    if(b!=len2)
     {
            int e=len2-b;
            for(i=1;i<=e;i++)
                temp[i]=0;
            for(i=e+1,j=1;i<=len2,j<=b;i++,j++)
                temp[i]=K[j];
            for(i=1;i<=len2;i++)
                K[i]=temp[i];
            b=len2;
     }
    for(j=1,i=1;j<=len2,i<=b;j++,i++)
        A[j]=K[i];
    
    // Converting Binary values to Decimal
        
       
       //Quotient
    for(i=p+1;i<=len1;i++) 
    {
        dec=(Q[i]*BinaryToDecimal(2,k))+dec;
        k--;
    }
    quotient=dec;
    
       //Remainder
    dec=0,k=len2-1;
    for(i=1;i<=p;i++) 
    {
        dec=(A[i]*BinaryToDecimal(2,k))+dec;
        k--;
    }
    remainder=dec;
    
    printf("\n\nQuotient(Q): %d",Qs);
    printf(" ");
    for(i=p+1;i<=len1;i++)
         printf("%d",Q[i]);
      
    if(Qs==1)
       printf("     (-");
    else
       printf("     (+");
    printf("%d)",quotient);
    
    int Rs;
    if(dividend<0)
       Rs=1;
    else
       Rs=0;
    
    printf("\n\nRemainder(A): %d",Rs);
    printf(" ");
    for(i=1;i<=p;i++)
         printf("%d",A[i]);
      
    if(Rs==1)
       printf("     (-");
    else
       printf("     (+");
    printf("%d)",remainder);
    
    printf("\n\n-------------------------------------------------------------------------------\n"); 
    printf("\n\n\t\t\t##### END #####");
    printf("\n\n-------------------------------------------------------------------------------\n");             
           
             
    getch();
    return 0;
}
