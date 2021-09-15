#ifndef HASH_H
#define HASH_H
#include <stdio.h>
void create_hash(char *path, char *hash_summ);
void create_h_arr(unsigned *h, int n);
void create_k_arr(unsigned *k, int n);
void create_bin_arr(unsigned *h, unsigned *k, char *path, char *hash_summ);
void create_arr_simple_num(unsigned *h, int n);
unsigned int create_32bit_num(double num);
void get_size_of_binary_file(FILE *file, size_t *size);
unsigned rotr(unsigned num, unsigned char shift);
#endif  // !HASH_H
