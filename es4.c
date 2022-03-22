#include <stdio.h>

#define PI 3.14

int main() {
    char type, mode;
    float area, num;

    printf("Area quadrato (Q) o area cerchio (C)?");
    scanf(" %s", &type);

    switch(type) {
        case 'Q':
            printf("Lato (L) o diagonale (D)?");
            scanf(" %s", &mode);

            printf("Inserisci il valore:");
            scanf(" %f", &num);

            switch(mode) {
                case 'L':
                    area = num * num;
                    break;
                case 'D':
                    area = num * num / 2;
                    break;
                default:
                    printf("Invalid input");
                    return 1;
            }

            printf("Area Quadrato = %.2f", area);

            break;
        case 'C':
            printf("Diametro (D) o raggio (R)?");
            scanf(" %s", &mode);

            printf("Inserisci il valore:");
            scanf(" %f", &num);

            switch(mode) {
                case 'D':
                    area = PI * num * num / 4;
                    break;
                case 'R':
                    area = PI * num * num;
                    break;
                default:
                    printf("Invalid input");
                    return 1;
            }

            printf("Area Cerchio = %.2f", area);

            break;
        default:
            printf("Invalid input");
            return 1;
    }

    return 0;
}