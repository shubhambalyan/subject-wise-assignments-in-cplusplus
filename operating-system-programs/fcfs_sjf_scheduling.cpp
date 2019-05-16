#include<stdio.h>

#include<conio.h>

struct process {
  int bt, at, tat, wt;

}
p[5], temp;
main() {
  int n, i, j, ta = 0;
  float avgtat = 0.0, avgwt = 0.0;
  printf("\nEnter the number of processes...\n");
  scanf("%d", & n);
  printf("\nStart entering the cpu burst time and arrival time for the processes...\n");
  for (i = 0; i < n; i++) {
    printf("\n\nPROCESS %d", i + 1);
    printf("\nCPU burst time= ");
    scanf("%d", & p[i].bt);
    printf("\nArrivin time= ");
    scanf("%d", & p[i].at);
  }
  printf("\n\n****FCFS*****\n");
  printf("************************\n");
  for (i = 0; i < n; i++) {
    ta = ta + p[i].bt;
    p[i].tat = ta;
    p[i].wt = p[i].tat - p[i].bt;
    avgtat = avgtat + p[i].tat;
    avgwt = avgwt + p[i].wt;
  }
  avgtat = avgtat / n;
  avgwt = avgwt / n;
  printf("\n\nprocess name\tBurst time\tTAT\tWT\n");
  for (i = 0; i < n; i++) {
    printf("\nP%d           \t%d       \t%d \t%d  ", i + 1, p[i].bt, p[i].tat, p[i].wt);
  }
  printf("\nAverage TAT= %f", avgtat);
  printf("\nAverage WT= %f", avgwt);
  for (i = 0; i < n; i++) {
    p[i].tat = 0;
    p[i].wt = 0;
  }
  ta = 0;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (p[i].at > p[j].at) {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }
  avgtat = 0.0;
  avgwt = 0.0;
  for (i = 0; i < n; i++) {
    ta = ta + p[i].bt;
    p[i].tat = ta - p[i].at;
    p[i].wt = p[i].tat - p[i].bt;
    avgtat = avgtat + p[i].tat;
    avgwt = avgwt + p[i].wt;
  }
  avgtat = avgtat / n;
  avgwt = avgwt / n;
  printf("\n\n*****SJF*****\n");
  printf("************************\n");
  printf("\n\nprocess name\tArrival time\tBurst time\tTAT\tWT\n");
  for (i = 0; i < n; i++) {
    printf("\nP%d           \t%d           \t%d       \t%d \t%d  ", i + 1, p[i].at, p[i].bt, p[i].tat, p[i].wt);
  }
  printf("\nAverage TAT= %f", avgtat);
  printf("\nAverage WT= %f", avgwt);
  getch();
}