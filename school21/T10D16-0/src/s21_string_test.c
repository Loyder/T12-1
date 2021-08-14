#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

#include "s21_string_test.h"

int main() {
#ifdef QUEST1
  s21_strlen_test();
#endif
#ifdef QUEST2
  s21_strcmp_test();
#endif
#ifdef QUEST3
  s21_strcpy_test();
#endif
#ifdef QUEST4
  s21_strcat_test();
#endif
#ifdef QUEST5
  s21_strchr_test();
#endif
#ifdef QUEST6
  s21_strstr_test();
#endif
#ifdef QUEST7
  s21_strtok_test();
#endif
  return 0;
}
void s21_strlen_test() {
  int test = 16, result;
  char input1[] = "Hello, School21!";
  result = s21_strlen(input1);
  output_strlen(input1, result, test);
  printf("\n");
  test = 16;
  char input2[16] =
      "Hello, School21!";  // puts incorrect number of symbols to input
  result = s21_strlen(input2);
  output_strlen(input2, result, test);
  printf("\n");
  test = 16;
  char input3[] = "Привет, Школа21!";  // puts cyrillic symbols
  result = s21_strlen(input3);
  output_strlen(input3, result, test);
  printf("\n");
  test = 0;
  char input4[] = "";
  result = s21_strlen(input4);
  output_strlen(input4, result, test);
}
void output_strlen(char *input, int output, int result) {
  printf("%s\n%d\n", input, output);
  if (output == result) {
    printf("SUCCESS");
  } else {
    printf("FAIL");
  }
}
/*
-1: *str1 < *str2
0: *str1 equal *str2
1: *str1 > *str2
*/
void s21_strcmp_test() {
  int test = 0, result;
  char input1[] = "Hello, School21!";
  char input2[] = "Hello, School21!";
  result = s21_strcmp(input1, input2);
  output_strcmp(input1, input2, result, test);
  printf("\n");
  test = 1;
  char input3[] = "Apple";
  char input4[] = "Apartments";
  result = s21_strcmp(input3, input4);
  output_strcmp(input3, input4, result, test);
  printf("\n");
  test = -1;
  char input5[] = "90 km/h";
  char input6[] = "90kg";
  result = s21_strcmp(input5, input6);
  output_strcmp(input5, input6, result, test);
  printf("\n");
  test = -1;
  char input7[] = "";
  char input8[] = "'rainbow";
  result = s21_strcmp(input7, input8);
  output_strcmp(input7, input8, result, test);
}
void output_strcmp(char *input1, char *input2, int output, int result) {
  printf("%s\n%s\n%d\n", input1, input2, output);
  if (output == result) {
    printf("SUCCESS");
  } else {
    printf("FAIL");
  }
}
void s21_strcpy_test() {
  char input1[40], input2[] = "Hello, School21!";
  s21_strcpy(input1, input2);
  output_strcpy(input1, input2);
  printf("\n");
  char input3[5], input4[16] = "Hello, School21!";
  s21_strcpy(input3, input4);
  output_strcpy(input3, input4);
  printf("\n");
  char input5[40], input6[] = "Привет, Школа21!";
  s21_strcpy(input5, input6);
  output_strcpy(input5, input6);
  printf("\n");
  char input7[40], input8[] = "";
  s21_strcpy(input7, input8);
  output_strcpy(input7, input8);
}
void output_strcpy(char *input, char *result) {
  printf("%s\n%s\n", input, result);
  if (input == result) {
    printf("SUCCESS");
  } else {
    printf("FAIL");
  }
}
void s21_strcat_test() {}
void s21_strchr_test() {}
void s21_strstr_test() {}
void s21_strtok_test() {}
