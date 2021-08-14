/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
  int n, data[NMAX];
  if (!input(data, &n)) {
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

double mean(int *a, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum / n;
}

double variance(int *a, int n) {
  double sum = 0, mean_res;
  for (int i = 0; i < n; i++) {
    sum += a[i] * a[i];
  }
  mean_res = mean(a, n);
  mean_res *= mean_res;
  return sum / n - mean_res;
}

void output(int *a, int n) {
  int res = 0;
  double mean_res, sigma3_res;
  mean_res = mean(a, n);
  sigma3_res = sqrt(variance(a, n)) * 3.0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0 && a[i] >= mean_res && a[i] <= mean_res + sigma3_res &&
        a[i] != 0) {
      res = a[i];
      break;
    }
  }
  printf("%d", res);
}
