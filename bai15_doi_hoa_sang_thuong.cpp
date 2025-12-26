#include <stdio.h>

// #include <stdlib.h>
// // Cần delete bộ nhớ sau khi sử dụng
// char *doi_chu_thuong(char s[]) {
//     int len = 0;
//     while (s[len] != '\0') len++;
//     char *kq = (char*)malloc(len + 1);
//     int i = 0;
//     while(s[i] != '\0') {
//         if (s[i] >= 'A' && s[i] <= 'Z') {
//             kq[i] = s[i] + ('a' - 'A');
//         } else {
//             kq[i] = s[i];
//         }
//         i++;
//     }
//     kq[i] = '\0';
//     return kq;
// }

char *doi_chu_thuong(char s[]) {
    static char kq[100];
    int i = 0;
    while(s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            kq[i] = s[i] + ('a' - 'A');
        } else {
            kq[i] = s[i];
        }
        i++;
    }
    kq[i] = '\0';
    return kq;
}

void doctep(char s[]) {
    FILE *f = fopen("INPUT.INP", "r");
    fscanf(f, "%s", s);
    fclose(f);
}

int main() {
    char s[100];
    doctep(s);
    printf("Chuoi sau khi doi thanh chu thuong: %s\n", doi_chu_thuong(s));
    return 0;
}