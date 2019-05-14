#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
    int i;
    char pin[3];
    printf("\nEnter the pin: ");
    for(i=0;i<4;i++)
     {
                    pin[i]=getch();
                    printf("*");
                    }
     char pin1[3];
     printf("\nEnter the pin1: ");
    for(i=0;i<4;i++)
     {
                    pin1[i]=getch();
                    printf("*");
                    }
     if(strcmp(pin,"1234")==0)
        printf("done");
     
                    printf("%s",pin);
                    printf("%s",pin1);
                    getch();
}
