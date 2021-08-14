#include "polynomial.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *str = (char *)malloc(1 * sizeof(char));
  input(str);
  printf("%s\n", str);
  parse_polynome(str);
  free(str);
  return 0;
}

void input(char *str) {
  int i = 0;
  do {
    i++;
    str = (char *)realloc(str, i * sizeof(char));
    scanf("%c", &str[i - 1]);
  } while (str[i - 1] != '\n' && str[i - 1] != '\0');
  str[i - 1] = '\0';
}
void parse_polynome(char *str) {
  const int x = 3;
  struct list *polynome = init(), *root;
  root = polynome;
  int number1, number2, sum = 0;
  char tc, kl, *ur;
  char *pch = strtok(str, "*x^");
  printf("%s\n", pch);
  while (pch != NULL) {
    sscanf(pch, "%d%s", &number1, ur);
    if (ur != '\0' && (ur[0] == '+' || ur[0] == '-')) {
      if (ur[0] == '+') {
        sscanf(pch, "%d%c%d%c", &number1, &kl, &number2, &tc);
      } else if (ur[0] == '-') {
        sscanf(pch, "%d%d%c", &number1, &number2, &tc);
      }

      polynome->number = number1;
      pch = strtok(NULL, "*x^");
      printf("%s\n", pch);
      if (pch != NULL) {
        sscanf(pch, "%d%c", &number2, &tc);
        polynome->pow = number2;
        if (tc != '\0') {
          polynome = addelem(polynome, number1);
          polynome->number = number2;
        }
      }
    }
    do {
      sum += root->number * pow(x, root->pow);
      root = root->ptr;
    } while (root != NULL);
    printf("%d", sum);
  }
  struct list *init() {
    struct list *lst;
    lst = (struct list *)malloc(sizeof(struct list));
    lst->ptr = NULL;
    return (lst);
  }
  struct list *addelem(struct list * lst, int number) {
    struct list *temp, *p;
    temp = (struct list *)malloc(sizeof(struct list));
    p = lst->ptr;
    lst->ptr = temp;
    temp->number = number;
    temp->ptr = p;
    return temp;
  }
