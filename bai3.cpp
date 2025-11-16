#include <stdio.h>

void selectsort(float a[], int n) {
    for (int i = 0; i < n; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[min_idx])
                min_idx = j;
        float temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
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
    selectsort(a, n);
    ghitep(a, n);
    return 0;
}