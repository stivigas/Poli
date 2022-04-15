#include <stdio.h>
#include <string.h>

#define S 30
#define MAX 201
#define fileDiz "../es2/dizionario.txt"
#define fileIn "../es2/sorgente.txt"
#define fileOut "../es2/ricodificato.txt"

typedef struct {
    char substring[MAX], codifica[MAX];
} Dizionario;

void loadDict(FILE *fpIn, Dizionario dict[], int n);
int isSubstring(char str[], char substr[]);
void replaceStr(char str[], char codifica[], int iPos, int length);

int main() {
    FILE *fpDiz, *fpIn, *fpOut;
    char str[MAX], endChar;
    Dizionario dict[S];
    int nDiz, i, found, index;

    if((fpDiz = fopen(fileDiz, "r")) == NULL) return 1;
    if((fpIn = fopen(fileIn, "r")) == NULL) return 1;
    if((fpOut = fopen(fileOut, "w")) == NULL) return 1;

    // load dict
    fscanf(fpDiz, "%d", &nDiz);
    loadDict(fpDiz, dict, nDiz);
    fclose(fpDiz);

    while(fscanf(fpIn, "%s", str) == 1) {
        found = 0;
        for(i = 0; i < nDiz && !found; i++) { // ciclo per trovare quale sotto-stringa è presente
            index = isSubstring(str, dict[i].substring);
            if(index != -1) found = 1;
        }

        if(found) replaceStr(str, dict[i-1].codifica, index, strlen(dict[i-1].substring));
        fscanf(fpIn, "%c", &endChar); // eventuali spazi o \n non presi dalla scanf %s

        fprintf(fpOut, "%s%c", str, endChar);
    }
    fclose(fpIn); fclose(fpOut);

    return 0;
}

void loadDict(FILE *fpIn, Dizionario dict[], int n) {
    for(int i = 0; i < n; i++) fscanf(fpIn, "%s%s", dict[i].codifica, dict[i].substring);
}

int isSubstring(char str[], char substr[]) {
    int i, j = 0; // indice per str; indice per substr

    for(i = 0; i < strlen(str); i++) {
        if(j == strlen(substr)) // se j arriva alla fine di substr    // potevo anche mettere la condizione nel for
            break;              // interrompo

        if(str[i] == substr[j]) { // se carattere i di str è uguale al carattere j di substr
            j++;                  // incremento j
        } else { // se non corrispondono
            if(j > 0) i -= j; // caso in cui il carattere che precede i-esimo è duplicato
            j = 0; // riporto j a 0
        }
    }

    return j < strlen(substr) ? -1 : i - j; // restituisco -1 se substr non trovata, altrimenti (indice di str) - (indice substr)
}

void replaceStr(char str[], char codifica[], int iPos, int length) {
    char tmp[MAX]; // parte finale che deve rimanere invariata
    strcpy(tmp, &str[iPos + length]);

    str[iPos] = 0; // parte iniziale che deve rimanere invariata

    strcat(str, codifica); // concateno le varie componenti
    strcat(str, tmp);
}