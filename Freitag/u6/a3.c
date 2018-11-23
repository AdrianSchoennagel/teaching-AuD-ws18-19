#include "stdlib.h"
#include "stdio.h"

typedef struct node *tree;
typedef struct node {int key; tree left; tree right; } node;

// nur für Ausgabe, nicht gefordert durch Aufgabenstellung
void printTree(tree t) {
	if (t == NULL) {
		printf(" ");
		return;
	}
	printf("%i {", t->key);
	printTree(t->left);
	printf(" ,");
	printTree(t->right);
	printf(" }");
}

// Wie oft kommt key in s vor?
int count(int key, tree s) {
    if (s == NULL) {
        return 0;
    }
    if (key == s->key) {
        return 1 + count(key, s->left) + count(key, s->right);
    }
    else {
        return count(key, s->left) + count(key, s->right);
    }
}

tree baz(tree s, tree t) {
    if (s == NULL) {
        return NULL;
    }
    else if (t == NULL) {
        return s;
    }
    tree k = (tree) malloc(sizeof(node));
    k->key = count(s->key, t);
    k->left = baz(s->left, t);
    k->right = baz(s->right, t);
    return k;
}

int leafprod(tree t) {
    if (t == NULL) {
        return 1;
    }
    if (t->left == NULL && t->right == NULL) {
        // kein Nachfolger links und rechts -> Blatt
        return t->key;
    }
    else {
        return leafprod(t->left) * leafprod(t->right);
    }
}

// nur für Ausgabe, nicht gefordert durch Aufgabenstellung
int main() {
    node a, b, c, d, e ,f, g, h;
    tree s, t;
    a.key = 2; a.left = &b; a.right = &c;
	b.key = 3; b.left = &d; b.right = &e;
	c.key = 1; c.left = NULL, c.right = NULL;
	d.key = 2; d.left = NULL, d.right = NULL;
	e.key = 4; e.left = NULL, e.right = NULL;
	s = &a;
	f.key = 2; f.left = &g; f.right = &h;
	g.key = 2; g.left = NULL; g.right = NULL;
	h.key = 3; h.left = NULL; h.right = NULL;
	t = &f;
    
    printf("Baum t: ");
    printTree(t);
    printf("\n Baum s: ");
    printTree(s);
    printf("\n baz s und t: ");
    printTree(baz(s, t));
    printf("\n leafprod(t): %i", leafprod(t));
    printf("\n leafprod(s): %i\n", leafprod(s));
}