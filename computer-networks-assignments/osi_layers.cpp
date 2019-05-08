#include<stdio.h>
#include<conio.h>
#include<windows.h>
int main()
{
    char layer[7][20]={"Physical","Data Link","Network","Transport","Session","Presentation","Application"};
    int stack[10],i,j,n,status,top=-1,number[7]={0,1,2,3,4,5,6};
    char data[50];
    printf("\nEnter the Data to send: ");
    scanf("%s",data);
    for(i=0;i<7;i++)
    {
        top++;
        stack[top]=number[i];
    }
    printf("\nEnter the Layer no. to be checked: ");
    scanf("%d",&n);
    printf("\n");
    Sleep(5000);
    for(i=0;i<n;i++)
    {
        status=stack[top];
        for(j=6;j>=status;j--)
             printf("%s--->",layer[j]);
        top--;
        printf("#%s#\n",data);
    }
    getch();
    return 0;
}
             
