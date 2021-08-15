#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"

int main() {
  struct list *home = init();
  push(home, 1, home);
  return 0;
}

struct list *init() {
  struct list *lst;
  lst = (struct list *)malloc(sizeof(struct list));
  lst->head = NULL;
  lst->end = lst->head;
  return (lst);
}
struct list *addelem(struct list *lst, int number) {
  struct list *temp, *p;
  temp = (struct list *)malloc(sizeof(struct list));
  p = lst->ptr;
  lst->ptr = temp;
  temp->number = number;
  temp->ptr = p;
  return temp;
}
void push(struct list *lst, void *data, struct list *head) {
  struct list *node = malloc(sizeof(struct list));
  node->number = data;
  node->ptr = lst->head;

  lst->head = node;
  lst->size += 1;
}
