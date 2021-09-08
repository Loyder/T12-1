
#include "../include/game_life.h"

#include <dir.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
int main(int argc, char* argv[]) {
  char** matrix = (char**)malloc(HEIGHT * sizeof(char*));
  for (int i = 0; i < HEIGHT; i++) {
    matrix[i] = (char*)malloc(WIDTH * sizeof(char));
  }
  char buf[PATH_MAX], path[PATH_MAX],
      path_datasets[PATH_MAX] = "datasets\\2.txt";
  if (argc > 0) {
    char** lppPart = NULL;
    GetFullPathName(argv[0], PATH_MAX, buf, lppPart);
    int ptr = strlen(buf);
    for (int i = 0; i < 2; i++) {
      ptr--;
      while (buf[ptr] != '\\') {
        ptr--;
      }
    }
    buf[ptr + 1] = '\0';
    snprintf(path, PATH_MAX, "%s%s", buf, path_datasets);
  }
  system("cls");
  if (!setup(matrix, path)) {
    print(matrix);
    sleep(3);
    system("cls");
    path[0] = '\0';
    snprintf(path, PATH_MAX, "%smatrix.txt", buf);
    // while (1) {
    update(matrix);
    print(matrix);
    write_matrix_to_file(matrix, path);
    // count hash summ (unique combination) and delete file
    // write hash summ to matrix
    // if hash is replying (verify from end of matrix) then print period and
    // exit
    // usleep(20 * 1000);
    // system("cls");
    // }
  } else {
    printf("n/a");
  }
  for (int i = 0; i < HEIGHT; i++) {
    free(matrix[i]);
  }
  free(matrix);
  return 0;
}
void write_matrix_to_file(char** matrix, char* path) {
  FILE* file = fopen(path, "w");
  for (int i = 0; i < HEIGHT; i++) {
    fwrite(matrix[i], 1, WIDTH, file);
    // fputs(matrix[i], file);
  }
  fclose(file);
}
// void test(int num, char* message, char* test_hash_summ) {
//   char path[60] = "src/test_message.txt";
//   FILE* file = fopen(path, "w");
//   fputs(message, file);
//   fclose(file);
//   char hash_summ[65];
//   create_hash(path, hash_summ);
//   if (!strcmp(test_hash_summ, hash_summ)) {
//     printf("#%d: Test is OK", num);
//   } else {
//     printf("#%d: Test FAILED!!!", num);
//   }
//   if (remove(path)) {
//     printf("\nCan't remove file");
//   }
// }
int setup(char** matrix, char* path) {
  int flag_err = 0;
  FILE* file = fopen(path, "r");
  if (file) {
    char ch;
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        if (i == 0 || i == HEIGHT - 1) {
          matrix[i][j] = '=';
        } else if (j == 0 || j == WIDTH - 1) {
          matrix[i][j] = '|';
        } else {
          do {
            fscanf(file, "%c", &ch);
          } while (ch == '\n');
          if (ch == '-') {
            matrix[i][j] = ' ';
          } else if (ch == '1') {
            matrix[i][j] = '*';
          }
        }
      }
    }
    fclose(file);
  } else {
    flag_err = 1;
  }
  return flag_err;
}
void print(char** matrix) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", matrix[i][j]);
    }
    if (i < HEIGHT - 1) {
      printf("\n");
    }
  }
}
void update(char** matrix) {
  char new_matrix[HEIGHT][WIDTH];
  int i, j, y, x, yy, xx, neighbour;
  for (i = 1; i < HEIGHT - 1; i++) {
    for (j = 1; j < WIDTH - 1; j++) {
      neighbour = 0;
      for (y = i - 1; y <= i + 1; y++) {
        if (y == 0) {
          yy = HEIGHT - 2;
        } else if (y == HEIGHT - 1) {
          yy = 1;
        } else {
          yy = y;
        }
        for (x = j - 1; x <= j + 1; x++) {
          if (x == 0) {
            xx = WIDTH - 2;
          } else if (x == WIDTH - 1) {
            xx = 1;
          } else {
            xx = x;
          }
          if (!(y == i && x == j) && matrix[yy][xx] == '*') {
            neighbour++;
          }
        }
      }
      if (neighbour == 3 || (neighbour == 2 && matrix[i][j] == '*')) {
        new_matrix[i][j] = '*';
      } else {
        new_matrix[i][j] = ' ';
      }
    }
  }
  for (i = 1; i < HEIGHT - 1; i++) {
    for (j = 1; j < WIDTH - 1; j++) {
      matrix[i][j] = new_matrix[i][j];
    }
  }
}
