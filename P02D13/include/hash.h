#ifndef HASH_H
#define HASH_H
#include <stdio.h>
void create_hash();
void create_h_arr(unsigned *h, int n);
void create_k_arr(unsigned *k, int n);
unsigned **create_bin_arr(unsigned **w, unsigned *h, unsigned *k);
void create_arr_simple_num(unsigned *h, int n);
unsigned int create_32bit_num(double num);
void get_size_of_binary_file(FILE *file, size_t *size);
unsigned rotr(unsigned num, unsigned char shift);
void my_printf(unsigned num);
#endif  // !HASH_H
