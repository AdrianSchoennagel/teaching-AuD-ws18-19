#include "stdio.h"

int main() {
    int n;
    scanf("%i", &n);
    
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    
    printf("%i\n", result);
}