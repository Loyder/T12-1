#include "../include/hash.h"

#include <math.h>
#include <stdio.h>
void create_hash() {
  //
  create_h_arr();
  // create_k_arr();
  // create_bin_arr();
}
void create_bin_arr() {
  // create dynamic arr[1][512]
  // begin read matrix
  // coding each symbol to binary format
  // if len of matrix (in binary) < 448 then add 1 and puts zero to end of 447th
  // count len matrix and write this at 64 bit
  // add this 64bit to end of arr (from 448th to 511th)
}
void create_h_arr() {
  // первые 32 бита дробных частей квадратных корней первых восьми простых чисел
  // [от 2 до 19]
  int n = 8;
  unsigned int h_arr[n];
  create_arr_simple_num(h_arr, n);
  for (int i = 0; i < n; i++) {
    double num = sqrt(h_arr[i]);
    num -= floor(num);
    printf("%d %lf\n", i, num);
  }
  // for (int i = 0; i < n; i++) {
  //   printf("%d %u\n", i, h_arr[i]);
  // }
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
