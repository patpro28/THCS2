#include <stdio.h>

void bubblesort(float a[], int n) {
    for (int i = n - 2; i >= 0; --i)
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[j - 1]) {
                float temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
}

void doctep(float a[], int &n) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; ++i)
        fscanf(f, "%f", &a[i]);
    fclose(f);
}

void ghitep(float a[], int n) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    for (int i = 0; i < n; ++i)
        fprintf(f, "%.2f ", a[i]);
    fclose(f);
}

int main() {
    float a[100];
    int n;
    doctep(a, n);
    bubblesort(a, n);
    ghitep(a, n);
    return 0;
}