#include <stdio.h>
#include <ctype.h>

#define filein "../es1/input.txt"
#define MAXCHAR 25

int checkPunct(char c);

int main(){
    FILE *fpIn, *fpOut;
    int totChar = 1, totCharOriginal = 0, isPunct;
    char c, c1;

    if((fpIn = fopen(filein, "r")) == NULL) return 1;
    if((fpOut = fopen("../es1/testo.txt", "w")) == NULL) return 2;

    fscanf(fpIn, "%c", &c); fscanf(fpIn, "%c", &c1);
    while(!feof(fpIn)) {
        if(totChar <= MAXCHAR) {
            if(checkPunct(c)) isPunct = 1;
            if(isPunct && isalpha(c)) {
                c = toupper(c);
                isPunct = 0;
            }

            fprintf(fpOut, "%c", c);

            if(ispunct(c)) {
                totCharOriginal++;
                if(c1 != ' ' && c1 != '\n') {
                    fprintf(fpOut, " ");
                    totChar++;
                }
            }

            if(isdigit(c)) {
                c = '*';
                totCharOriginal++;
            }

            if(isalpha(c) || c == ' '){
                totCharOriginal++;
            }

            c = c1;
            fscanf(fpIn, "%c", &c1);
            totChar++;

            if(c == '\n') {
                //totCharOriginal++;
                for(int i = 0; i < MAXCHAR - totChar; i++){
                    fprintf(fpOut, " ");
                }
                fprintf(fpOut, " | c:%d", totCharOriginal);
                totChar = 0;
                totCharOriginal = 0;
            }

            if(totChar > MAXCHAR){
                fprintf(fpOut, " | c:%d\n", totCharOriginal);
                totChar = 0;
                totCharOriginal = 0;
            }
        }
    }
    fclose(fpIn); fclose(fpOut);

    return 0;
}

int checkPunct(char c) {
    if(c == '.' ||  c == '!' || c == '?') return 1;
    else return 0;
}
