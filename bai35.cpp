#include <stdio.h>

void mergesort(float a[], int n) {
    if (n <= 1) return;
    int mid = n / 2;
    mergesort(a, mid);
    mergesort(a + mid, n - mid);

    float* temp = new float[n];
    int i = 0, j = mid, k = 0;

    while (i < mid && j < n) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i < mid) temp[k++] = a[i++];
    while (j < n) temp[k++] = a[j++];
    // Sao chép mảng tạm trở lại mảng ban đầu
    for (i = 0; i < n; ++i) {
        a[i] = temp[i];
    }
    delete[] temp;
}

void doctep(float a[], int &n) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; ++i) {
        fscanf(f, "%f", &a[i]);
    }
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
    int n;
    float a[100];
    doctep(a, n);
    mergesort(a, n);
    ghitep(a, n);
    return 0;
}