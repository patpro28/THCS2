#include <stdio.h>

char *doinhiphan(long n) {
    static char s[65];
    int i = 0, j = 0;
    while (n > 0) {
        s[i++] = (n % 2) + '0';
        n /= 2;
    }
    s[i] = '\0';

    while (j * 2 < i) {
        char temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
        j++;
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