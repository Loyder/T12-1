#include <stdio.h>

int sum(int a, int b);
int diff(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main() {
    int x, y;
    printf("Input 2 integer numbers:\n");
    if (scanf("%d%d", &x, &y) == 2) {
        printf("%d %d %d ", sum(x, y), diff(x, y), mul(x, y));
        if (y != 0)
            printf("%d\n", div(x, y));
        else
            printf("n/a\n");
    } else {
        printf("n/a\n");
    }
    return 0;
}

int sum(int a, int b) {
    return a + b;
}

int diff(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}
