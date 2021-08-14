#include <math.h>
#include <stdio.h>

double func(double a);

int main() {
  double x;
  printf("Input integer number:\n");
  if (scanf("%lf", &x) == 1) {
    printf("%.1lf", func(x));
  } else {
    printf("n/a");
  }
  return 0;
}

double func(double a) {
  return 7E-3 * pow(a, 4) +
         ((22.8 * pow(a, 1 / 3) - 1E3) * a + 3) / (a * a / 2) -
         a * pow((10 + a), 2.0 / a) - 1.01;
}
