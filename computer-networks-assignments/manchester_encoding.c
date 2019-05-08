#include<stdio.h>
#include<conio.h>
int main()
{
    int msg[20],size,min=0,max=5,n,i,check=0;
    printf("\nEnter the size: ");
    scanf("%d",&size);
    printf("\nEnter the message(0/1): ");
    for(i=0;i<size;i++)
    scanf("%d",&msg[i]);
    printf("\n\n\t\t\tNRZ OUTPUT\n\n");
    for(i=0;i<size;i++)
    {
       if(msg[i]==0)
          printf("%d: %dV\n",msg[i],min);
       else
          printf("%d: %dV\n",msg[i],max);
    }
    printf("\n\n\t\t\tNRZ-I OUTPUT\n\n");
    printf("%d: %dV\n",msg[0],min);
    for(i=1;i<size;i++)
    {
       if((msg[i-1]==0 && msg[i]==0) || (msg[i-1]==1 && msg[i]==0))
       {
           if(check==0)
              printf("%d: %dV\n",msg[i],min);
           else
              printf("%d: %dV\n",msg[i],max);
       }
      else if((msg[i-1]==0 && msg[i]==1) || (msg[i-1]==1 && msg[i]==1))
       {
           if(check==0)
             {
                  printf("%d: %dV --> %dV\n",msg[i],min,max);
                  check=1;
             }
           else
             {
                  printf("%d: %dV --> %dV\n",msg[i],max,min);
                  check=0;
             }      
       }
    }
    printf("\n\n\t\t\tMANCHESTER OUTPUT\n\n");
    for(i=0;i<size;i++)
    {
       if(msg[i]==0)
          printf("%d: %dV --> %dV\n",msg[i],min,max);
       else
          printf("%d: %dV --> %dV\n",msg[i],max,min);
    }
    getch();
    return 0;
}
