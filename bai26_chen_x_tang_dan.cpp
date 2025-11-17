#include <stdio.h>

void chenx(float a[], int &n, float x) {
    a[n] = x;
    int i = n;
    while (i > 0 && a[i] < a[i - 1]) {
        float temp = a[i];
        a[i] = a[i - 1];
        a[i - 1] = temp;
        i--;
    }
    n++;
}

void doctep(float a[], int &n, float &x) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; ++i) {
        fscanf(f, "%f", a + i);
    }
    fscanf(f, "%f", &x);
    fclose(f);
}

void ghitep(float a[], int n) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    for (int i = 0; i < n; ++i) {
        fprintf(f, "%.2f ", a[i]);
    }
    fclose(f);
}

int main() {
    float a[100];
    int n;
    float x;
    doctep(a, n, x);
    chenx(a, n, x);
    ghitep(a, n);
    return 0;
}