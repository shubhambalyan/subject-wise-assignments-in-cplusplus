#include<stdio.h>

#include<string.h>

int main() {
  int choice, i, pageFault, p, ch, j, count = 0, counter[10], max, l = 0, k, m, size;
  char x[25], arr[10];
  printf("Enter the pattern\n");
  scanf("%s", x);
  int num = strlen(x);
  printf("Page Table Size:");
  scanf("%d", & size);
  do {
    printf("1.FIFO\n2.LRU\n3.Optimal\nEnter your choice:");
    scanf("%d", & choice);
    for (i = 0; i <= size - 1; i++)
      arr[i] = '`';
    pageFault = 0;
    l = 0;
    switch (choice) {
    case 1:
      for (i = 0, p = 0; i < num; i++) {
        for (j = 0, count = 0; j <= size - 1; j++) {
          if (arr[j] != x[i]) {
            count++;
          }
        }
        if (count == size) {
          arr[p] = x[i];
          pageFault++;
          p++;
        }
        if (p == size)
          p = 0;
      }
      printf("Total pageFault: %d\n", pageFault);
      break;

    case 2:
      for (i = 0; i < num; i++) {

        for (j = 0, count = 0; j <= size - 1; j++) {
          if (arr[j] != x[i])
            count++;
          counter[j] = 0;
        }
        if (count == size) {
          for (m = 0; m <= size - 1; m++) {
            for (k = i - 1; k >= 0; k--) {
              if (x[k] == arr[m])
                break;
              else
                counter[m]++;
            }
          }
          max = 0;
          for (l = 1; l <= size - 1; l++) {
            if (counter[max] < counter[l])
              max = l;
          }
          arr[max] = x[i];
          pageFault++;
        }
      }
      printf("Total pageFault: %d\n", pageFault);
      break;
    case 3:
      for (i = 0; i < num; i++) {

        for (j = 0, count = 0; j <= size - 1; j++) {
          if (arr[j] != x[i])
            count++;
          counter[j] = 0;
        }
        if (count == size) {
          for (m = 0; m <= size - 1; m++) {
            for (k = i + 1; k < num; k++) {
              if (x[k] == arr[m])
                break;
              else
                counter[m]++;
            }
          }
          max = 0;
          for (l = 1; l <= size - 1; l++) {
            if (counter[max] < counter[l])
              max = l;
          }
          arr[max] = x[i];
          pageFault++;
        }
      }
      printf("Total pageFault: %d\n", pageFault);
      break;
    }
    printf("press 1 to continue:");
    scanf("%d", & ch);
  } while (ch == 1);
  getch();
  return 0;
}