#ifndef DATABASE_H
#define DATABASE_H
typedef struct ENTITY {
  char choice[20];
  typedef struct TABLE_LEVELS {
    int num_level_memory;
    int count_cell_in_level;
    int flag_security;
  } LEVELS;
  typedef struct TABLE_MODULES {
    int id_module;
    char name_module[30];
    int num_level_module;
    int num_cell_module;
    int flag_delete;
  } MODULES;
  typedef struct TABLE_STATUS_EVENTS {
    int id_events;
    int id_module;
    int new_status_module;
    char date_change_status[10];
    char time_change_status[8];
  } STATUS_EVENTS;
} ENTITY;

//////////////////////////////////////////////////////
ENTITY *select(FILE *db, int id);
int delete (FILE *db, int id);
int insert(FILE *db, ENTITY *entity);
int update(FILE *db, int id, ENTITY *entity);
//////////////////////////////////////////////////////
#endif