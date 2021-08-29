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
  char path[60] = "src/message.txt";
  FILE *file = fopen(path, "r");
  if (file != NULL) {
    unsigned i, j, k, size, tmp1, tmp2 /*tmp3*/;
    char ch;
    // create dynamic arr by 512bit: unsigned arr[][16]
    get_size_of_binary_file(file, &size);
    tmp1 = size % 64;
    tmp2 = size / 64 + 1;
    message = (unsigned **)realloc(message, tmp2 * sizeof(unsigned *));
    for (i = 0; i < tmp2; i++) {
      message[i] = (unsigned *)malloc(16 * sizeof(unsigned));
      // if (tmp2 - i != 1) {
      //   tmp3 = 64;
      // } else {
      //   tmp3 = tmp1;
      // }
      for (k = 0, j = -1; k < 64; k++) {
        if (k % 4 == 0) {
          j++;
          message[i][j] = 0;
        }
        if ((tmp2 - i != 1) || k < tmp1) {
          fscanf(file, "%c", &ch);
          message[i][j] <<= 8;
          message[i][j] += (unsigned)ch;
        } else if (k == tmp1) {
          message[i][j] <<= 8;
          message[i][j] += 1 << 7;
        }
        // FIX !!! NEED PASTE LENGTH OF FILE (NOT ZERO AFTER 56TH BYTE)
        else {
          message[i][j] <<= 8;
        }
        printf("%x ", message[i][j]);
      }
    }
    for (i = 0; i < tmp2; i++) {
      for (j = 0; j < 16; j++) {
        printf("%08x ", message[i][j]);
      }
    }

    if (tmp1 >= 56) {
      tmp2 += 1;
      message = (unsigned **)realloc(message, tmp2 * sizeof(unsigned *));
      message[tmp2 - 1] = (unsigned *)malloc(16 * sizeof(unsigned));
      for (j = 0; j < 56; j++) {
        message[tmp2 - 1][j] = 0;
      }
    }

    // add length of file
    // for (j = 0; j < 56; j++) {
    //   message[tmp2 - 1][j] = 0;
    // }

    // if len of matrix (in binary) < 448 then add 1 and puts zero to end of
    // 447th count len matrix and write this at 64 bit add this 64bit to end
    // of arr (from 448th to 511th)
    fclose(file);
    for (i = 0; i < tmp2; i++) {
      free(message[i]);
    }
  } else {
    printf("n/a");
  }
}
// size of file <= 4 Gb
void get_size_of_binary_file(FILE *file, unsigned *size) {
  fseek(file, 0, SEEK_END);
  *size = ftell(file);
  printf("%u\n", *size);
  fseek(file, 0, SEEK_SET);
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
