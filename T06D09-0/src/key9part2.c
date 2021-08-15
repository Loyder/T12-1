#include <stdio.h>

#define LEN 100

int input(int *buff, int *length);
int filter_arrays(int *buff1, int *length1, int *buff2, int *length2);
void shifting(int *buff, int *length1, int length2);
void sum(int *buff1, int len, int *buff2, int *result, int *result_length);
int sub(int *buff1, int len, int *buff2, int *result, int *result_length);
void output(int *buff1, int length1, int *buff2, int length2, int err_sub);
void output_buff(int *buff, int length);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
  int data1[LEN], data2[LEN], length1 = 0, length2 = 0;
  if (!input(data1, &length1) && !input(data2, &length2)) {
    int data3[LEN + 1], length3 = 0, data4[LEN], length4 = 0, err_sub = 0;
    err_sub = filter_arrays(data1, &length1, data2, &length2);

    sum(data1, length1, data2, data3, &length3);
    if (err_sub == 0) {
      err_sub = sub(data1, length1, data2, data4, &length4);
    }
    output(data3, length3, data4, length4, err_sub);
  }
  return 0;
}
int input(int *buff, int *length) {
  int err_input = 0, count = 0;
  char ch;
  do {
    if (scanf("%d", &buff[*length])) {
      count++;
      ch = getchar();
      if ((ch != '\n' && ch != ' ') || buff[*length] < 0 || buff[*length] > 9 ||
          count > LEN) {
        err_input = 1;
      }
      if (buff[*length] != 0 || *length != 0) {
        (*length)++;
      }
    } else {
      err_input = 1;
    }
    if (err_input == 1) {
      break;
    }
  } while (ch != '\n');
  if (err_input == 1) {
    printf("n/a");
  }
  return err_input;
}
int filter_arrays(int *buff1, int *length1, int *buff2, int *length2) {
  int err_sub = 0;
  if (*length2 > *length1) {
    err_sub = 1;
    shifting(buff1, length1, *length2);
  } else if (*length1 > *length2) {
    shifting(buff2, length2, *length1);
  }

  return err_sub;
}
void shifting(int *buff, int *length1, int length2) {
  int i;
  for (i = (*length1) - 1; i >= 0; i--) {
    buff[i + length2 - (*length1)] = buff[i];
  }
  for (i = 0; i < length2 - (*length1); i++) {
    buff[i] = 0;
  }
  *length1 = length2;
}
void sum(int *buff1, int len, int *buff2, int *result, int *result_length) {
  int remain = 0, i;
  for (i = len - 1; i >= 0; i--) {
    result[i + 1] = (buff1[i] + buff2[i] + remain) % 10;
    remain = (buff1[i] + buff2[i] + remain) / 10;
  }
  result[0] = remain;
  if (result[0] == 0) {
    for (i = 0; i < len; i++) {
      result[i] = result[i + 1];
    }
    *result_length = len;
  } else {
    *result_length = len + 1;
  }
}
int sub(int *buff1, int len, int *buff2, int *result, int *result_length) {
  int err_sub = 0;
  int remain = 0, i;
  for (i = len - 1; i >= 0; i--) {
    if (buff1[i] - remain >= buff2[i]) {
      result[i] = buff1[i] - remain - buff2[i];
      remain = 0;
    } else {
      result[i] = 10 + buff1[i] - remain - buff2[i];
      remain = 1;
    }
  }
  *result_length = len;
  if (remain == 0) {
    // make cycle with many first zeros
    int count = 0;
    while (result[count] == 0) {
      count++;
    }
    for (i = 0; i < (*result_length) - count; i++) {
      result[i] = result[i + count];
    }
    *result_length -= count;
  } else {
    err_sub = 1;  // make condition to negative result -> err_sub = 1;
  }
  return err_sub;
}
void output(int *buff1, int length1, int *buff2, int length2, int err_sub) {
  output_buff(buff1, length1);
  printf("\n");
  if (err_sub == 0) {
    output_buff(buff2, length2);
  } else {
    printf("n/a");
  }
}
void output_buff(int *buff, int length) {
  int i;
  for (i = 0; i < length - 1; i++) {
    printf("%d ", buff[i]);
  }
  printf("%d", buff[i]);
}
