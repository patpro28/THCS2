#include <stdio.h>

int getbit(int n, int k) {
    return (n >> k) & 1;
}

char *doinhiphan(float n) {
    static char s[101];
    int intPart = (int)n;
    float fracPart = n - intPart;
    for (int i = 31; i >= 0; i--) {
        s[i] = (intPart & 1) + '0';
        intPart >>= 1;
    }
    s[32] = '.';
    for (int i = 33; i < 100; i++) {
        fracPart *= 2;
        if (fracPart >= 1) {
            s[i] = '1';
            fracPart -= 1;
        } else {
            s[i] = '0';
        }
    }
    s[100] = '\0';
    return s;
}

void doctep(float &n) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%f", &n);
    // scanf("%f", &n);
    fclose(f);
}

int main() {
    float n;
    doctep(n);
    printf("So nhi phan cua %.6f la: %s\n", n, doinhiphan(n));
    return 0;
}