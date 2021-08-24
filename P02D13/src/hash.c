#include "../include/hash.h"
#define __USE_MINGW_ANSI_STDIO 1
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
void create_hash() {
  int n = 8;
  unsigned int h_arr[n];
  create_h_arr(h_arr, n);
  n = 64;
  unsigned int k_arr[n];
  create_k_arr(k_arr, n);
  size_t **message = (size_t **)malloc(1 * sizeof(size_t *));
  create_bin_arr(message);
  free(message);
  system("pause");
}
void create_bin_arr(size_t **message) {
  size_t i = 0;
  do {
    message[i] = (size_t *)malloc(1 * sizeof(size_t));
    message[i][0] = 0;

    FILE *file;
    char path[100] = "./message.txt";
    if ((file = fopen(path, "r")) != NULL) {
      while (!feof(file)) {
        char ch = 0;
        message[i][0] <<= 1;
        fscanf(file, "%c", &ch);
        message[i][0] += (int)ch;
        printf("%zu ", message[i][0]);
      }
      fclose(file);
    }
    i++;
  } while (i < 1);  // create dynamic arr[1][512]
  for (size_t k = 0; k < i; k++) {
    free(message[k]);
  }
  // begin read matrix
  // coding each symbol to binary format
  // if len of matrix (in binary) < 448 then add 1 and puts zero to end of 447th
  // count len matrix and write this at 64 bit
  // add this 64bit to end of arr (from 448th to 511th)
}
void create_h_arr(unsigned int *h_arr, int n) {
  // first 32 bit of fractional part square root of first 8 simple numbers [from
  // 2 to 19]
  create_arr_simple_num(h_arr, n);
  for (int i = 0; i < n; i++) {
    double num = sqrt(h_arr[i]);
    num -= floor(num);
    h_arr[i] = create_32bit_num(num);
  }
}
void create_k_arr(unsigned int *k_arr, int n) {
  // first 32 bit of fractional part cube root of first 64 simple numbers [from
  // 2 to 311]
  create_arr_simple_num(k_arr, n);
  for (int i = 0; i < n; i++) {
    double num = cbrt(k_arr[i]);
    num -= floor(num);
    k_arr[i] = create_32bit_num(num);
  }
}
unsigned int create_32bit_num(double num) {
  int i, n = 32;
  unsigned int res = 0;
  for (i = -1; i >= n * -1; i--) {
    res <<= 1;
    if (num / pow(2, i) > 1) {
      res += 1;
      num -= pow(2, i);
    }
  }
  return res;
}
// n must be > 0
void create_arr_simple_num(unsigned int *h_arr, int n) {
  h_arr[0] = 2;
  int num, flag_simple;
  for (int i = 1; i < n; i++) {
    num = h_arr[i - 1] + 1;
    do {
      flag_simple = 1;
      for (int k = 0; k < i; k++) {
        if (num % h_arr[k] == 0) {
          num += 1;
          flag_simple = 0;
          break;
        }
      }
    } while (flag_simple == 0);
    h_arr[i] = num;
  }
}
