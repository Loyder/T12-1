#include <stdio.h>

int main(void) {
  int x, a;
  char ch;
  a = scanf("%d%c", &x, &ch);
  if (a == 0 || a == 2 && ch != '\n') {
    printf("n/a");
  } else if (a == 1 && (ch != '\n' || ch == '\0') || a == 2 && ch == '\n') {
    printf("%d", x);
  }
  return 0;
}
