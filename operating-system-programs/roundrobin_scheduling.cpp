#include<iostream>
#include<conio.h>
using namespace std;
struct pcb
{
   int id,at,bt,rt,wt,tat,arr[3][10],st,ct,x;
}process[50];
       
main()
{
      int n,flag;
      int i,j,k,c,e,y;
      int time;
      int ts=2;
      cout<<"\nEnter n : ";
      cin>>n;
      for(i=1;i<=n;i++)
      {
		   cout<<"Process id :";
		   cin>>process[i].id;
		   cout<<"Burst time :";
		   cin>>process[i].bt;
		   cout<<"Arrival time :";
		   cin>>process[i].at;
		   process[i].rt=process[i].bt;
      }
      int flaga[50],flagc[50],arror[50];
      for(i=0;i<50;i++)
      {
		   flaga[i]=0;
		   process[i].x=0;
		   flagc[i]=0;
		   arror[i]=0;
		   for(j=0;j<10;j++)
				process[i].arr[1][j]=process[i].arr[2][j]=0;
      }
      time=process[1].at;
      flaga[1]=1;
      arror[1]=1;
      c=1;
      while(1)
      {
		  for(i=1;i<=n;i++)
		  {
			   for(j=1;j<=n;j++)
			   {
					if(process[j].at<=time&&flaga[j]==0)
					{
								 arror[++c]=process[j].id;
								 flaga[process[j].id]=1;
					}
			   }
			   if(arror[i]!=0&&flaga[process[i].id]==1&&flagc[process[i].id]==0)
			   {                                                                
					 if(process[i].rt>=ts)
					 {
						 process[i].st=time;
						 process[i].x=process[i].x+1;
						 process[i].arr[1][process[i].x]=time;
						 process[i].arr[2][process[i].x]=time+ts;
						 process[i].rt=process[i].rt-ts;
						 time=time+ts;
						 if(process[i].rt==0)
						 {
							flagc[process[i].id]=1;
							process[i].ct=time;
						 }
					 }
					 else if(process[i].rt<ts)
					 {
						 process[i].st=time;
						 process[i].x=process[i].x+1;
						 process[i].arr[1][process[i].x]=time;
						 process[i].arr[2][process[i].x]=time+process[i].rt;
						 time=time+process[i].rt;
						 process[i].rt=0;
						 flagc[process[i].id]=1;
						 process[i].ct=time;
					 }
			   }
		  }
		  flag=0;
		  for(k=1;k<=n;k++)
		  {
			   if(flagc[k]==0)
			   {
				   flag=1;
				   break;
			   }
		  }
		  if(flag==0)
		  break;
      }
//display results
      for(i=1;i<=n;i++)
      {
		   cout<<"\n\n\t\tProcess : "<<process[i].id;
		   cout<<"\nSubmissions at : \n";
		   for(j=1;j<=process[i].x;j++)
		   {
			   cout<<process[i].arr[1][j]<<"\t";
		   }
		   cout<<"\nCompletions at : \n";
		   for(j=1;j<=process[i].x;j++)
		   {
			   cout<<process[i].arr[2][j]<<"\t";
		   }
		   cout<<"\n\nCompletion time final : "<<process[i].ct;
      }
      getch();
}
