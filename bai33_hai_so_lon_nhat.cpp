#include <stdio.h>

void timso(float a[], int n, float &max1, int &vt1, float &max2, int &vt2) {
    max1 = -1e9;
    max2 = -1e9;
    vt1 = -1;
    vt2 = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] > max1) {
            max2 = max1;
            vt2 = vt1;
            max1 = a[i];
            vt1 = i;
        } else if (a[i] > max2 && a[i] < max1) {
            max2 = a[i];
            vt2 = i;
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

void ghitep(float a[], int n, float max1, int vt1, float max2, int vt2) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    fprintf(f, "%.2f %d\n", max1, vt1);
    fprintf(f, "%.2f %d\n", max2, vt2);
    fclose(f);
}