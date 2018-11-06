#include "stdio.h"

int main () {
    int n;
    scanf("%i", &n);
    int ergebnis = 1;
    for (int i = 1; i <= n; i++) {
        ergebnis = ergebnis * i;
    }
    printf("%i\n", ergebnis);
}