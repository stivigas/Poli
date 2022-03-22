#include <stdio.h>

int serie(int n);
int serieApprofondimento(int n);

int main() {
    int n;
    printf("Inserisci n:"); scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("%d ", serie(i));
    }
    printf("\n");
    for(int i = 1; i <= n; i++) {
        printf("%d ", serieApprofondimento(i));
    }
}

int serie(int n) {
    if(n <= 1) return n;
    else return serie(n - 1) + serie(n - 2);
}

int serieApprofondimento(int n) {
    if(n <= 2) return n;
    else return serieApprofondimento(n - 1) * serieApprofondimento(n - 2);

    /*
     * In questa serie tutti i termini sono rappresentabili sia come int(signed) sia come
     * int unsigned, poiché prodotti di interi sempre positivi
     */
}
