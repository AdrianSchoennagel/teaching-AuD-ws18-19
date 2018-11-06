// Kommentar
/*
mehrzeiliges Kommentar

int i = 5;               ganze Zahl
double d = -3.87;        Kommazahlen
string s = "Hallo Welt"; Zeichenkette
char c = 'c';            Zeichen

s = 'd'; s = "d";
s = 'c' + 'd'; // --> s = "cd"
s = "cd" + 'g';


s = "\n" //Zeilenumbruch ("Enter")

if (_Bedingung_) {
  _Befehle_
}
else {
  _Befehle_
}

//10 mal
// i++; <==> i = i + 1;
for (int i = 0; i < 10; i++) {
    _Befehle_
}


// Ein- und Ausgabe
#include "stdio.h"

String name;

String* Speicheraddresse = &name;

scanf("%s", &name);
scanf("%s", Speicheraddresse);

printf("Hallo Welt"); // Ausgabe von Hallo Welt
printf("Halle %s", name); // Ausgabe von Hallo Peter 
*/

#include "stdio.h"

void a2a() {
    char name[10];
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
    for (int prim = 2; prim <= 1000; prim++) {
        bool isPrim = true;
        for (int j = 2; (j <= prim/2 && isPrim); j++) {
            if (prim % j == 0) {
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
}
