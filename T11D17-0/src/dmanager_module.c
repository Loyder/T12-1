#include "dmanager_module.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

int main() {
  struct door doors[DOORS_COUNT];
  initialize_doors(doors);
  sort_doors(doors);
  closing_doors(doors);
  print_doors(doors);
  return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
  srand(time(0));
  int seed = rand() % MAX_ID;
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].id = (i + seed) % MAX_ID;
    doors[i].status = rand() % 2;
  }
}
void sort_doors(struct door* doors) {
  struct door tmp;
  for (int i = 0; i < DOORS_COUNT - 1; i++) {
    for (int j = i + 1; j < DOORS_COUNT; j++) {
      if (doors[i].id > doors[j].id) {
        tmp = doors[j];
        doors[j] = doors[i];
        doors[i] = tmp;
      }
    }
  }
}
void closing_doors(struct door* doors) {
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].status = 0;
  }
}
void print_doors(struct door* doors) {
  int i;
  for (i = 0; i < DOORS_COUNT - 1; i++) {
    printf("%d, %d\n", doors[i].id, doors[i].status);
  }
  printf("%d, %d", doors[i].id, doors[i].status);
}
