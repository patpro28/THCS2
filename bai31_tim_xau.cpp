#include <stdio.h>

int len(char s[]) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

int tim_xau(char s1[], char s2[], int &vtdau, int &vtcuoi) {
    int n = len(s1);
    int m = len(s2);
    vtdau = -1;
    vtcuoi = -1;
    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j)
            if (s1[i + j] != s2[j]) {
                break;
            }
        if (j == m) {
            vtdau = i;
            vtcuoi = i + m - 1;
            return 1;
        }
    }
    return 0;
}

void doctep(char s1[], char s2[]) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%s", s1);
    fscanf(f, "%s", s2);
    fclose(f);
}

void ghitep(int vtdau, int vtcuoi) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    fprintf(f, "%d %d", vtdau, vtcuoi);
    fclose(f);
}

int main() {
    char s1[100], s2[100];
    int vtdau, vtcuoi;
    doctep(s1, s2);
    if (tim_xau(s1, s2, vtdau, vtcuoi)) {
        ghitep(vtdau, vtcuoi);
    } else {
        ghitep(-1, -1);
    }
    return 0;
}