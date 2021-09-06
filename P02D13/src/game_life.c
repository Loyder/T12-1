
#include "../include/game_life.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  char** matrix = (char**)malloc(HEIGHT * sizeof(char*));
  for (int i = 0; i < HEIGHT; i++) {
    matrix[i] = (char*)malloc(WIDTH * sizeof(char));
  }
  int mode = 2;
  // printf("Choose mode of game:\n1 - step-by-step mode\n2 - interactive
  // mode\n"); scanf("%d", &mode);
  if (mode == 1) {
    setup(matrix);
    // do {
    //   print(matrix);
    // } while (my_getch() == ' ');
  } else if (mode == 2) {
    system("cls");
    setup(matrix);
    print(matrix);
    usleep(60 * 1000);
    system("cls");
    while (1) {
      update(matrix);
      print(matrix);
      usleep(60 * 1000);
      system("cls");
    }
    // usleep(5000 * 1000);
  }
  for (int i = 0; i < HEIGHT; i++) {
    free(matrix[i]);
  }
  free(matrix);
  return 0;
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
      if (matrix[i][j] == ' ') {
        if (neighbour == 3) {
          new_matrix[i][j] = '*';
        } else {
          new_matrix[i][j] = ' ';
        }
      } else if (matrix[i][j] == '*') {
        if (neighbour == 3 || neighbour == 2) {
          new_matrix[i][j] = '*';
        } else {
          new_matrix[i][j] = ' ';
        }
      }
    }
  }
  for (i = 1; i < HEIGHT - 1; i++) {
    for (j = 1; j < WIDTH - 1; j++) {
      matrix[i][j] = new_matrix[i][j];
    }
  }
}
void setup(char** matrix) {
  FILE* start = fopen("datasets/4.txt", "r");
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
// char my_getch() {
//   char buf = 0;
//   struct termios old = {0};
//   if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
//   old.c_lflag &= ~ICANON;
//   old.c_lflag &= ~ECHO;
//   old.c_cc[VMIN] = 1;
//   old.c_cc[VTIME] = 0;
//   if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
//   if (read(0, &buf, 1) < 0) perror("read()");
//   old.c_lflag |= ICANON;
//   old.c_lflag |= ECHO;
//   if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
//   return (buf);
// }
