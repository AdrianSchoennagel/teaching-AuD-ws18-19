// Kommentare

/*
mehrzeilige Kommentare
*/
/*
int i = 5;
double d = 5.5;
float f = 5.5;
char c = 'c';
char l = '&uuml'; // ü

char wort[100]; // Wörter bzw Listen aus char's

if (i == 6) {
    // Kode wenn i gleich 6
}

if (i == 6) {
    // Kode wenn i gleich 6
}
else {
    // Kode wenn i nicht gleich 6
}

// Zahlschleife
for (int i = 0; i < 15; i = i+1) {
    // Kode der 15mal ausgeführt werden soll
}*/

// i++; <=> i = i+1;
  
#include "stdio.h"  
  
  
void a2a() {
    char name[100];
    scanf("%s", name);
    printf("Hallo %s\n", name);
}

void a2b() {
    int n;
    scanf("%i", &n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%i ", i*j);
        }
        printf("\n");
    }
}

#include "stdbool.h"

void a2c() {
    int n = 1000;
    
    bool isPrim;
    
    for (int prim = 1; prim <= n; prim++) {
        isPrim = true;
        for (int i = 2; (i < prim/2 && isPrim); i++) {
            if ((prim % i) == 0) {
                isPrim = false;
            }
        }
        
        if (isPrim) {
            printf("%i\n", prim);
        }
        
    }
}
  
int main() {
    a2c();
    return 0;
}    
    
    
    
    
    
    
    
    
    
    