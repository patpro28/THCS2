#include <stdio.h>

int tong_chu_so(char s[]) {
    int cnt = 0;
    for (int i = 0; s[i] != '\0'; ++i)
        if (s[i] >= '0' && s[i] <= '9') cnt++;
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
    printf("So chu so trong chuoi la: %d\n", tong_chu_so(s));
    return 0;
}
