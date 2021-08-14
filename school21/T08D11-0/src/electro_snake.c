#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);
/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
/*
    7 8 9
    6 1 2
    5 4 3
*/
void sort_spiral(int **matrix, int n, int m, int **result_matrix);
int input_numbers(int *n, int *m);
int **init_matrix(int n, int m);
void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void delete_matrix(int **matrix, int n);

int main() {
  int n, m, err_input = 0;
  err_input = input_numbers(&n, &m);
  if (!err_input) {
    int **matrix = init_matrix(n, m);
    input(matrix, &n, &m);
    if (n != 0 && m != 0) {
      int **result = init_matrix(n, m);
      sort_vertical(matrix, n, m, result);
      output(result, n, m);
      printf("\n\n");
      sort_horizontal(matrix, n, m, result);
      output(result, n, m);
      printf("\n\n");
      sort_spiral(matrix, n, m, result);
      output(result, n, m);
      delete_matrix(result, n);
    }
    delete_matrix(matrix, n);
  }
  return 0;
}
int input_numbers(int *n, int *m) {
  char ch1, ch2;
  int err_input = 0;
  if (scanf("%d%c%d%c", n, &ch1, m, &ch2) != 4 || *n <= 0 || *m <= 0 ||
      ch1 != ' ' || ch2 != '\n') {
    err_input = 1;
    printf("n/a");
  }
  return err_input;
}
int **init_matrix(int n, int m) {
  int **matrix = NULL;
  matrix = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    matrix[i] = (int *)malloc(m * sizeof(int));
  }
  return matrix;
}
void input(int **matrix, int *n, int *m) {
  int err = 0, i, j;
  char ch;
  for (i = 0; i < *n && err == 0; i++) {
    for (j = 0; j < *m - 1 && err == 0; j++) {
      if (scanf("%d%c", &matrix[i][j], &ch) != 2 || ch != ' ') err = 1;
    }
    if (scanf("%d%c", &matrix[i][j], &ch) != 2 || ch != '\n') err = 1;
  }
  if (err == 1) {
    *n = 0;
    *m = 0;
    printf("n/a");
  }
}
void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
  int array[n * m], k = 0, i, j, tmp;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      array[k] = matrix[i][j];
      k++;
    }
  }
  for (i = 0; i < n * m - 1; i++) {
    for (j = i + 1; j < n * m; j++) {
      if (array[i] > array[j]) {
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
      }
    }
  }
  k = 0;
  for (j = 0; j < m; j++) {
    if (j % 2 == 0) {
      for (i = 0; i < n; i++) {
        result_matrix[i][j] = array[k];
        k++;
      }
    } else {
      for (i = n - 1; i >= 0; i--) {
        result_matrix[i][j] = array[k];
        k++;
      }
    }
  }
}
void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
  int array[n * m], k = 0, i, j, tmp;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      array[k] = matrix[i][j];
      k++;
    }
  }
  for (i = 0; i < n * m - 1; i++) {
    for (j = i + 1; j < n * m; j++) {
      if (array[i] > array[j]) {
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
      }
    }
  }
  k = 0;
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (j = 0; j < m; j++) {
        result_matrix[i][j] = array[k];
        k++;
      }
    } else {
      for (j = m - 1; j >= 0; j--) {
        result_matrix[i][j] = array[k];
        k++;
      }
    }
  }
}
void sort_spiral(int **matrix, int n, int m, int **result_matrix) {
  int array[n * m], k = 0, i, j, tmp;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      array[k] = matrix[i][j];
      k++;
    }
  }
  for (i = 0; i < n * m - 1; i++) {
    for (j = i + 1; j < n * m; j++) {
      if (array[i] > array[j]) {
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
      }
    }
  }
  k = 0;
  i = (n - 1) / 2;
  j = (m - 1) / 2;
  int w = i, s = i + 1, a = j, d = j + 1;
  do {
    while (j <= d && k < n * m) {
      if (j < m) {
        result_matrix[i][j] = array[k];
        j++;
        k++;
      } else {
        i = i + s - w - 1;
        break;
      }
    }
    j--;
    i++;
    a--;
    while (i <= s && k < n * m) {
      if (i < n) {
        result_matrix[i][j] = array[k];
        i++;
        k++;
      } else {
        j = j - d + a + 1;
        break;
      }
    }
    i--;
    j--;
    w--;
    while (j >= a && k < n * m) {
      if (j >= 0) {
        result_matrix[i][j] = array[k];
        j--;
        k++;
      } else {
        i = i - s + w + 1;
        break;
      }
    }
    j++;
    i--;
    d++;
    while (i >= w && k < n * m) {
      if (i >= 0) {
        result_matrix[i][j] = array[k];
        i--;
        k++;
      } else {
        j = j + d - a - 1;
        break;
      }
    }
    i++;
    j++;
    s++;
  } while (k < n * m);
}
void output(int **matrix, int n, int m) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (j != m - 1) {
        printf("%d ", matrix[i][j]);
      } else if (i != n - 1) {
        printf("%d\n", matrix[i][j]);
      } else {
        printf("%d", matrix[i][j]);
      }
    }
  }
}
void delete_matrix(int **matrix, int n) {
  for (int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);
}
