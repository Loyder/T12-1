#include <stdio.h>

long long int max_simple_div(long long int numb);
long long int recurs_div(long long int numb);
long long int division(long long int x, long long int div);
long long int give_rest(long long int x, long long int div);

int main(void) {
    long long int numb;
    long long int result;
    if (scanf("%lld", &numb) == 1 && numb == (long long int)numb) {
        if (numb == 0) {
            printf("n/a");
            return -1;
        }
        result = max_simple_div(numb);
        printf("%lld", result);
    } else {
        printf("n/a");
        return -1;
    }
    return 0;
}

long long int max_simple_div(long long int numb) {
    if (numb < 0) {
        numb *= -1;
    }
    if (numb == 1 || numb == 2) {
        return numb;
    }
    return recurs_div(numb);
}

long long int recurs_div(long long int numb) {
    long long int i;
    for (i = 2; i <= numb - 1; i++) {
        if (give_rest(numb, i) == 0) {
            numb = recurs_div(division(numb, i));
        }
    }
    return numb;
}

long long int division(long long int x, long long int div) {
    long long int count = 0, result = 0;
    while (result <= x) {
        result += div;
        count++;
    }
    return count-1;
}

long long int give_rest(long long int x, long long int div) {
    long long int count = 0, result = 0;
    while (result <= x) {
        result += div;
        count++;
    }
    return x + div - result;
}
