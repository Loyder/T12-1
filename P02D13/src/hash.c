#include "../include/hash.h"

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
  unsigned int h_arr[8];
  h_arr[0] = 2;
  int tmp;
  for (int i = 1; i < 8; i++) {
    tmp = h_arr[i - 1] + 1;
    for (int k = 0; k < i; k++) {
      if (tmp % h_arr[k] != 0) {
        h_arr[i] = tmp;
      }
    }
  }
  for (int i = 0; i < 8; i++) {
    printf("%d %u\n", i, h_arr[i]);
  }
}
