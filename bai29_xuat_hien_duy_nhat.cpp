#include <stdio.h>

void solan1(float a[], int n, float a2[], int &m) {
    m = 0;
    int ok[n] = {0};
    for (int i = 0; i < n; ++i) {
        if (ok[i] == 1) continue;
        a2[m++] = a[i];
        for (int j = i + 1; j < n; ++j) {
            if (a[j] == a[i]) {
                ok[j] = 1;
            }
        }
    }
}

void doctep(float a[], int &n) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; ++i) {
        fscanf(f, "%f", a + i);
    }
    fclose(f);
}

void ghitep(float a2[], int m) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    for (int i = 0; i < m; ++i) {
        fprintf(f, "%.2f ", a2[i]);
    }
    fclose(f);
}

int main() {
    float a[100];
    int n;
    float a2[100];
    int m;
    doctep(a, n);
    solan1(a, n, a2, m);
    ghitep(a2, m);
    return 0;
}