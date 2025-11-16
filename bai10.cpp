#include <stdio.h>

float lon_nhat(float a[], int n) {
    float ln = a[0];
    for (int i = 1; i < n; ++i)
        if (ln < a[i]) ln = a[i];
    return ln;
}

void doctep(float a[], int &n) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; ++i) {
        fscanf(f, "%f", &a[i]);
    }
    fclose(f);
}

int main() {
    int n;
    float a[100];
    doctep(a, n);
    printf("Gia tri lon nhat trong mang la: %.2f\n", lon_nhat(a, n));
    return 0;
}