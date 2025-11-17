#include <stdio.h>

void doctep(float a[], int &n) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; ++i) {
        fscanf(f, "%f", &a[i]);
    }
    fclose(f);
}

void quicksort(float a[], int n) {
    if (n <= 1) return;
    float pivot = a[n / 2];
    int i = 0, j = n - 1;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            float temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    quicksort(a, j + 1);
    quicksort(a + i, n - i);
}

void ghitep(float a[], int n) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    for (int i = 0; i < n; ++i) {
        fprintf(f, "%.2f ", a[i]);
    }
    fclose(f);
}

int main() {
    int n;
    float a[100];
    doctep(a, n);
    quicksort(a, n);
    ghitep(a, n);
    return 0;
}