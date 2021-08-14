#include <stdio.h>
int s21_strlen(char *str) {
  int count = 0;
  while (str[count] != '\0') {
    count++;
  }
  return count;
}
int s21_strcmp(char *str1, char *str2) {
  int result = 0, i = -1;
  do {
    i++;
    if (str1[i] < str2[i] || str1[i] > str2[i]) {
      if (str1[i] < str2[i]) {
        result = -1;
      } else {
        result = 1;
      }
      break;
    }
  } while (str1[i] != '\0' && str2[i] != '\0');
  return result;
}
void s21_strcpy(char *str1, char *str2) {
  int i = -1;
  do {
    i++;
    str1[i] = str2[i];
    // if (sizeof(str1) - 1 == i) {
    //   break;
    // }
  } while (str2[i] != '\0');
  for (++i; i < sizeof(str1); i++) {
    str1[i] = '\0';
  }
}
