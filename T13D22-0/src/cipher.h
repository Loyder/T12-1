#ifndef CIPHER_H
#define CIPHER_H
void start_print(void);
void cycle_verify(void);
void input_number(int *num_menu, int *err_input, int *flag_exit);
void input_string(char *string, int *err_input, int *flag_exit);
int check_getchar(int *err_input, int *flag_exit);
void readfile_and_print(char *path, int *err_input);
void writefile_and_print(char *string, int *err_input, char *path);
#endif