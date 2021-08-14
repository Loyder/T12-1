#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <stdlib.h>
void input(char *str);
void parse_polynome(char *str);
struct list {
  int number;
  struct list *head;
  struct list *end;
};
struct list *init();
struct list *addelem(struct list *lst, int number);
void push(struct list *lst, void *data, struct list *head);
#endif
