#include<stdio.h>

#include<conio.h>

struct request {
  int req, finish, temp;
}
r[15];

main() {
  int n_cyl, i, n_req, temp, g_tot = 0, head_pos, choice;
  int count, diff, j, offset, point, temp_pos;

  printf("\nEnter the number of cylinders in disk drive ");
  scanf("%d", & n_cyl);

  printf("\nEnter the no. of requests ");
  scanf("%d", & n_req);

  printf("\nStart entering the %d requests..\n", n_req);

  for (i = 0; i < n_req; i++) {
    scanf("%d", & r[i].req);
    r[i].finish = 0;
    r[i].temp = r[i].req;
  }

  for (i = 0; i < n_req; i++) {
    for (j = 0; j < n_req; j++)
      if (r[i].temp < r[j].temp) {
        temp = r[i].temp;
        r[i].temp = r[j].temp;
        r[j].temp = temp;
      }
  }
  printf("\nEnter the head position  ");
  scanf("%d", & head_pos);
  while (1) {
    printf("\n1. FCFS\n2. SSTF\n3. SCAN\n4. CSCAN\n5. LOOK\n6.CLOOK\n");
    printf("\nSelect your choice \n");
    scanf("%d", & choice);

    switch (choice) {
    case 1:
      g_tot = 0;
      for (i = 0; i < n_req; i++) {
        printf("-> %d ", r[i].req);
        if (i == 0)
          temp = r[i].req - head_pos;
        else
          temp = r[i].req - r[i - 1].req;
        if (temp < 0)
          temp = temp * -1;
        g_tot = g_tot + temp;
      }
      printf("\nTotal Head Movement= %d\n", g_tot);
      break;

    case 2:
      g_tot = 0;
      for (i = 0; i < n_req; i++)
        r[i].finish = 0;
      for (i = 0; i < n_req; i++) {
        count = 0;
        point = offset;
        diff = 1000;
        while (count < n_req) {
          if (i == 0)
            temp = r[count].req - head_pos;
          else if (i != 0 && r[count].finish == 0)
            temp = r[point].req - r[count].req;
          if (temp < 0)
            temp = temp * -1;
          if (temp < diff && r[count].finish == 0) {
            diff = temp;
            offset = count;
          }
          count++;
        }
        printf("-> %d ", r[offset].req);
        g_tot += diff;
        r[offset].finish = 1;
      }
      printf("\nTotal Head Movement= %d\n", g_tot);
      break;
    case 3:
      temp_pos = head_pos;
      for (i = 0; i < n_req; i++)
        if (r[i].temp > temp_pos) {
          for (j = i - 1; j >= 0; j--)
            printf("-> %d ", r[j].temp);
          break;
        }
      printf("-> 0 ");
      temp_pos = head_pos;
      for (i = 0; i < n_req; i++)
        if (r[i].temp > temp_pos) {
          printf("-> %d ", r[i].temp);
          temp_pos = r[i].temp;
        }
      g_tot = head_pos + r[n_req - 1].temp;
      printf("\nTotal Head Movement= %d ", g_tot);
      break;
    case 4:
      temp_pos = head_pos;
      for (i = 0; i < n_req; i++)
        if (r[i].temp > temp_pos) {
          printf("-> %d ", r[i].temp);
          temp_pos = r[i].temp;
        }
      printf("-> %d ", n_cyl - 1);
      i = 0;
      while (r[i].temp < head_pos) {
        printf("-> %d ", r[i].temp);
        i++;
      }
      g_tot = (n_cyl - head_pos - 1) + (n_cyl - r[0].temp - 1) + (r[i - 1].temp - r[0].temp);
      printf("\nTotal Head Movement= %d ", g_tot);
      break;
    case 5:
      temp_pos = head_pos;
      for (i = 0; i < n_req; i++)
        if (r[i].temp > temp_pos) {
          printf("-> %d ", r[i].temp);
          temp_pos = r[i].temp;
        }
      temp_pos = head_pos;
      for (i = 0; i < n_req; i++)
        if (r[i].temp > temp_pos) {
          for (j = i - 1; j >= 0; j--)
            printf("-> %d ", r[j].temp);
          break;
        }
      g_tot = (r[n_req - 1].temp - head_pos) + (r[n_req - 1].temp - r[0].temp);
      printf("\nTotal Head Movement= %d", g_tot);
      break;
    case 6:
      temp_pos = head_pos;
      for (i = 0; i < n_req; i++)
        if (r[i].temp > temp_pos) {
          printf("-> %d ", r[i].temp);
          temp_pos = r[i].temp;
        }
      i = 0;
      while (r[i].temp < head_pos) {
        printf("-> %d ", r[i].temp);
        i++;
      }
      g_tot = (r[n_req - 1].temp - head_pos) + (r[n_req - 1].temp - r[0].temp) + (r[i - 1].temp - r[0].temp);
      printf("\nTotal Head Movement= %d", g_tot);
      break;
    default:
      printf("\nYou have entered a wrong choice\nPlease select Valid option\n");
      break;
    }
  }
  getch();
}