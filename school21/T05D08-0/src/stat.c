#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
  int n, data[NMAX];
  if (!input(data, &n)) {
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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
void output(int *a, int n) {
  int i;
  for (i = 0; i < n - 1; i++) printf("%d ", a[i]);
  printf("%d\n", a[i]);
}
int max(int *a, int n) {
  int maximum = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] > maximum) maximum = a[i];
  }
  return maximum;
}
int min(int *a, int n) {
  int minimum = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] < minimum) minimum = a[i];
  }
  return minimum;
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
void output_result(int max_v, int min_v, double mean_v, double variance_v) {
  printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
