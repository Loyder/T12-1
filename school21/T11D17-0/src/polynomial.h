#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <stdlib.h>
void input(char *str);
void parse_polynome(char *str);
struct list {
  int pow, number;
  struct list *ptr;
};
struct list *init();
struct list *addelem(struct list *lst, int number);
#endif
