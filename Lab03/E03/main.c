#include <stdio.h>

#define fileInput "../es3/numeri.txt"

int main() {
    FILE *fpIn;
    int a, b, n, max, min, scartati = 0;

    if((fpIn = fopen(fileInput, "r")) == NULL) return 1;

    fscanf(fpIn, "%d", &a); fscanf(fpIn, "%d", &b);
    if(a >= b) { max = a, min = b; }
    else { max = b, min = a; }

    while(fscanf(fpIn, "%d", &n) == 1) {
        if((a + b == n) || (a - b == n) || (a * b == n) || (a / b == n)) {
            if(n > max) max = n;
            if(n < min) min = n;

            a = b;
            b = n;
        } else {
            scartati++;
        }
    }
    printf("Numero massimo: %d\nNumero minimo: %d\nNumeri scartati: %d", max, min, scartati);

    fclose(fpIn);
    return 0;
}
