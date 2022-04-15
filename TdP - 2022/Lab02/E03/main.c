#include <stdio.h>
#include <string.h>
#include <ctype.h>

int comprimi(FILE *fpIn, FILE *fpOut);
int decomprimi(FILE *fpIn, FILE *fpOut);

int main() {
    FILE *fpIn, *fpCom, *fpDecom;
    char choice;

    printf("Vuoi comprimere(C) o decomprimere(D) il file?"); scanf(" %c", &choice);

    if((fpIn = fopen("../es3/sorgente.txt", "r")) == NULL) return 1;
    if((fpCom = fopen("../es3/compresso.txt", (toupper(choice) == 'C') ? "w" : "r")) == NULL) return 1;
    if((fpDecom = fopen("../es3/decompresso.txt", "w")) == NULL) return 1;

    switch(toupper(choice)) {
        case 'C':
            comprimi(fpIn, fpCom);
            break;
        case 'D':
            decomprimi(fpCom, fpDecom);
            break;
        default:
            return 2; // Invalid input
    }
    fclose(fpIn); fclose(fpCom); fclose(fpDecom);

    return 0;
}

int comprimi(FILE *fpIn, FILE *fpOut) {
    char riga[100];
    int totChar = 0;

    while(!feof(fpIn)) {
        fgets(riga, 100, fpIn);

        if(!feof(fpIn)) {
            for(int i = 0; i < strlen(riga); i++) {
                int count = 0;
                while(riga[i] == riga[i + 1] && count < 9) {
                    count++;
                    i++;
                }

                if(count > 1) {
                    fprintf(fpOut, "%c$%d", riga[i], count);
                    totChar += 3;
                } else if(count == 1) {
                    fprintf(fpOut, "%c%c", riga[i], riga[i]);
                    totChar += 2;
                } else {
                    fprintf(fpOut, "%c", riga[i]);
                    totChar++;
                }
            }
        }
    }

    if(totChar > 0) return totChar;
    return 0;
}

int decomprimi(FILE *fpIn, FILE *fpOut) {
    char riga[100];
    int totChar = 0;

    while(!feof(fpIn)) {
        fgets(riga, 100, fpIn);

        if(!feof(fpIn)) {
            for(int i = 0; i < strlen(riga); i++) {
                if(riga[i] == '$') {
                    int count = riga[i + 1] - '0';
                    for(int j = 0; j < count; j++) {
                        fprintf(fpOut, "%c", riga[i - 1]);
                    }
                    i++;
                    totChar += count;
                } else {
                    fprintf(fpOut, "%c", riga[i]);
                    totChar++;
                }
            }
        }
    }

    if(totChar > 0) return totChar;
    else return 0;
}
