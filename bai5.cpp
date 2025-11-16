#include <stdio.h>

void insertionsort(float a[], int n) {
    for (int i = 1; i < n; ++i) {
        float key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
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
    insertionsort(a, n);
    ghitep(a, n);
    return 0;
}