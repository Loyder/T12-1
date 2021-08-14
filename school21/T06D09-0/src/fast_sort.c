#include <stdio.h>
#define NMAX 10

int input(int *data);
// void copy_array(int *data1, int *data2);
void fast_sort(int *data, int left, int right);
// void pyramid_sort(int *data);
void output(int *data);

int main() {
  int data1[NMAX];
  // int data2[NMAX];
  if (!input(data1)) {
    // copy_array(data1, data2);
    fast_sort(data1, 0, NMAX - 1);
    // pyramid_sort(data2);
    output(data1);
    // printf("\n");
    // output(data2);
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
      }
    } else {
      err = 1;
    }
    if (err == 1) {
      break;
    }
  }
  if (err == 1) {
    printf("n/a");
  }
  return err;
}
// void copy_array(int *data1, int *data2) {
//   for (int i = 0; i < NMAX; i++) {
//     data2[i] = data1[i];
//   }
// }
void fast_sort(int *data, int left, int right) {
  if (left < right) {
    int L = left, R = right;
    double B = (data[left] + data[right]) / 2.0;
    do {
      while (data[L] < B) {
        L++;
      }
      while (data[R] > B) {
        R--;
      }
      if (L < R) {
        int tmp = data[R];
        data[R] = data[L];
        data[L] = tmp;
        L++;
        R--;
      }
    } while (L < R);
    fast_sort(data, left, R);
    fast_sort(data, R + 1, right);
  }
}
// void pyramid_sort(int *data) { printf("%d", data[0]); }
void output(int *data) {
  int i;
  for (i = 0; i < NMAX - 1; i++) {
    printf("%d ", data[i]);
  }
  printf("%d", data[i]);
}
