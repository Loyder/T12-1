#include "../include/hash.h"
#define __USE_MINGW_ANSI_STDIO 1
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void create_hash() {
  int n = 8;
  unsigned h_arr[n];
  create_h_arr(h_arr, n);
  n = 64;
  unsigned k_arr[n];
  create_k_arr(k_arr, n);
  unsigned **message = (unsigned **)malloc(1 * sizeof(unsigned *));
  create_bin_arr(message);
  free(message);
}
void create_bin_arr(unsigned **message) {
  unsigned i = 0;
  char path[100] = "src/message.txt";
  FILE *file = fopen(path, "r");
  if (file != NULL) {
    do {
      message[i] = (unsigned *)malloc(1 * sizeof(unsigned));
      message[i][0] = 0;
      while (!feof(file)) {
        char ch;
        if (fscanf(file, "%c", &ch) != EOF) {
          message[i][0] <<= 8;
          message[i][0] += (unsigned)ch;
          printf("%u ", message[i][0]);
        }
      }
      i++;
    } while (i < 1);  // create dynamic arr[1][512]
    fclose(file);
    for (unsigned k = 0; k < i; k++) {
      free(message[k]);
    }
  } else {
    printf("n/a");
  }
  // begin read matrix
  // coding each symbol to binary format
  // if len of matrix (in binary) < 448 then add 1 and puts zero to end of 447th
  // count len matrix and write this at 64 bit
  // add this 64bit to end of arr (from 448th to 511th)
}
void create_h_arr(unsigned *h_arr, int n) {
  // first 32 bit of fractional part square root of first 8 simple numbers [from
  // 2 to 19]
  create_arr_simple_num(h_arr, n);
  for (int i = 0; i < n; i++) {
    double num = sqrt(h_arr[i]);
    num -= floor(num);
    h_arr[i] = create_32bit_num(num);
  }
}
void create_k_arr(unsigned *k_arr, int n) {
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
void create_arr_simple_num(unsigned *h_arr, int n) {
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
void get_size_of_binary_file(char *path, long int *size, int *err) {
  FILE *file;
  if ((file = fopen(path, "rb")) != NULL) {
    fseek(file, 0, SEEK_END);
    *size = ftell(file) / sizeof(ROWS);
    printf("%ld\n", ftell(file));
    fclose(file);
  } else {
    *err = 1;
  }
}
