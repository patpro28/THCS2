#include <stdio.h>

int tong_chu_thuong(char s[]) {
    int cnt = 0;
    for (int i = 0; s[i] != '\0'; ++i)
        if (s[i] >= 'a' && s[i] <= 'z') cnt++;
    return cnt;
}

void doctep(char s[]) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%s", s);
    fclose(f);
}

int main() {
    char s[100];
    doctep(s);
    printf("So chu cai thuong trong chuoi la: %d\n", tong_chu_thuong(s));
    return 0;
}