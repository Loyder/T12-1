#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int input_numbers(int *n, int *m);
double **init_matrix(int n, int m);
void input(double **matrix, int *n, int *m);
double det(double **matrix, int n, int m);
void output(double det);
void delete_matrix(double **matrix, int n);

int main() {
  int n, m, err_input = 0;
  err_input = input_numbers(&n, &m);
  if (!err_input) {
    double **matrix = init_matrix(n, m);
    input(matrix, &n, &m);
    if (n != 0 && m != 0) {
      double determ;
      determ = det(matrix, n, m);
      output(determ);
    }
    delete_matrix(matrix, n);
  }
  return 0;
}
int input_numbers(int *n, int *m) {
  char ch1, ch2;
  int err_input = 0;
  if (scanf("%d%c%d%c", n, &ch1, m, &ch2) != 4 || *n <= 0 || *m <= 0 ||
      *n != *m || ch1 != ' ' || ch2 != '\n') {
    err_input = 1;
    printf("n/a");
  }
  return err_input;
}
double **init_matrix(int n, int m) {
  double **matrix = NULL;
  matrix = (double **)malloc(n * sizeof(double *));
  for (int i = 0; i < n; i++) {
    matrix[i] = (double *)malloc(m * sizeof(double));
  }
  return matrix;
}
void input(double **matrix, int *n, int *m) {
  int err = 0, i, j;
  char ch;
  for (i = 0; i < *n && err == 0; i++) {
    for (j = 0; j < *m - 1 && err == 0; j++) {
      if (scanf("%lf%c", &matrix[i][j], &ch) != 2 || ch != ' ') err = 1;
    }
    if (scanf("%lf%c", &matrix[i][j], &ch) != 2 || ch != '\n') err = 1;
  }
  if (err == 1) {
    *n = 0;
    *m = 0;
    printf("n/a");
  }
}
double det(double **matrix, int n, int m) {
  if (n == 1) {
    return matrix[0][0];
  }
  double **matrix2 = init_matrix(n - 1, m - 1);
  int i, j, k, sum = 0, x, y;
  for (k = 0; k < m; k++) {
    x = 0;
    y = 0;
    for (i = 1; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (j != k) {
          matrix2[x][y] = matrix[i][j];
          y++;
          if (y == m - 1) {
            y = 0;
            x++;
          }
        }
      }
    }
    sum += matrix[0][k] * pow(-1, k + 2) * det(matrix2, n - 1, m - 1);
  }
  delete_matrix(matrix2, n - 1);
  return sum;
}
void output(double det) { printf("%.6lf", det); }

void delete_matrix(double **matrix, int n) {
  for (int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);
}
