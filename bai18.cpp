#include <stdio.h>
#include <math.h>

float ex(float x, float c) {
    float res = 0;
    float mu = 1, gt = 1;
    int n = 0;
    while (fabs(mu / gt) >= c) {
        res += mu / gt;
        mu *= x;
        n++;
        gt *= n;
    }
    return res;
}

void doctep(float &x, float &c) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%f%f", &c, &x);
    fclose(f);
}

int main() {
    float x, c;
    doctep(x, c);
    printf("Gia tri e^%.2f voi sai so %.5f la: %.5f\n", x, c, ex(x, c));
    return 0;
}