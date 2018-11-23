#include <stdio.h>
#include <stdlib.h>

typedef struct element *list;
struct element { int value; list next; };


// nur für Ausgabe, nicht gefordert durch Aufgabenstellung
void printList(list l) {
	if (l != NULL) {
		printf("%i, ", l->value);
		printList(l->next);
	}
}

int sum_it(list l) {
    int sum = 0;
    list f = l;
    while (f != NULL) {
        sum = sum + f->value; 
        f = f->next;
    }
    return sum;
}

int sum_rec(list l) {
    if (l == NULL) {
        return 0;
    }
    return l->value + sum_rec(l->next);
}

void rmEvens(list* l) {
    if (l == NULL || (*l) == NULL) {
        return;
    }
    if ((*l)->value % 2 == 0) {
        (*l) = (*l)->next;
    }
    else {
        l = &((*l)->next);
    }
    rmEvens(l);
}

// nur für Ausgabe, nicht gefordert durch Aufgabenstellung
int main() {
    list a = (list) malloc((sizeof(int) + sizeof(list)));
    list b = (list) malloc((sizeof(int) + sizeof(list)));
	list c = (list) malloc((sizeof(int) + sizeof(list)));
	a->value = 2; // <==> (*a).value = 2;
	a->next = b;
	b->value = 1;
	b->next = c;
	c->value = 3;
	c->next = NULL;
    
    printList(a);
    printf("\n Summe von a: %i", sum_it(a));
    printf("\n Summe rekuriv von a: %i\n", sum_rec(a));
    rmEvens(&a);
    printList(a);
}