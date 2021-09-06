
#include "../include/game_life.h"

#include <dir.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  char** matrix = (char**)malloc(HEIGHT * sizeof(char*));
  for (int i = 0; i < HEIGHT; i++) {
    matrix[i] = (char*)malloc(WIDTH * sizeof(char));
  }
  system("cls");
  if (!setup(matrix)) {
    print(matrix);
    usleep(60 * 1000);
    system("cls");
    while (1) {
      update(matrix);
      print(matrix);
      usleep(10 * 1000);
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
int setup(char** matrix) {
  int flag_err = 0;
  char path[_MAX_DIR] = "datasets/2.txt";
  FILE* start = fopen(path, "r");
  if (!start) {
    char path_new[_MAX_DIR + 3];
    snprintf(path_new, _MAX_DIR + 3, "../%s", path);
    start = fopen(path_new, "r");
  }
  if (start) {
    char ch;
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        if (i == 0 || i == HEIGHT - 1) {
          matrix[i][j] = '=';
        } else if (j == 0 || j == WIDTH - 1) {
          matrix[i][j] = '|';
        } else {
          do {
            fscanf(start, "%c", &ch);
          } while (ch == '\n');
          if (ch == '-') {
            matrix[i][j] = ' ';
          } else if (ch == '1') {
            matrix[i][j] = '*';
          }
        }
      }
    }
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
