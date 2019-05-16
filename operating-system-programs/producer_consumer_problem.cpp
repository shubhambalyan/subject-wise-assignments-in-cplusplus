#include <stdio.h>
#include <conio.h>

int mutex=1;//1
int full=0; //0
int empty=10;//10
int buffer[10];

void  producer(void *arg)
{
        int i,index=0;

        for(i=0;i<26;i++)
        {
        empty--;//can produce if empty is not zero
        mutex--;
        buffer[index] = i+64;
        printf("Producer added %c to buffer \n",buffer[index]);
        full++;
        mutex++;
        if (++index == 10) index=0;
        }
}

void consumer(void *arg)
{
        int i,index=0;
        for(i=0;i<26;i++)
        {
        full--;//can consume if full is not zero
        mutex--;
        printf("Consumer consumed %c \n",buffer[index]);
        empty++;
        mutex++;
        if (++index == 10) index=0;
        }
}

int main()
{
        producer(NULL);
        consumer(NULL);
        getch();
}
