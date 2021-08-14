#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void squaring(int *a, int n);
void output(int *a, int n);

int main() {
  int n, data[NMAX];
  if (!input(data, &n)) {
    squaring(data, n);
    output(data, n);
  } else {
    printf("n/a");
  }
  return 0;
}

int input(int *a, int *n) {
  int err = 0;
  if (scanf("%d", n) && *n > 0 && *n <= NMAX && getchar() == '\n') {
    for (int *p = a; p - a < *n; p++) {
      if (scanf("%d", p)) {
        char ch = getchar();
        if ((ch == '\n' && p - a < *n - 1) || (ch != '\n' && p - a >= *n - 1) ||
            (ch != ' ' && ch != '\n')) {
          err = 1;
          break;
        }
      } else {
        err = 1;
        break;
      }
    }
  } else {
    err = 1;
  }
  return err;
}

void squaring(int *a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] *= a[i];
  }
}

void output(int *a, int n) {
  int i;
  for (i = 0; i < n - 1; i++) printf("%d ", a[i]);
  printf("%d", a[i]);
}
