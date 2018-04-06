#ifndef LINKS_H
#define LINKS_H
// struct data should be completed before use of a list.
// data should be a wrapper struct around the intended type.

// Seriously recommended: Constructor to make data out of the wrapped type.
struct data;
// Implement this!
void free_data(struct data *d);

struct node {
	struct data *car;
	struct node *cdr;
};
typedef struct node* List;
List new_node(struct data *val);
List cons(struct data *a, struct node *b);
List free_node(List l);
void free_list(List l);
int len(List l);
struct data** as_arr(List l);
#endif
