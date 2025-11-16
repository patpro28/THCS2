#include <stdio.h>

int tongam(float a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
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

void ghitep(int sum) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    fprintf(f, "%d", sum);
    fclose(f);
}

int main() {
    float a[100];
    int n;
    doctep(a, n);
    int sum = tongam(a, n);
    ghitep(sum);
    return 0;
}