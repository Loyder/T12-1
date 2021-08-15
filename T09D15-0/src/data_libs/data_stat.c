#include "data_stat.h"

double max(double *data, int n) {
  double max = data[0];
  for (int i = 1; i < n; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }
  return max;
}
double min(double *data, int n) {
  double min = data[0];
  for (int i = 1; i < n; i++) {
    if (data[i] < min) {
      min = data[i];
    }
  }
  return min;
}
double mean(double *data, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += data[i];
  }
  return sum / n;
}
double variance(double *data, int n) {
  double sum = 0, mean_res;
  for (int i = 0; i < n; i++) {
    sum += data[i] * data[i];
  }
  mean_res = mean(data, n);
  mean_res *= mean_res;
  return sum / n - mean_res;
}
void sort(double *data, int n) {
  double tmp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (data[j] < data[i]) {
        tmp = data[j];
        data[j] = data[i];
        data[i] = tmp;
      }
    }
  }
}
