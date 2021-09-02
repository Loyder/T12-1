#include "../include/hash.h"
#define __USE_MINGW_ANSI_STDIO 1
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void create_hash() {
  unsigned n = 8, h[n];
  create_h_arr(h, n);
  n = 64;
  unsigned k[n];
  create_k_arr(k, n);
  unsigned **w = NULL;
  // for (unsigned i = 0; i < 64; i++) {
  //   printf("%08x ", k[i]);
  // }
  // printf("\n");
  w = create_bin_arr(w, h, k);
  free(w);
}
unsigned **create_bin_arr(unsigned **w, unsigned *h, unsigned *k) {
  char path[60] = "src/message.txt";
  FILE *file = fopen(path, "r");
  if (file != NULL) {
    size_t size, size_64, num_block, i;
    unsigned char ch, j, m, byte_size = 8, last_pos_mess;
    get_size_of_binary_file(file, &size);
    last_pos_mess = size % 64;
    size_64 = size / 64 + 1;
    if (last_pos_mess < 56) {
      num_block = size_64;
    } else {
      num_block = size_64 + 1;
    }
    size *= 8;  // length of file in bit
    w = (unsigned **)malloc(num_block * sizeof(unsigned *));
    for (i = 0; i < num_block; i++) {
      w[i] = (unsigned *)malloc(64 * sizeof(unsigned));
      for (m = 0, j = 0; m < 64; m++) {
        if (m % 4 == 0) {
          if (m != 0) {
            j++;
          }
          w[i][j] = 0;
        }
        if ((i < size_64 - 1) || (i == size_64 - 1 && m < last_pos_mess)) {
          fscanf(file, "%c", &ch);
          w[i][j] <<= 8;
          w[i][j] += (unsigned)ch;
        } else if (i == size_64 - 1 && m == last_pos_mess) {  // put one 1
          w[i][j] <<= 8;
          w[i][j] += 1 << 7;
        } else if (i != num_block - 1 || m < 56) {  // put zero
          w[i][j] <<= 8;
        } else if (byte_size > 0) {  // put length of source file
          w[i][j] = size >> (8 * (byte_size - 1));
          byte_size--;
        }
      }
      // generate adding 48 words to j [from 16 to 63]
      unsigned s0, s1;
      for (j = 16; j < 64; j++) {
        s0 = rotr(w[i][j - 15], 7) ^ rotr(w[i][j - 15], 18) ^
             (w[i][j - 15] >> 3);
        s1 =
            rotr(w[i][j - 2], 17) ^ rotr(w[i][j - 2], 19) ^ (w[i][j - 2] >> 10);
        w[i][j] = w[i][j - 16] + s0 + w[i][j - 7] + s1;
      }
      unsigned A = h[0], B = h[1], C = h[2], D = h[3], E = h[4], F = h[5],
               G = h[6], H = h[7];
      unsigned Ma, t1, t2, Ch;
      for (j = 0; j < 64; j++) {
        s0 = rotr(A, 2) ^ rotr(A, 13) ^ rotr(A, 22);
        Ma = (A & B) ^ (A & C) ^ (B & C);
        t2 = s0 + Ma;
        s1 = rotr(E, 6) ^ rotr(E, 11) ^ rotr(E, 25);
        Ch = (E & F) ^ ((~E) & G);
        t1 = H + s1 + Ch + k[i] + w[i][j];
        H = G;
        G = F;
        F = E;
        E = D + t1;
        D = C;
        C = B;
        B = A;
        A = t1 + t2;
        if (j <= 1) {
          // printf("s1 = ");
          // my_printf(s1);
          // printf("\nCh = ");
          // my_printf(Ch);
          // printf("\nt1 = ");
          // my_printf(t1);
          // printf("\ns0 = ");
          // my_printf(s0);
          // printf("\nMa = ");
          // my_printf(Ma);
          // printf("\nt2 = ");
          // my_printf(t2);

          // printf("\nH = ");
          // my_printf(H);
          // printf("\nG = ");
          // my_printf(G);
          // printf("\nF = ");
          // my_printf(F);
          // printf("\nE = ");
          // my_printf(E);
          // printf("\nD = ");
          // my_printf(D);
          // printf("\nC = ");
          // my_printf(C);
          // printf("\nB = ");
          // my_printf(B);
          // printf("\nA = ");
          // my_printf(A);
          // printf("\n");
          printf("k[i] = %08x\n", k[i]);
          printf("w[i][j] = %08x\n", w[i][j]);
          printf("s1 = %08x\n", s1);
          printf("Ch = %08x\n", Ch);
          printf("t1 = %08x\n", t1);
          printf("s0 = %08x\n", s0);
          printf("Ma = %08x\n", Ma);
          printf("t2 = %08x\n", t2);
          printf("A = %08x\n", A);
          printf("B = %08x\n", B);
          printf("C = %08x\n", C);
          printf("D = %08x\n", D);
          printf("E = %08x\n", E);
          printf("F = %08x\n", F);
          printf("G = %08x\n", G);
          printf("H = %08x\n", H);
        }
      }
      h[0] += A;
      h[1] += B;
      h[2] += C;
      h[3] += D;
      h[4] += E;
      h[5] += F;
      h[6] += G;
      h[7] += H;
    }
    // for (i = 0; i < num_block; i++) {
    //   for (j = 0; j < 64; j++) {
    //     my_printf(w[i][j]);
    //     if (i != num_block - 1 || j != 63) {
    //       printf(" ");
    //     }
    //   }
    // }
    // for (i = 0; i < 8; i++) {
    //   printf("%08x ", h[i]);
    // }
    fclose(file);
    for (i = 0; i < num_block; i++) {
      free(w[i]);
    }
  } else {
    printf("n/a");
  }
  return w;
}
void my_printf(unsigned num) {
  for (unsigned char i = 0; i < 32; i++) {
    printf("%d", (num << i) >> 31);
    // if (i % 8 == 7) {
    //   printf(" ");
    // }
  }
}
// rotate_right (0 <= num <= 32)
unsigned rotr(unsigned num, unsigned char shift) {
  return (num >> shift) | (num << (32 - shift));
}
// size of file <= 4 Gb
void get_size_of_binary_file(FILE *file, size_t *size) {
  fseeko64(file, 0, SEEK_END);
  *size = ftello64(file);
  fseeko64(file, 0, SEEK_SET);
}
// first 32 bit of fractional part square root of first 8 simple numbers
// [from 2 to 19]
void create_h_arr(unsigned *h, int n) {
  create_arr_simple_num(h, n);
  for (int i = 0; i < n; i++) {
    double num = sqrt(h[i]);
    num -= floor(num);
    h[i] = create_32bit_num(num);
  }
}
// first 32 bit of fractional part cube root of first 64 simple numbers
// [from 2 to 311]
void create_k_arr(unsigned *k, int n) {
  create_arr_simple_num(k, n);
  for (int i = 0; i < n; i++) {
    double num = cbrt(k[i]);
    num -= floor(num);
    k[i] = create_32bit_num(num);
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
void create_arr_simple_num(unsigned *h, int n) {
  h[0] = 2;
  int num, flag_simple;
  for (int i = 1; i < n; i++) {
    num = h[i - 1] + 1;
    do {
      flag_simple = 1;
      for (int k = 0; k < i; k++) {
        if (num % h[k] == 0) {
          num += 1;
          flag_simple = 0;
          break;
        }
      }
    } while (flag_simple == 0);
    h[i] = num;
  }
}
