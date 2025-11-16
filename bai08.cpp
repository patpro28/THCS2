#include <stdio.h>

int demso(float a[], int n, float x) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

void doctep(float a[], int &n, float &x) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; ++i)
        fscanf(f, "%f", &a[i]);
    fscanf(f, "%f", &x);
    fclose(f);
}

int main() {
    float a[100], x;
    int n;
    doctep(a, n, x);
    int result = demso(a, n, x);
    printf("So lan xuat hien cua %.2f trong mang la: %d\n", x, result);
    return 0;
}
