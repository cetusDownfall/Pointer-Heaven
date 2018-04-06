#include "links.h"
#include <stdlib.h>
struct node* new_node(struct data *val) {
	struct node* h = malloc(sizeof(struct node));
	if (h) {
		h->car = val;
		h->cdr = NULL;
	}
	return h;
}
struct node* cons(struct data *a, struct node *b) {
	struct node *h = new_node(a);
	h->cdr = b;
	return h;
}
struct node* free_node(struct node *l) {
	struct node* out = NULL;
	if (l) {
		out = l->cdr;
		free_data(l->car);
		free(l);
	}
	return out;
}
void free_list(struct node *l) {
	if (l) {
		if (l->cdr) free_list(l->cdr);
		free_node(l);
	}
}
int len(List l) {
	int ct = 0;
	List t = l;
	while (t) {
		ct++;
		t = t->cdr;
	}
	return ct;
}
struct data** as_arr(List l) {
	if (l) {
		struct data** out = (struct data**)malloc(sizeof(struct data*)*len(l));
		if (out) {
			List t;
			struct data** m;
			for (t = l, m = out; t; t = t->cdr) *(m++) = t->car;
		}
		return out;
	}
	else return NULL;
}
