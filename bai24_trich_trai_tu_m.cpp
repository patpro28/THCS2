#include <stdio.h>

char *trich_trai(char s[], int n, int m) {
    static char result[100];
    // Có thể kiểm tra xem m < length(s) hay không?
    int i;
    for (i = m; s[i] != '\0' && i < m + n; ++i) {
        result[i - m] = s[i];
    }
    result[i - m] = '\0';
    return result;
}

void doctep(char s[], int &n, int &m) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%s", s);
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);
    fclose(f);
}

void ghitep(char result[]) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    fprintf(f, "%s", result);
    fclose(f);
}

int main() {
    char s[100];
    int n, m;
    doctep(s, n, m);
    char *result = trich_trai(s, n, m);
    ghitep(result);
    return 0;
}