#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }
void print_log(char (*print)(char), char* message) {
  int i;
  for (i = 0; Log_prefix[i] != '\0'; i++) {
    print(Log_prefix[i]);
  }
  print(' ');
  struct tm* local;
  time_t t;
  char str[128] = "";
  t = time(NULL);
  local = localtime(&t);
  strftime(str, 128, "%H:%M:%S", local);
  for (i = 0; str[i] != '\0'; i++) {
    print(str[i]);
  }
  print(' ');
  for (i = 0; message[i] != '\0'; i++) {
    print(message[i]);
  }
}
