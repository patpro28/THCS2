#include <stdio.h>

int dem_tu(char s[]) {
    int count = 0;
    int word = 0;
    for (int i = 0; s[i] != '\0'; ++i) 
        if (s[i] != ' ') {
            if (word == 0) {
                word = 1;
                count++;
            }
        } else {
            word = 0;
        }
    return count;
}

void doctep(char s[]) {
    FILE *f = fopen("INPUT.INP", "r");
    // fscanf(f, "%[^\n]", s);
    fgets(s, 100, f);
    fclose(f);
}

void ghitep(int count) {
    FILE *f = fopen("OUTPUT.OUT", "w");
    fprintf(f, "%d", count);
    fclose(f);
}

int main() {
    char s[100];
    doctep(s);
    int count = dem_tu(s);
    ghitep(count);
    return 0;
}