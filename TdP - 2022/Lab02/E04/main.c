#include <stdio.h>
#include <ctype.h>

int comprimi(FILE *fpIn, FILE *fpOut);
int decomprimi(FILE *fpIn, FILE *fpOut);

int main() {
    FILE *fpIn, *fpOut;
    char choice;
    printf("Comprimere (C) o decomprimere (D)?"); scanf("%c", &choice);

    switch(toupper(choice)) {
        case 'C':
            if((fpIn = fopen("../es4/sorgente.txt", "r")) == NULL) return 0;
            if((fpOut = fopen("../es4/compresso.txt", "w")) == NULL) return 0;

            comprimi(fpIn, fpOut);
            break;
        case 'D':
            if((fpIn = fopen("../es4/compresso.txt", "r")) == NULL) return 0;
            if((fpOut = fopen("../es4/decompresso.txt", "w")) == NULL) return 0;

            decomprimi(fpIn, fpOut);
            break;
        default:
            return 1; // Invalid input
    }

    return 0;
}

int comprimi(FILE *fpIn, FILE *fpOut) {
    int k = 0, h, totChar = 0, cNew;
    char c, c0;
    while(!feof(fpIn)) {
        fscanf(fpIn,"%c",&c);

        if (!feof(fpIn)) {
            if (c >= '0' && c <= '9') {
                cNew= c + k;
                if (cNew > '9') {
                    cNew= (cNew - '9' - 1) % 10 + '0';
                }

                fprintf(fpOut, "%c", cNew);
                c0 = (char)cNew;
                k++;
            }
            else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                if ((c0 >= 'A' && c0 <= 'Z') || (c0 >= 'a' && c0 <= 'z')) {
                    if (c0 >= 'A' && c0 <= 'Z') h= c0 - 'A';
                    else h= c0 - 'a';
                    cNew= c + h;

                    if (c >= 'A' && c <= 'Z') {
                        if (cNew > 'Z') {
                            cNew= ((cNew - 'Z' - 1) % 26) + 'A';
                        }
                    }
                    else {
                        if (cNew > 'z') {
                            cNew= ((cNew - 'z' - 1) % 26) + 'a';
                        }
                    }
                    fprintf(fpOut, "%c", cNew);
                    c0 = cNew;
                }
                else {
                    fprintf(fpOut, "%c", c);
                    c0 = c;
                }
            }
            else {
                fprintf(fpOut, "%c", c);
                c0 = c;
            }
            totChar++;
        }
    }
    if(totChar > 0) return totChar;
    return totChar;
}

int decomprimi(FILE *fpIn, FILE *fpOut) {
    return 0;
}
