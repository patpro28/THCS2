#include <stdio.h>

int getbit(int n, int k) {
    return (n >> k) & 1;
}

char *doinhiphan(float n) {
    static char s[101];
    int intPart = (int)n;
    float fracPart = n - intPart;
    int i = 0;
    while (intPart > 0) {
        s[i++] = (intPart % 2) + '0';
        intPart /= 2;
    }
    int j = 0;
    while (j * 2 < i) {
        char temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
        j++;
    }
    s[i++] = '.';
    while (i < 100) {
        fracPart *= 2;
        if (fracPart >= 1) {
            s[i++] = '1';
            fracPart -= 1;
        } else {
            s[i++] = '0';
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