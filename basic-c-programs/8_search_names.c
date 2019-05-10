#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
 int n,i,low,high,mid,found=0;
 char key[20],names[20][30];
 clrscr();
 printf("Enter the no of names\n");
 scanf("%d",&n);
 printf("Enter the names in assending order\n");
 for(i=0;i<n;i++)
 {
  scanf("%s",names[i]);
 }
 printf("Enter the name to be search\n");
 scanf("%s",key);
 low=0;
 high=n-1;
 while(low<=high&&!found)
 {
  mid=(low+high)/2;
  if(strcmp(names[mid],key)==0)
  found=1;
  else if(strcmp(names[mid],key)<0)
  low=mid+1;
  else
  high=mid-1;
 }
 if(found==1)
 printf("Names that found in the list at %d",mid+1);
 else
 printf("Name is not found and the search is unsuccessful");
 getch();
}