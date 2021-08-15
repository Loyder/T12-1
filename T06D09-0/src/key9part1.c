/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
int sum_numbers(int *buffer, int length, int *sum);
int find_numbers(int *buffer, int length, int number, int *numbers);
void output(int *buffer, int length, int sum);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
  int data1[NMAX], n;
  if (!input(data1, &n)) {
    int sum = 0;
    if (!sum_numbers(data1, n, &sum)) {
      int data2[NMAX], length;
      length = find_numbers(data1, n, sum, data2);
      output(data2, length, sum);
    }
  }
  return 0;
}

int input(int *buffer, int *length) {
  int err = 0;
  if (scanf("%d", length) && (getchar() == '\n') && (*length > 0) &&
      (*length <= NMAX)) {
    char ch;
    for (int i = 0; i < *length; i++) {
      if (scanf("%d", &buffer[i])) {
        ch = getchar();
        if ((ch != '\n' && ch != ' ') || (ch == '\n' && i < *length - 1) ||
            (ch != '\n' && i >= *length - 1)) {
          err = 1;
        }
      } else {
        err = 1;
      }
      if (err == 1) {
        break;
      }
    }
  } else {
    err = 1;
  }
  if (err == 1) {
    printf("n/a");
  }
  return err;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length, int *sum) {
  int err = 0, count = 0;

  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0) {
      *sum += buffer[i];
      count++;
    }
  }
  if (!count) {
    err = 1;
    printf("n/a");
  }
  return err;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
  int j = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] != 0) {
      if (number % buffer[i] == 0) {
        numbers[j] = buffer[i];
        j++;
      }
    }
  }
  return j;
}

void output(int *buffer, int length, int sum) {
  int i;
  printf("%d\n", sum);
  for (i = 0; i < length - 1; i++) {
    printf("%d ", buffer[i]);
  }
  printf("%d", buffer[i]);
}
