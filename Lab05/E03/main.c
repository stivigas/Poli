#include <stdio.h>
#include <string.h>

#define maxNome 20
#define maxN 30
#define exit "fine"

void loadMatrix(int m[][maxN], int nr, int nc, FILE *fpIn);
void printMatrix(int m[][maxN], int nr, int nc);
void ruota(int m[][maxN], char sel[maxN], int N, int index, char dir[maxN], int pos);

int main() {
    FILE *fpIn;
    char fileName[maxNome], sel[maxN], dir[maxN];
    int m[maxN][maxN], nr, nc, index, pos;

    // matrix block
    printf("Nome file:"); scanf("%s", fileName);
    if((fpIn = fopen(fileName, "r")) == NULL) return 1;
    fscanf(fpIn, "%d%d", &nr, &nc);
    loadMatrix(m, nr, nc, fpIn);
    fclose(fpIn);

    printMatrix(m, nr, nc);

    printf("\nIstruzioni:"); scanf("%s%d%s%d", sel, &index, dir, &pos);
    while(strcmp(sel, exit) != 0) {
        ruota(m, sel, (strcmp(sel, "riga") == 0) ? nc : nr, index-1, dir, pos);
        printMatrix(m, nr, nc);

        printf("\nIstruzioni:");
        scanf("%s%d%s%d", sel, &index, dir, &pos);
    }

    return 0;
}

void loadMatrix(int m[][maxN], int nr, int nc, FILE *fpIn) {
    for(int i = 0; i < nr; i++)
        for(int j = 0; j < nc; j++)
            fscanf(fpIn, "%d", m[i] + j);
}

void printMatrix(int m[][maxN], int nr, int nc) {
    printf("\n");
    for(int i = 0; i < nr; i++) {
        for(int j = 0; j < nc; j++)
            printf("%3d", m[i][j]);
        printf("\n");
    }
}

void ruota(int m[][maxN], char sel[maxN], int N, int index, char dir[maxN], int pos) {
    int copy[maxN], newI;

    for(int i = 0; i < N; i++) {
        if(strcmp(dir, "sinistra") == 0 || strcmp(dir, "su") == 0) {
            newI = (i - pos) % N;
            if(newI < 0) newI += N;
        } else if(strcmp(dir, "destra") == 0 || strcmp(dir, "giu") == 0) newI = (i + pos) % N;

        if(strcmp(sel, "riga") == 0) copy[newI] = m[index][i];
        else if(strcmp(sel, "colonna") == 0) copy[newI] = m[i][index];
    }

    for(int i = 0; i < N; i++) {
        if(strcmp(sel, "riga") == 0) m[index][i] = copy[i];
        else if(strcmp(sel, "colonna") == 0) m[i][index] = copy[i];
    }
}
