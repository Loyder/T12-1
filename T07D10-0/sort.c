#include <stdio.h>
#define NMAX 10

int input(int *data);
void sort(int *data);
void output(int *data);

int main() {
  int data[NMAX];
  if (!input(data)) {
    sort(data);
    output(data);
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
void sort(int *data) {
  int i, j, tmp;
  for (i = 0; i < NMAX - 1; i++) {
    for (j = i + 1; j < NMAX; j++) {
      if (data[i] > data[j]) {
        tmp = data[j];
        data[j] = data[i];
        data[i] = tmp;
      }
    }
  }
}
void output(int *data) {
  int i;
  for (i = 0; i < NMAX - 1; i++) {
    printf("%d ", data[i]);
  }
  printf("%d", data[i]);
}
