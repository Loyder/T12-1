#include "door_struct.h"
#ifndef DMANAGER_MODULE_H
#define DMANAGER_MODULE_H
#define DOORS_COUNT 15
#define MAX_ID 100000
void initialize_doors(struct door* doors);
void sort_doors(struct door* doors);
void closing_doors(struct door* doors);
void print_doors(struct door* doors);
#endif
