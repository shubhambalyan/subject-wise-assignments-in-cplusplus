// Reader Writer problem

#include <stdio.h>
#include <conio.h>

int mutex=1;//1
int wrt=1; //1
int readcount=0,file[10];

void writer(void *arg)
{
        int i,index=0;

        for(i=0;i<5;i++)
        {
        wrt--;
        file[index] = i;
        printf("Writer wrote %d to file \n",file[index]);
        wrt++;
        if (++index == 2) index=0;
        }
}

void reader(void *arg)
{
        int i,index=0;
        for(i=0;i<5;i++)
        {
        mutex--;
        readcount++;
        if(readcount==1)
            wrt--;
        mutex++;
        printf("Reader read %d from the file \n",file[index]);
        mutex--;
        readcount--;
        if(readcount==0)
            wrt++;
        mutex++;
        if (++index == 2) index=0;
        }
}
main()
{
        writer(NULL);
        reader(NULL);
        getch();
}
