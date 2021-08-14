#include "cipher.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  start_print();
  cycle_verify();
  return 0;
}
void start_print(void) {
  printf("\033[0;0H\033[2J");
  printf("\t\t\t\t------------PROGRAM OF OPEN AND READ FILES----------");
  printf("\n\n1. For read file: input number 1\n");
  printf("2. For write to file: input number 2\n");
  printf("3. For exit: input number -1\n");
}
void cycle_verify(void) {
  int num_menu = 0, err_input, flag_exit = 0, flag_open = 0;
  while (!flag_exit) {
    input_number(&num_menu, &err_input, &flag_exit);
    char path[1000];
    if (num_menu == 1 && flag_open == 0) {
      input_string(path, &err_input, &flag_exit);
      if (!err_input) {
        readfile_and_print(path, &err_input);
        flag_open = 1;
      }
    } else if (num_menu == 2) {
      char string[1000];
      input_string(string, &err_input, &flag_exit);
      if (flag_open == 1) {
        if (!err_input) {
          writefile_and_print(string, &err_input, path);
        }
      } else {
        err_input = 1;
      }
      flag_open = 0;
    } else if (num_menu == -1) {
      flag_exit = 1;
      err_input = 0;
    } else {
      err_input = 1;
      flag_open = 0;
    }
    if (err_input == 1 && flag_exit == 0) {
      printf("n/a\n");
    } else if (err_input == 1 && flag_exit == 1) {
      printf("n/a");
    }
  }
}
void input_number(int *num_menu, int *err_input, int *flag_exit) {
  *err_input = 0;
  int ch, res;
  do {
    res = scanf("%d", num_menu);
    ch = check_getchar(err_input, flag_exit);
    printf("%c\n", (char)ch);
    *err_input = 1;
  } while (res != 1 && (char)ch != '\n' && ch != EOF);
  // check_getchar(err_input, flag_exit);
}
void input_string(char *string, int *err_input, int *flag_exit) {
  int ch;
  if (scanf("%999[^\n]s", string) != 1) {
    *err_input = 1;
  }
  ch = check_getchar(err_input, flag_exit);
}
int check_getchar(int *err_input, int *flag_exit) {
  int ch;
  ch = getchar();
  if ((char)ch != '\n' && ch != EOF) {
    *err_input = 1;
  }
  if (ch == EOF) {
    *flag_exit = 1;
  }
  return ch;
}
void readfile_and_print(char *path, int *err_input) {
  FILE *file;
  file = fopen(path, "r");
  if (file != NULL) {
    int sym_of_file;
    int count = 0;
    while ((sym_of_file = getc(file)) != EOF) {
      printf("%c", sym_of_file);
      count++;
    }
    if (count) {
      printf("\n");
    } else {
      *err_input = 1;
    }
    fclose(file);
  } else {
    *err_input = 1;
  }
}
void writefile_and_print(char *string, int *err_input, char *path) {
  FILE *file;
  if (fopen(path, "r") != NULL) {
    file = fopen(path, "a");
    for (int i = 0; string[i] != '\0'; i++) {
      putc(string[i], file);
    }
    fclose(file);
    readfile_and_print(path, err_input);
  } else {
    *err_input = 1;
  }
}
