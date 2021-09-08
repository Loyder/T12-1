#ifndef GAME_LIFE_H
#define GAME_LIFE_H
#define HEIGHT 27
#define WIDTH 82
int setup(char** matrix, char* path);
void start(char** matrix);
void print(char** matrix);
void update(char** matrix);
char my_getch();
void write_matrix_to_file(char** matrix, char* path);
#endif  // !GAME_LIFE_H