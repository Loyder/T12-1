#include <stdio.h>

int max(int a, int b);

int main() {
    int x, y;
    printf("Input 2 integer numbers:\n");
    if (scanf("%d", &x) == 1) {
        if (scanf("%d", &y) == 1)
            printf("%d", max(x, y));
        else
            printf("n/a");
    } else {
        printf("n/a");
    }
    return 0;
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}
