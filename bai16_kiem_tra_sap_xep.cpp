#include <stdio.h>

int kiem_tra_sap_xep(float a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            return 0; // Không sắp xếp
        }
    }
    return 1; // Đã sắp xếp
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
    if (kiem_tra_sap_xep(a, n)) {
        printf("Mang da sap xep tang dan.\n");
    } else {
        printf("Mang chua sap xep tang dan.\n");
    }
    return 0;
}