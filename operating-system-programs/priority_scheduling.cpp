#include<stdio.h>

#include<conio.h>

#include<string.h>

struct process {
  int tat, wt, at, bt, btt;
  char pr[2];
}
p[5], temp;
main() {
  int i, j, n = 4, k, tot = 0;
  float avgtat = 0.0, avgwt = 0.0;
  printf("\nEnter the process, its burst tym n arrval tym ..\n");
  for (i = 0; i < n; i++) {
    printf("\nProcess= ");
    scanf("%s", & p[i].pr);
    printf("\nCPU burst tym= ");
    scanf("%d", & p[i].bt);
    p[i].btt = p[i].bt;
    printf("\nArrival tym= ");
    scanf("%d", & p[i].at);
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (p[i].at > p[j].at) {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }
  printf("\n\n");
  printf("process\tburst\tarrival\n");
  for (i = 0; i < n; i++)
    printf("\n%s     \t%d    \t%d     ", p[i].pr, p[i].btt, p[i].at);
  j = 1;
  for (i = 0; i < n; i++) {
    printf("\ni= %d", i);
    if (p[i].bt > p[i + j].bt && p[i].bt > p[i + j].at) {
      if (j == 1) {
        p[i].bt = p[i].bt - p[i + j].at;
        tot = tot + p[i + j].at;
      }
      if (tot == p[i + j].at) {
        p[i + j].wt = 0;
        p[i + j].tat = p[i + j].btt + p[i + j].wt;
      } else {
        p[i + j].wt = tot - p[i + j].at;
        p[i + j].tat = p[i + j].btt + p[i + j].wt;
      }
      tot = tot + p[i + j].bt;
      printf("\ntotal= %d", tot);
      p[i + j].bt = 0;
      j++;
      if (j < 4)
        i = -1;
      else {
        for (i = 0; i < n; i++) {
          if (p[i].bt != 0) {
            printf("\nin if loop\n");
            if (p[i].bt < p[i].btt)
              p[i].wt = p[i].btt + (p[i].btt - p[i].bt);
            else
              p[i].wt = tot - p[i].at;
            p[i].tat = p[i].wt + p[i].btt;
            tot = tot + p[i].bt;
            p[i].bt = 0;
          }
        }
      }

    } else {
      j++;
      if (j < 4)
        i = -1;

      /* if(j>=4)
       {
        for(i=0;i<n;i++)
          {
           if(p[i].bt!=0)
           {
            p[i].wt=p[i].btt+(p[i].btt-p[i].bt);
            tot=tot+p[i].bt;
            p[i].bt=0;             
                         }               
                          }           
               } */
    }
  }
  printf("\n\n****PRIORITY*****\n");
  printf("************************\n");
  for (i = 0; i < n; i++) {
    avgtat = avgtat + p[i].tat;
    avgwt = avgwt + p[i].wt;
  }
  avgtat = avgtat / n;
  avgwt = avgwt / n;
  printf("\n\nBurst time\tTAT\tWT\n");
  for (i = 0; i < n; i++) {
    printf("\n  %d       \t%d \t%d  ", p[i].btt, p[i].tat, p[i].wt);
  }
  printf("\nAverage TAT= %f", avgtat);
  printf("\nAverage WT= %f", avgwt);
  getch();
}