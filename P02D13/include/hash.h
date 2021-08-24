#ifndef HASH_H
#define HASH_H
#include <stddef.h>
void create_hash();
void create_h_arr(unsigned int *h_arr, int n);
void create_k_arr(unsigned int *k_arr, int n);
void create_bin_arr(size_t **message);
void create_arr_simple_num(unsigned int *h_arr, int n);
unsigned int create_32bit_num(double num);
#endif  // !HASH_H
