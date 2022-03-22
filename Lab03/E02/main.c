#include <stdio.h>

int checkExpr(char expr[]);

int main() {
    FILE *fpIn;
    char expr[100];
    int n = 0;

    if((fpIn = fopen("../es2/expr.txt", "r")) == NULL) return 1;

    while(fgets(expr, 100, fpIn)) {
        n++;
        if(checkExpr(expr) != 0) printf("Errore nell'espressione %d\n", n);
    }

    return 0;
}

int checkExpr(char expr[]) { // 0: valid; 1: parentesi error; 2: number error; 3: operator error
    int numP = 0;
    for(int i = 0; expr[i] != '\0'; i++) {
        int c = expr[i];
        if(c == ' ') {
            if((expr[i - 1] >= '0' && expr[i - 1] <= '9') && (expr[i + 1] >= '0' && expr[i + 1] <= '9')) return 2;
        } else {
            if(i != 0) {
                int h = i - 1;
                int c0 = expr[h];
                if(c0 == ' ') {
                    while(c0 == expr[h - 1]) {
                        h--;
                    }
                    h--;
                }
                c0 = expr[h];

                if(c == '+' || c == '*' || c == '-' || c == '/' || c == '%') {
                    if(!((c0 >= '0' && c0 <= '9') || c0 == ')')) return 2;
                } else if(c == ')') {
                    if(numP == 0) return 1;
                    else numP--;

                    if(!((c0 >= '0' && c0 <= '9') || c0 == ')')) return 2;
                } else if(c == '(') {
                    numP++;

                    if (!((c0 == '+' || c0 == '*' || c0 == '-' || c0 == '/' || c0 == '%') ||
                            c0 == '('))
                        return 2;
                } else if(c >= '0' && c <= '9') {
                    if (!((c0 == '+' || c0 == '*' || c0 == '-' || c0 == '/' || c0 == '%') ||
                            c0 == '(' || (c0 >= '0' && c0 <= '9')))
                        return 2;
                } else if(c == '\n' || c == '\0') {
                    if (!(c0 == ')' || (c0 >= '0' && c0 <= '9')))
                        return 2;
                }
            } else {
                if(c == '(') numP++;
            }
        }
    }

    if(numP != 0) return 1;
    return 0;
}
