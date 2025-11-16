#include <stdio.h>

char *doinhiphan(long n) {
    static char s[65];
    s[64] = '\0';
    for (int i = 63; i >= 0; i--) {
        s[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
    return s;
}

void doctep(long &n) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%ld", &n);
    fclose(f);
}

int main() {
    long n;
    doctep(n);
    printf("So nhi phan cua %ld la: %s\n", n, doinhiphan(n));
    return 0;
}