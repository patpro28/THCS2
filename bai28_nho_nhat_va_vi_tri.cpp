#include <stdio.h>

float nho_nhat(float a[], int n, int vitri[], int &tongvitri) {
    tongvitri = 0;
    float min = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == min) {
            vitri[tongvitri++] = i;
        }
    }
    return min;
}

void doctep(float a[], int &n) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; ++i) {
        fscanf(f, "%f", a + i);
    }
    fclose(f);
}

void ghitep(int vitri[], int tongvitri, float min) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    fprintf(f, "%.2f\n", min);
    for (int i = 0; i < tongvitri; ++i) {
        fprintf(f, "%d ", vitri[i]);
    }
    fclose(f);
}

int main() {
    float a[100];
    int n;
    int vitri[100];
    int tongvitri;
    doctep(a, n);
    float min = nho_nhat(a, n, vitri, tongvitri);
    ghitep(vitri, tongvitri, min);
    return 0;
}