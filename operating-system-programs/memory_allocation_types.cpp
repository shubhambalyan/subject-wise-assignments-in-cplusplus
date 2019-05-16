// program to implement First, Best and Worst Fit to allocate memory.
#include<stdio.h>
#include<conio.h>
int size[20],n,file,i;

void first_fit()
{
     int flag=0;
     for(i=0;i<n;i++)
     {
           if(file<=size[i])
           {
                 printf("\nFirst Fit::: File size %d KB allocated to %d KB hole",file,size[i]);
                 size[i]-=file;
                 flag=1;
                 break;
           } 
      }
      if(flag==0)
      printf("\nNot possible to allocate memory!!!");
}

void best_fit()
{
     int flag=0,pos=0,small=size[0];
     for(i=0;i<n-1;i++)
      {
            if(size[i]>size[i+1] && file<=size[i+1])
              {
                    small=size[i+1];
                    flag=1;
                    pos=i+1;
              } 
      }
      if(flag==0 && file<=size[0])
      {  small=size[0]; flag=1; pos=0;  }
      if(flag==1)
        {
             printf("\nBest Fit::: File size %d KB allocated to %d KB hole",file,small);
             small-=file;
             size[pos]=small;
        }
      else
        printf("\nNot possible to allocate memory!!!");
}

void worst_fit()
{
     int flag=0,pos=0,large=size[0];
     for(i=0;i<n-1;i++)
     {
                     if(size[i]<size[i+1] && file<=size[i+1])
                     {
                          large=size[i+1];
                          flag=1;
                          pos=i+1;
                     }
     }
     if(flag==0 && file<=size[0])
     {  large=size[0]; flag=1; pos=0;  }
     if(flag==1)
        {
             printf("\nWorst Fit::: File size %d KB allocated to %d KB hole",file,large);
             large-=file;
             size[pos]=large;
        }
      else
        printf("\nNot possible to allocate memory!!!");
}

main()
{
      int choice=1;
      printf("\nEnter the no. of holes: ");
      scanf("%d",&n);
      printf("\nEnter the Sizes of the holes(in KB): ");
      for(i=0;i<n;i++)
       scanf("%d",&size[i]);
      while(choice!=4)
      {
      printf("\nEnter the file size to fit in the holes(in KB): ");
      scanf("%d",&file);
      printf("\nSelect an option: ");
      printf("\n1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Exit");
      printf("\nYour choice: ");
      scanf("%d",&choice);
      switch(choice)
      { 
                    case 1: first_fit();
                             break;
                    case 2: best_fit();
                             break;
                    case 3: worst_fit();
                             break;
                    case 4: exit(0);
                               break;
      }
      }
      getch();
}              
