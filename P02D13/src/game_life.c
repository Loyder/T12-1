#include <stdio.h>
#include <stdlib.h>
// #include <termios.h>
#include <unistd.h>
#define Height 27
#define Width 82

void setup(char matrix[Height][Width]);
void start(char matrix[Height][Width]);
void print(char matrix[Height][Width]);
void update2(char matrix[Height][Width]);
char getch();
void update(char matrix[Height][Width]);

// int main() {
//   char matrix[Height][Width];
//   setup(matrix);
//   do {
//     print(matrix);
//   } while (getch() == ' ');
//   return 0;
// }

int main() {
  char matrix[Height][Width];
  setup(matrix);
  start(matrix);
  print(matrix);
  while (1 == 1) {
    update2(matrix);
    print(matrix);
    sleep(1);
  }
  return 0;
}

void update2(char matrix[Height][Width]) {
  char new_matrix[Height][Width];
  int i, j, x, y;
  int neighbour;
  for (i = 0; i < Height; i++) {
    for (j = 0; j < Width; j++) {
      new_matrix[i][j] = matrix[i][j];
    }
  }
  for (i = 1; i < Height - 1; i++) {
    for (j = 1; j < Width - 1; j++) {
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

  for (i = 1; i < Height - 1; i++) {
    for (j = 1; j < Width - 1; j++) {
      matrix[i][j] = new_matrix[i][j];
    }
  }
}
void start(char matrix[Height][Width]) {
  FILE* start = fopen("start.txt", "r");
  for (int i = 1; i < Height - 1; i++) {
    for (int j = 1; j < Width - 1; j++) {
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
void setup(char matrix[Height][Width]) {
  for (int i = 0; i < Height; i++) {
    for (int j = 0; j < Width; j++) {
      if (i == 0 || i == Height - 1) {
        matrix[i][j] = '=';
      } else if (j == 0 || j == Width - 1) {
        matrix[i][j] = '|';
      } else {
        matrix[i][j] = ' ';
      }
    }
  }
}
void print(char matrix[Height][Width]) {
  for (int i = 0; i < Height; i++) {
    for (int j = 0; j < Width; j++) {
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
}
// char getch() {
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

// figure_block(){};

// void update(char matrix[Height][Width]) {
//   char new_matrix[Height][Width];
//   int status = 0;
//   int neighbor = 0;
//   for (int i = 1; i < Height - 1; i++) {
//     for (int j = 1; j < Width - 1; j++) {
//       new_matrix[i][j] = matrix[i][j];
//       if (matrix[i][j] == '*') {
//         status = 1;
//       }
//       if (i > 1 && j > 1) {
//         if (matrix[i - 1][j - 1] == '*') {
//           neighbor += 1;
//         }
//         if (matrix[i][j - 1] == '*') {
//           neighbor += 1;
//         }
//         if (matrix[i - 1][j] == '*') {
//           neighbor += 1;
//         }
//       }
//       if (i < Height - 2 && j < Width - 2) {
//         if (matrix[i + 1][j + 1] == '*') {
//           neighbor += 1;
//         }
//         if (matrix[i][j + 1] == '*') {
//           neighbor += 1;
//         }
//         if (matrix[i + 1][j] == '*') {
//           neighbor += 1;
//         }
//       }
//       if (i > 1 && j < Width - 2) {
//         if (matrix[i - 1][j + 1] == '*') {
//           neighbor += 1;
//         }
//       }
//       if (i < Height - 2 && j > 1) {
//         if (matrix[i + 1][j - 1] == '*') {
//           neighbor += 1;
//         }
//       }
//       // if(status == 0) {
//       if (neighbor == 3 && status == 0) {
//         new_matrix[i][j] = '*';
//       } else if (neighbor != 3 && neighbor != 2 && status == 1) {
//         new_matrix[i][j] = ' ';
//         printf("%d ", neighbor);
//       }
//       status = 0;
//       neighbor = 0;
//     }
//   }
//   for (int i = 1; i < Height - 1; i++) {
//     for (int j = 1; j < Width - 1; j++) {
//       matrix[i][j] = new_matrix[i][j];
//     }
//   }
// }
