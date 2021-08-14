#include "state_sort.h"

#include <stdio.h>

int main(void) {
  char path[303];
  int num_menu = -666, err = 0;
  long int size;
  input_path(path, &err);
  if (!err) {
    input_number(&num_menu, &err);
    if (!err) {
      ROWS row[2];
      FILE *file;
      int *ptr[2], count_struct = (int)sizeof(row) / (int)sizeof(int);
      printf("%d", count_struct);
      ptr[0] = (int *)&row[0];
      ptr[1] = (int *)&row[1];
      get_size_of_binary_file(path, &size, &err);
      printf("%ld\n", size);
      if (num_menu == 0) {
        if (!err) {
          output(row, file, ptr[0], path, size, count_struct);
        }
      } else if (num_menu == 1) {
        // sort file
        if ((file = fopen(path, "r+b")) != NULL) {
          fast_sort(file, ptr, 0, size, count_struct);
          fclose(file);
        }
        // output
      } else if (num_menu == 2) {
        // add row
        // sort file
        // output
      }
    }
  }
  if (err == 1) {
    printf("n/a");
  }
  return 0;
}
void fast_sort(FILE *file, int **ptr, long int left, long int right,
               int count_struct) {
  if (left < right) {
    long int L = left, R = right;
    read_row(file, left, ptr[0], count_struct);
    read_row(file, right, ptr[1], count_struct);
    double B = (ptr[0][0] + ptr[1][0]) / 2.0;
    printf("%ld %d\n%ld %d\n%lf", left, ptr[0][0], right, ptr[1][0], B);
    read_row(file, L, ptr[0], count_struct);
    read_row(file, R, ptr[1], count_struct);
    // do {
    //   while (ptr[0][0] < B) {
    //     L++;
    //   }
    //   while (ptr[1][0] > B) {
    //     R--;
    //   }
    //   if (L < R) {
    //     swap_rows(file, L, R, ptr, count_struct);
    //     L++;
    //     R--;
    //   }
    // } while (L < R);
    // fast_sort(file, ptr, left, R, count_struct);
    // fast_sort(file, ptr, R + 1, right, count_struct);
  }
}

void input_path(char *path, int *err) {
  char path_postfix[300];
  if (scanf("%s", path_postfix) == 1) {
    snprintf(path, 303, "../%s", path_postfix);
  } else {
    *err = 1;
  }
}
void input_number(int *num_menu, int *err) {
  if (scanf("%d", num_menu) == 1) {
  } else {
    *err = 1;
  }
}
void output(ROWS *row, FILE *file, int *ptr, char *path, long int size,
            int count_struct) {
  if ((file = fopen(path, "rb")) != NULL) {
    for (long int i = 0; i < size; i++) {
      read_row(file, i, ptr, count_struct);
      print_row(ptr, count_struct);
      printf("\n");
    }
    fclose(file);
  }
}
void read_row(FILE *file, long int row, int *ptr, int count_struct) {
  fseek(file, row * sizeof(ROWS), SEEK_SET);
  for (int i = 0; i < count_struct; i++) {
    fread(&ptr[i], sizeof(int), 1, file);
  }
}
void write_row(FILE *file, long int row, int *ptr, int count_struct) {
  fseek(file, row * sizeof(ROWS), SEEK_SET);
  for (int i = 0; i < count_struct; i++) {
    fwrite(&ptr[i], sizeof(int), 1, file);
  }
}
void swap_rows(FILE *file, long int row0, long int row1, int **ptr,
               int count_struct) {
  read_row(file, row0, ptr[0], count_struct);
  read_row(file, row1, ptr[1], count_struct);
  write_row(file, row0, ptr[1], count_struct);
  write_row(file, row1, ptr[0], count_struct);
}
void print_row(int *ptr, int count_struct) {
  int i;
  for (i = 0; i < count_struct - 1; i++) {
    printf("%d ", ptr[i]);
  }
  printf("%d", ptr[i]);
}

void get_size_of_binary_file(char *path, long int *size, int *err) {
  FILE *file;
  if ((file = fopen(path, "rb")) != NULL) {
    fseek(file, 0, SEEK_END);
    *size = ftell(file) / sizeof(ROWS);
    printf("%ld\n", ftell(file));
    fclose(file);
  } else {
    *err = 1;
  }
}
