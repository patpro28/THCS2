#include <stdio.h>

char *trich_phai(char s[], int n) {
    static char result[100];
    int j = 0;
    if (n <= 0) {
        result[0] = '\0';
        return result;
    }
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    for (int i = len - n; i < len; i++) {
        result[j++] = s[i];
    }
    result[j] = '\0';
    return result;
}

void doctep(char s[], int &n) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%s", s);
    fscanf(f, "%d", &n);
    fclose(f);
}

void ghitep(char result[]) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    fprintf(f, "%s", result);
    fclose(f);
}

int main() {
    char s[100];
    int n;
    doctep(s, n);
    char *result = trich_phai(s, n);
    ghitep(result);
    return 0;
}