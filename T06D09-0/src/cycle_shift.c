#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *shift);
void cycle_shift(int *buffer, int *out, int length, int shift);
void output(int *buffer, int length);

int main() {
  int data[NMAX], length, shift;
  if (!input(data, &length, &shift)) {
    int out[NMAX];
    cycle_shift(data, out, length, shift);
    output(out, length);
  }
  return 0;
}

int input(int *buffer, int *length, int *shift) {
  int err = 0;
  if (scanf("%d", length) && getchar() == '\n' && *length > 0 &&
      *length <= NMAX) {
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
    if (scanf("%d", shift) && getchar() == '\n') {
    } else {
      err = 1;
    }
  } else {
    err = 1;
  }
  if (err == 1) {
    printf("n/a");
  }
  return err;
}

void cycle_shift(int *buffer, int *out, int length, int shift) {
  int j;
  if (shift >= 0) {
    j = shift;
    for (int i = 0; i < length; i++) {
      if (j >= length) j = 0;
      out[i] = buffer[j];
      j++;
    }
  } else {
    j = length + shift;
    for (int i = 0; i < length; i++) {
      if (j >= length) j = 0;
      out[i] = buffer[j];
      j++;
    }
  }
}

void output(int *buffer, int length) {
  int i;
  for (i = 0; i < length - 1; i++) {
    printf("%d ", buffer[i]);
  }
  printf("%d", buffer[i]);
}
