#include<stdio.h>

#include<conio.h>

struct fil {
  int all, finish;
}
f[10];
struct block {
  int finish;
}
b[20];
main() {
  int n_block, s_block, num, i, j, count, n_file, rem, div;
  printf("\nEnter the number of blocks on disk and size of each block \n");
  printf("\nNo. of blocks= ");
  scanf("%d", & n_block);
  printf("\nSize of each block= ");
  scanf("%d", & s_block);
  for (i = 0; i < n_block; i++)
    b[i].finish = 0;
  printf("\nEnter the number of files to allocate \n");
  scanf("%d", & n_file);
  printf("\nGive the size of each block \n");
  for (i = 0; i < n_file; i++) {
    printf("\nSize of file%d= ", i + 1);
    scanf("%d", & f[i].all);
    f[i].finish = 0;
  }
  num = n_block;
  for (i = 0; i < n_file; i++) {
    if (f[i].all > num * s_block) {
      printf("\n\nFile%d is too big to be allocated to disk\n", i + 1);
      continue;
    } else {
      rem = f[i].all % s_block;
      div = f[i].all / s_block;
      if (rem == 0) {
        num -= div;
        count = 0;
        printf("\n");
        printf("\nFile%d is allocated to block= ", i + 1);
        for (j = 0; j < n_block; j++) {
          if (b[j].finish == 0) {
            printf("%d\t", j);
            b[j].finish = 1;
            count++;
          }
          if (count == div)
            break;
        }
      } else {
        num = num - div - 1;
        count = 0;
        printf("\n");
        printf("\nFile%d is allocated to block= ", i + 1);
        for (j = 0; j < n_block; j++) {
          if (b[j].finish == 0) {
            printf("%d\t", j);
            b[j].finish = 1;
            count++;
          }
          if (count == div + 1)
            break;
        }
      }
    }
  }
  getch();
}