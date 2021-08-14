#include <stdio.h>

int main() {
    double x, y;
    printf("Input 2 integer numbers:\n");
    if (scanf("%lf%lf", &x, &y) == 2) {
        if (x * x + y * y < 25)
            printf("GOTCHA");
        else
            printf("MISS");
    } else {
        printf("n/a");
    }
    return 0;
}
