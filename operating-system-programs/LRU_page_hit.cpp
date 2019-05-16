#include<stdio.h>

#include<conio.h>

main() {
  int max, count = 0, hit = 0, str[20], k, m, l, cnt[3], offset, arr[20][3], set, i, j, n;
  float ratio;
  printf("Enter the number of elements in string \n");
  scanf("%d", & n);
  for (i = 0; i < n; i++)
    for (j = 0; j < 3; j++) {
      cnt[j] = 0;
      arr[i][j] = -1;
    }
  printf("\nEnter the %d pages \n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", & str[i]);
  }
  offset = 0;
  for (i = 0; i < n; i++) {
    set = 0;
    if (i < 3) {
      if (i == 0) {
        arr[i][i] = str[i];
        offset = i;
        cnt[i] = 1;
      } else {
        for (j = 0; j <= i; j++) {
          arr[i][j] = arr[i - 1][j];
        }
        arr[i][offset + 1] = str[i];
        offset = i;
      }
    } else {
      offset = -1;
      for (j = 2; j >= 0; j--)
        if (str[i] == arr[i - 1][j]) {
          offset = j;
          hit++;
        }
      for (j = 0; j < 3; j++)
        arr[i][j] = arr[i - 1][j];
      if (offset >= 0)
        printf("");
      if (offset == -1) {
        if (i == 3) {
          arr[i][0] = str[i];
        }
        if (i > 3) {
          count = 0;
          for (k = 0; k < 3; k++)
            cnt[k] = 0;
          for (m = i - 1; m >= 0; m--) {
            for (k = 0; k < 3; k++)
              if (arr[i][k] == str[m]) {
                cnt[k] = 1;
                count++;
                if (count == 2)
                  break;
              }
            if (count == 2)
              break;
          }
          for (k = 0; k < 3; k++)
            if (cnt[k] == 0)
              arr[i][k] = str[i];
        }
      }
    }
  }
  printf("\nLRU ....................\n\n");
  for (i = 0; i < n; i++)
    printf(" %d  ", str[i]);
  printf("\n\n");
  for (j = 0; j < 3; j++) {
    for (i = 0; i < n; i++) {
      printf(" %d  ", arr[i][j]);
    }
    printf("\n");
  }
  printf("\nHit= %d", hit);
  ratio = (float(hit) / float(n)) * 100.00;
  printf("\nHit Ratio= %f", ratio);
  getch();
}