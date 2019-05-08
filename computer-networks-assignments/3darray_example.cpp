#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char  *names[4]={"John","Alex","David","Niall"};
    char  *color[4]={"Blue","Orange","Yellow","Red"};
    char  t1[8], t2[8];
    int i,j,n=4;
    printf("\nThe List before Sorting is as  follows:\n\n");
    printf("NAME\t\tCOLOR\n\n");
    for(i=0;i<n;i++)
     {
         printf("%s\t\t%s\n",names[i],color[i]);
     }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
         {
             if(strcmp(names[j],names[j+1])>0)
                {
                      strcpy(t1,names[j]);
                      strcpy(names[j],names[j+1]);
                      strcpy(names[j+1],t1);
                      strcpy(t2,color[j]);
                      strcpy(color[j],color[j+1]);
                      strcpy(color[j+1],t2);
                }
         }
    }
    printf("\nThe Sorted List is as  follows:\n\n");
    printf("NAME\t\tCOLOR\n\n");
    for(i=0;i<n;i++)
     {
         printf("%s\t\t%s\n",names[i],color[i]);
     }
    getch();
    return 0;
}
