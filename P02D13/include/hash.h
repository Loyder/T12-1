#ifndef HASH_H
#define HASH_H
#include <stddef.h>
void create_hash();
void create_h_arr(unsigned *h_arr, int n);
void create_k_arr(unsigned *k_arr, int n);
void create_bin_arr(unsigned **message);
void create_arr_simple_num(unsigned *h_arr, int n);
unsigned int create_32bit_num(double num);
void get_size_of_binary_file(char *path, long int *size, int *err);
#endif  // !HASH_H
