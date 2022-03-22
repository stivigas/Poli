#include <stdio.h>

int main() {
    int a, b, resto;
    do {
        printf("Inserisci due interi positivi (a b):");
        scanf(" %d%d", &a, &b);
    } while(a <= 0 || b <= 0);

    if(a < b) { // Variabile a contiene il valore maggiore, b quello minore
        int tmp = a;
        a = b;
        b = tmp;
    }

    resto = a % b;
    while(resto > 0) {
        a = b;
        b = resto;
        resto = a % b;
    }

    printf("MCD: %d", b);
}