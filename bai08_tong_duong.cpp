#include <stdio.h>

float tong_duong(float a[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            sum += a[i];
        }
    }
    return sum;
}

void doctep(float a[], int &n) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; ++i)
        fscanf(f, "%f", &a[i]);
    fclose(f);
}

void ghitep(float sum) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    fprintf(f, "%.2f", sum);
    fclose(f);
}

int main() {
    float a[100];
    int n;
    doctep(a, n);
    float sum = tong_duong(a, n);
    ghitep(sum);
    return 0;
}