
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
  char path[PATH_MAX], path_datasets[PATH_MAX] = "datasets\\2.txt";
  if (argc > 0) {
    char buf[PATH_MAX], **lppPart = NULL;
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
    system("cls");
    while (1) {
      update(matrix);
      print(matrix);
      // usleep(20 * 1000);
      system("cls");
    }
  } else {
    printf("n/a");
  }
  for (int i = 0; i < HEIGHT; i++) {
    free(matrix[i]);
  }
  free(matrix);
  return 0;
}
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
