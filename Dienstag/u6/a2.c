#include <stdio.h>
#include <stdlib.h>

typedef struct element *list;
struct element { int value; list next; };


void printList(list l) {
	if (l != NULL) {
		printf("%i, ", l->value);
		printList(l->next);
	}
}

int sum_it(list l) {
    if (l == NULL) {
        return 0;
    }
    int sum = l->value;
    list f = l->next; // weil l nicht verändert werden soll
    while (f != NULL) {
        sum += f->value;  // gleich wie sum = sum + f->value;
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

void remEvens_rec(list *l) {
    if (l == NULL || (*l) == NULL) {
        return;
    }
    if ((*l)->value % 2 == 0) {
        // gerade Zahl
        list d = *l;
        (*l) = (*l)->next;
        free(d);
    }
    else {
        l = &(*l)->next;
    }
    remEvens_rec(l);
    
}

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
    printf("\nSumme iterativ: %i\n", sum_it(a));
    printf("Summe rekursiv: %i\n", sum_rec(a));
    remEvens_rec(&a);
    printList(a);
    
    /*free(a);
    free(b);
    free(c);*/
}