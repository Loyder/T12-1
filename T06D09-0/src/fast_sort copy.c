#include <stdio.h>
#define NMAX 10

int input(int *data);
void copy_array(int *data1, int *data2);
void fast_sort(int *data, int left, int right);
void pyramid_sort(int *data);
void output(int *data);

int main() {
  int data1[NMAX], data2[NMAX];
  if (!input(data1)) {
    copy_array(data1, data2);
    fast_sort(data1, 0, NMAX - 1);
    // pyramid_sort(data2);
    output(data1);
    // printf("\n");
    // output(data2);
  } else {
    printf("n/a");
  }
  return 0;
}
int input(int *data) {
  int err = 0, i;
  char ch;
  for (i = 0; i < NMAX; i++) {
    if (scanf("%d", &data[i])) {
      ch = getchar();
      if ((ch != '\n' && ch != ' ') || (ch == '\n' && i < NMAX - 1) ||
          (ch != '\n' && i >= NMAX - 1)) {
        err = 1;
        break;
      }
    } else {
      err = 1;
      break;
    }
  }
  return err;
}
void copy_array(int *data1, int *data2) {
  for (int i = 0; i < NMAX; i++) {
    data2[i] = data1[i];
  }
}
void fast_sort(int *data, int left, int right) {
  int L = left, B, tmp;
  if (right - left > 1) {
    B = (left + right) / 2;
  } else if (right - left == 1) {
    B = right;
  } else
    return;
  while (B > L) {
    if (data[L] > data[B]) {
      if (B - L > 1) {
        tmp = data[B];
        data[B] = data[L];
        data[L] = data[B - 1];
        data[B - 1] = tmp;
        B--;
      } else if (B - L == 1) {
        tmp = data[B];
        data[B] = data[L];
        data[L] = tmp;
        B--;
      }
    } else
      L++;
  }
  fast_sort(data, left, B - 1);
  fast_sort(data, B + 1, right);
}
void pyramid_sort(int *data) {}
void output(int *data) {
  int i;
  for (i = 0; i < NMAX - 1; i++) {
    printf("%d ", data[i]);
  }
  printf("%d", data[i]);
}
