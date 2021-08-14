#include <stdio.h>
#include <string.h>

int coding_ASCII(char *str);
int decoding_ASCII(char *str);
int hex_dec(char symb);

int main(int argc, char **argv) {
    if (argc > 0) {
        char str[100];
        gets(str);
        if (strcmp(argv[1], "0") == 0) {
            if (coding_ASCII(str) == -1) return -1;
        } else if (strcmp(argv[1], "0") == 1) {
            if (decoding_ASCII(str) == -1) return -1;
        }
    }
    return 0;
}

int coding_ASCII(char *str) {
    int i;
    for (i = 0; str[i] != 0x0; i++) {
        if (i % 2 == 1) {
            if (str[i] != 0x20) {
                printf("n/a");
                return -1;
            }
        }
    }
    for (i = 0; str[i] != 0x0; i++) {
        if (str[i] == 0x20) printf(" ");
        else
            printf("%x", str[i]);
    }
    return 0;
}

int decoding_ASCII(char *str) {
    int i, x;
    for (i = 0; str[i] != 0x0; i++) {
        if ((i+2) % 3 == 1) {
            if (str[i] != 0x20) {
                printf("n/a");
                return -1;
            }
        }
    }
    for (i = 0; str[i] != 0x0; i++) {
        if (str[i] == 0x20) {
            printf(" ");
        } else {
            x = hex_dec(str[i]) * 0x10 + hex_dec(str[i+1]);
            printf("%c", x);
            i++;
        }
    }
    return 0;
}

int hex_dec(char symb) {
    if (symb >= 0x30 && symb <= 0x39) return symb - 0x30;
    if (symb >= 0x41 && symb <= 0x46) return symb - 0x37;
    return 0;
}