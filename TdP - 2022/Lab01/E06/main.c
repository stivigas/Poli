#include <stdio.h>

int main() {
    FILE *fpInput, *fpOutput;
    char segno;
    float op1, op2, res;

    if((fpInput = fopen("../es6/Operations.txt", "r")) == NULL) {
        printf("Errore durante il caricamento");
        return 1;
    }
    if((fpOutput = fopen("../es6/Results.txt", "w")) == NULL) {
        printf("Errore durante il caricamento");
        return 2;
    }

    while(!feof(fpInput)) {
        fscanf(fpInput, " %c%f%f", &segno, &op1, &op2);

        switch(segno) {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
        }
        fprintf(fpOutput, "%c %.2f\n", segno, res);
    }

    return 0;
}
