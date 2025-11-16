#include <stdio.h>

long giaithua(int n) {
    if (n == 0) return 1;
    return n * giaithua(n - 1);
}

void doctep(int &n) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%d", &n);
    fclose(f);
}

int main() {
    int n;
    doctep(n);
    printf("Giai thua cua %d la: %ld\n", n, giaithua(n));
    return 0;
}