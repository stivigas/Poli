#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define fileInput "../es1/input.txt"
#define fileOutput "../es1/testo.txt"
#define MAX 1000
#define MAXCHAR 25

int main() {
    FILE *fpIn, *fpOut;
    char text[MAX], riga[MAX];
    int totChar = 0;

    if((fpIn = fopen(fileInput, "r")) == NULL) return 1;
    if((fpOut = fopen(fileOutput, "w")) == NULL) return 2;

    while(fgets(riga, MAX, fpIn)) {
        strcat(text, riga);
    }

    for(int i = 0; i < strlen(text); i++) {
        while(totChar < MAXCHAR) {
            int c = text[i];

            if(isalpha(c)) {
                int k = i - 1;
                int c0 = text[k];
                if(c0 == ' ' || c0 == '\n') {
                    while(c0 == text[k - 1]) {
                        k--;
                    }
                    if(text[k - 1] == '.' || text[k - 1] == '!' || text[k - 1] == '?') {
                        fprintf(fpOut, "%c", toupper(c));
                    } else {
                        fprintf(fpOut, "%c", c);
                    }
                    i++;
                    totChar++;
                } else if(ispunct(c0)) {
                    fprintf(fpOut, "%c", toupper(c));
                    i++;
                    totChar++;
                } else {
                    fprintf(fpOut, "%c", c);
                    i++;
                    totChar++;
                }

            } else if(isdigit(c)) {
                fprintf(fpOut, "*");
                i++;
                totChar++;
            } else if(c == '\n' || c == '\0') {
                for(int j = 0; j < (MAXCHAR - totChar); j++) {
                    fprintf(fpOut, " ");
                }
                fprintf(fpOut, "| c:%d\n", totChar);
                break;
            } else if(ispunct(c) && i < strlen(text)) {
                int c0 = text[i + 1];
                if(!isspace(c0)) {
                    fprintf(fpOut, "%c ", c);
                    i++;
                    totChar += 2;
                } else {
                    fprintf(fpOut, "%c", c);
                    i++;
                    totChar++;
                }
            } else {
                fprintf(fpOut, "%c", c);
                i++;
                totChar++;
            }
        }

        if(totChar == MAXCHAR) {
            fprintf(fpOut, "| c:%d\n", totChar);
            i--;
        }
        totChar = 0;
    }
    fclose(fpIn); fclose(fpOut);

    return 0;
}
