#include <stdio.h>

#define maxN 30

typedef enum {sN, sP} scelta; // sN per input di N, sP per P

void ruota(int v[maxN], int N, int P, int dir);
void printArray(int v[], int N);
int getNumber(int max, scelta s);

int main() {
    int v[maxN], N, P, dir;
    N = getNumber(maxN, sN);

    // array block
    for(int i = 0; i < N; i++) {
        printf("Inserisci elemento:");
        scanf("%d", &v[i]);
    }

    // exercise block
    P = getNumber(N, sP); // voglio che appena inserisco 0 l'esecuzione si arresti, per questo non uso un do while
    while(P != 0) {
        printf("Inserisci dir (SINISTRA: 1, DESTRA: -1):"); scanf("%d", &dir);

        ruota(v, N, P, dir);
        printArray(v, N);

        P = getNumber(N, 2);
    }

    return 0;
}

void ruota(int v[maxN], int N, int P, int dir) {
    int copy[N], newI;

    for(int i = 0; i < N; i++) { // trovo il nuovo indice a seguito della traslazione
        if(dir == 1) {
            newI = (i - P) % N;
            if(newI < 0) newI += N;
        } else newI = (i + P) % N;

        copy[newI] = v[i]; // e poi gli assegno il valore corrispondente
    }

    for(int i = 0; i < N; i++) v[i] = copy[i]; // risostituisco i valori dei nuovi indici nel vettore originario
}

void printArray(int v[], int N) {
    for(int i = 0; i < N; i++) printf("%d ", v[i]);
    printf("\n");
}

int getNumber(int max, scelta s) {
    int num;

    do {
        s == sN ? printf("Inserisci maxN (<= %d):", max) : printf("\nInserisci P (< %d) (0 per terminare):", max);
        scanf("%d", &num);
    } while(num < 0 || s == sN ? num > max : num >= max);

    return num;
}