#include <stdio.h>

#define MAX 20
#define min(a, b) (a < b) ? a : b

void readMatrix(int nr, int nc, int m[][MAX], FILE *fpIn);
void findSubMatrix(int nr, int nc, int m[][MAX], int dim);

int main() {
    FILE *fpIn;
    char fileName[30];
    int m[MAX][MAX], nr, nc, dim;

    // file block
    printf("Inserisci il nome del file:"); scanf("%s", fileName);
    if((fpIn = fopen(fileName, "r")) == NULL) return 1;

    // matrix block
    fscanf(fpIn, "%d", &nr); fscanf(fpIn, "%d", &nc);
    readMatrix(nr, nc, m, fpIn);
    fclose(fpIn);

    // exercise block
    printf("\nInserisci la dimensione della sotto-matrice:"); scanf("%d", &dim);
    while(dim >= 1 && dim <= min(nr, nc)) {
        findSubMatrix(nr, nc, m, dim);
        printf("\nInserisci la dimensione della sottomatrice:"); scanf("%d", &dim);
    }

    return 0;
}

void readMatrix(int nr, int nc, int m[][MAX], FILE *fpIn) {
    for(int i = 0; i < nr; i++)
        for(int j = 0; j < nc; j++)
            fscanf(fpIn, "%d", m[i] + j);
}

void findSubMatrix(int nr, int nc, int m[][MAX], int dim) {
    int s, p, q;
    int sum = 0, iMax, jMax;

    printf("Le sottomatrici quadrate di dimensione %d sono:", dim);
    for(int i = 0; i < nr - dim + 1; i++) {
        for(int j = 0; j < nc - dim + 1; j++) {
            s = 0;
            printf("\n");
            for(p = i; p < i + dim; p++) {
                for(q = j; q < j + dim; q++) {
                    s += m[p][q];
                    printf("%d ", m[p][q]);
                }
                printf("\n");
            }

            if(s > sum) {
                sum = s;
                iMax = p;
                jMax = q;
            }
        }
    }

    printf("\nLa sottomatrice con somma degli elementi massima (%d) e':\n", sum);
    for(int i = iMax - dim; i < iMax; i++) {
        for(int j = jMax - dim; j < jMax; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
