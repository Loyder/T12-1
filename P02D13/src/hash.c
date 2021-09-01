#include "../include/hash.h"
#define __USE_MINGW_ANSI_STDIO 1
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void create_hash() {
  unsigned n = 8, h_arr[n];
  create_h_arr(h_arr, n);
  n = 64;
  unsigned k_arr[n];
  create_k_arr(k_arr, n);
  unsigned **message = NULL;
  message = create_bin_arr(message);
  free(message);
}
unsigned **create_bin_arr(unsigned **message) {
  message = (unsigned **)malloc(1 * sizeof(unsigned *));
  char path[60] = "src/message.txt";
  FILE *file = fopen(path, "r");
  if (file != NULL) {
    size_t size, size_64, num_block, i;
    unsigned char ch, j, k, byte_size = 8, last_pos_mess;
    get_size_of_binary_file(file, &size);
    last_pos_mess = size % 64;
    size_64 = size / 64 + 1;
    if (last_pos_mess < 56) {
      num_block = size_64;
    } else {
      num_block = size_64 + 1;
    }
    size *= 8;  // length of file in bit
    message = (unsigned **)realloc(message, num_block * sizeof(unsigned *));
    for (i = 0; i < num_block; i++) {
      message[i] = (unsigned *)malloc(16 * sizeof(unsigned));
      for (k = 0, j = 0; k < 64; k++) {
        if (k % 4 == 0) {
          if (k != 0) {
            j++;
          }
          message[i][j] = 0;
        }
        if ((i < size_64 - 1) || (i == size_64 - 1 && k < last_pos_mess)) {
          fscanf(file, "%c", &ch);
          message[i][j] <<= 8;
          message[i][j] += (unsigned)ch;
        } else if (i == size_64 - 1 && k == last_pos_mess) {  // put one 1
          message[i][j] <<= 8;
          message[i][j] += 1 << 7;
        } else if (i != num_block - 1 || k < 56) {  // put zero
          message[i][j] <<= 8;
        } else if (byte_size > 0) {  // put length of source file
          message[i][j] = size >> (8 * (byte_size - 1));
          byte_size--;
        }
      }
    }
    for (i = 0; i < num_block; i++) {
      for (j = 0; j < 16; j++) {
        printf("%08x ", message[i][j]);
      }
    }
    fclose(file);
    for (i = 0; i < num_block; i++) {
      free(message[i]);
    }
  } else {
    printf("n/a");
  }
  return message;
}
// size of file <= 4 Gb
void get_size_of_binary_file(FILE *file, size_t *size) {
  fseeko64(file, 0, SEEK_END);
  *size = ftello64(file);
  fseeko64(file, 0, SEEK_SET);
}
void create_h_arr(unsigned *h_arr, int n) {
  // first 32 bit of fractional part square root of first 8 simple numbers
  // [from 2 to 19]
  create_arr_simple_num(h_arr, n);
  for (int i = 0; i < n; i++) {
    double num = sqrt(h_arr[i]);
    num -= floor(num);
    h_arr[i] = create_32bit_num(num);
  }
}
void create_k_arr(unsigned *k_arr, int n) {
  // first 32 bit of fractional part cube root of first 64 simple numbers
  // [from 2 to 311]
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
