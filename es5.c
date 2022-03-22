#include <stdio.h>

int main() {
    char segno;
    float op1, op2, res;

    do {
        printf("Inserisci l'operazione da eseguire (+ - * /):");
        segno = getchar();
    } while(segno != '+' && segno != '-' && segno != '*' && segno != '/');
    printf("Inserisci il primo operando:"); scanf("%f", &op1);
    printf("Inserisci il secondo operando:"); scanf("%f", &op2);

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
            break;
    }

    printf("%c %.2f", segno, res);

    /*
     * Nel momento in cui op2 è uguale a 0, si individuano diverse
     * casistiche, riconducibili comunque all'operatore quoziente /:
     * - se op1 è un numero positivo non nullo, in console avremmo come risultato 1.#INF00 (pos/0 tende ad infinito);
     * - se op1 è un numero negativo non nullo, si avrà -1.#INF00;
     * - altrimenti se op1 è 0 anch'esso, -1.#IND00.
     *
     * Nel complesso quindi C non solleva un'eccezione con il classico Math Error, bensì imposterà il risultato
     * dell'operazione su indefinito
     */
}