#include <stdio.h>

#define maxSquadre 20
#define maxGiornate 20
#define fileName "../es1/mat.txt"

void readMatrix(int campionato[][maxGiornate], int nr, int nc, FILE *fpIn);
void findTeam(int campionato[][maxGiornate], int nr, int nc);
void findMax(int score[], int nr);

int main() {
    FILE *fpIn;
    int campionato[maxSquadre][maxGiornate], nr, nc;

    if((fpIn = fopen(fileName, "r")) == NULL) return 1;
    fscanf(fpIn, "%d%d", &nr, &nc);

    readMatrix(campionato, nr, nc, fpIn);
    fclose(fpIn);

    findTeam(campionato, nr, nc);

    return 0;
}

void readMatrix(int campionato[][maxGiornate], int nr, int nc, FILE *fpIn) {
    for(int i = 0; i < nr; i++)
        for(int j = 0; j < nc; j++)
            fscanf(fpIn, "%d", &campionato[i][j]);
}

void findTeam(int campionato[][maxGiornate], int nr, int nc) {
    int score[nr], first = 1;

    for(int j = 0; j < nc; j++) {
        printf("Giornata %d", j+1);
        for(int i = 0; i < nr; i++) {
            if(first) score[i] = campionato[i][j];
            else score[i] += campionato[i][j];
        }
        findMax(score, nr);
        first = 0;
    }
}

void findMax(int score[], int nr) {
    int max = score[0], iMax = 0;

    for(int i = 1; i < nr; i++) {
        if(score[i] >= max) {
            max = score[i];
            iMax = i;
        }
    }

    printf(" - Squadra capolista: %d\n", iMax);
}