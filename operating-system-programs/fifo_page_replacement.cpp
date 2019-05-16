// FIFO Page Replacement 

#include<stdio.h>
#include<conio.h>
main()
{
      int i,j=0,p,flag,page[20],size,frame[10],n,fault=0;
      printf("\nEnter the total no. of pages: ");
      scanf("%d",&n);
      printf("\nEnter the page numbers: ");
      for(i=0;i<n;i++)
         scanf("%d",&page[i]);
      printf("\nEnter the page frame size: ");
      scanf("%d",&size);
      for(i=0;i<size;i++)
         frame[i]=0;
      
      for(i=0;i<n;i++)
      {
            flag=0;
             for(p=0;p<size;p++)
               if(frame[p]==page[i])
                  flag=1;
             
             if(flag==0)
             {
                  frame[j]=page[i];
                  j=j+1;
                  if(j>=size)
                    j=0;
                  fault++;
                  for(p=0;p<size;p++)
                     printf("%d\t",frame[p]);
             }
             if(flag==1)
                for(p=0;p<size;p++)
                     printf("%d\t",frame[p]);
             printf("\n");
       }
      printf("\nNo. of Page Faults: %d",fault);
      float ratio,hit;
      hit=(float)(n-fault)/n;
      ratio=hit*100;
      printf("\nHit ratio: %f",ratio);
      getch();
}
