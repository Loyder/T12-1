
#include "../include/game_life.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  char** matrix = (char**)malloc(HEIGHT * sizeof(char*));
  for (int i = 0; i < HEIGHT; i++) {
    matrix[i] = (char*)malloc(WIDTH * sizeof(char));
  }
  int mode;
  printf("Choose mode of game:\n1 - step-by-step mode\n2 - interactive mode\n");
  scanf("%d", &mode);
  if (mode == 1) {
    setup(matrix);
    // do {
    //   print(matrix);
    // } while (my_getch() == ' ');
  } else if (mode == 2) {
    setup(matrix);
    start(matrix);
    print(matrix);
    while (1 == 1) {
      update(matrix);
      print(matrix);
      sleep(1);
    }
  }
  for (int i = 0; i < HEIGHT; i++) {
    free(matrix[i]);
  }
  free(matrix);
  return 0;
}

void update(char** matrix) {
  char new_matrix[HEIGHT][WIDTH];
  int i, j, x, y;
  int neighbour;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      new_matrix[i][j] = matrix[i][j];
    }
  }
  for (i = 1; i < HEIGHT - 1; i++) {
    for (j = 1; j < WIDTH - 1; j++) {
      neighbour = 0;
      for (x = i - 1; x <= i + 1; x++) {
        for (y = j - 1; y <= j + 1; y++) {
          if (!(x == i && y == j) && matrix[x][y] == '*') {
            neighbour++;
          }
        }
      }
      if (neighbour == 3 && matrix[i][j] == ' ') {
        new_matrix[i][j] = '*';
      } else if (neighbour != 3 && neighbour != 2 && matrix[i][j] == '*') {
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
void start(char** matrix) {
  FILE* start = fopen("../datasets/1.txt", "r");
  for (int i = 1; i < HEIGHT - 1; i++) {
    for (int j = 1; j < WIDTH - 1; j++) {
      fscanf(start, "%c", &matrix[i][j]);
      if (matrix[i][j] == '-') {
        matrix[i][j] = ' ';
      } else if (matrix[i][j] == '1') {
        matrix[i][j] = '*';
      }
      // if (foef(start)) break;
    }
  }
}
void setup(char** matrix) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (i == 0 || i == HEIGHT - 1) {
        matrix[i][j] = '=';
      } else if (j == 0 || j == WIDTH - 1) {
        matrix[i][j] = '|';
      } else {
        matrix[i][j] = ' ';
      }
    }
  }
}
void print(char** matrix) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", matrix[i][j]);
    }
    printf("\n");
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
