#include <stdio.h>

// #include <stdlib.h>
// // Cần delete bộ nhớ sau khi sử dụng
// char *doi_chu_thuong(char s[]) {
//     int len = 0;
//     while (s[len] != '\0') len++;
//     char *result = (char*)malloc(len + 1);
//     int i = 0;
//     for (; s[i] != '\0'; ++i) {
//         if (s[i] >= 'A' && s[i] <= 'Z') {
//             result[i] = s[i] + ('a' - 'A');
//         } else {
//             result[i] = s[i];
//         }
//     }
//     result[i] = '\0';
//     return result;
// }

char *doi_chu_thuong(char s[]) {
    static char result[100];
    int i = 0;
    for (; s[i] != '\0'; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            result[i] = s[i] + ('a' - 'A');
        } else {
            result[i] = s[i];
        }
    }
    result[i] = '\0';
    return result;
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