#include <stdio.h>

#define maxN 30
#define fileName "../es1/number.txt"

void sottoSequenze(int V[], int N);

int main() {
    FILE *fpIn;
    int V[maxN], N;

    if((fpIn = fopen(fileName, "r")) == NULL) return 1;

    for(N = 0; fscanf(fpIn, "%d", &V[N]) == 1; N++); // inizializzazione del vettore con calcolo della sua lunghezza
    fclose(fpIn);

    sottoSequenze(V, N);

    return 0;
}

void sottoSequenze(int V[], int N) {
    int maxLength = 0, iIn, flag = 1;
    for(int i = 0; i < N; i++) { // ciclo per trovate la lunghezza massima delle sotto-sequenze
        if(V[i] != 0 && flag) {
            iIn = i;
            flag = 0;
        } else if(V[i] == 0) {
            if(i - iIn >= maxLength) maxLength = i - iIn;
            flag = 1;
        } else if(i == N - 1 && V[i] != 0)
            if(i - iIn + 1 >= maxLength) maxLength = i - iIn + 1;
    }

    printf("I sottovettori di lunghezza massima (%d) sono:\n", maxLength);

    int length = 0;
    for(int i = 0; i < N; i++) {
        if(V[i] == 0) {
            if(length == maxLength) {
                printf("[ ");
                for (int j = i - maxLength; j < i; j++) {
                    printf("%d ", V[j]);
                }
                printf("]\n");
            }
            length = 0;
        } else if(i == N - 1 && V[i] != 0) {
            length++;

            if(length == maxLength) {
                for (int j = i - maxLength + 1; j < i; j++) {
                    printf("%d ", V[j]);
                }
                printf("\n");
            }
            length = 0;
        } else {
            length++;
        }
    }
}
