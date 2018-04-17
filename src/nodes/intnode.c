#include "intnode.h"

struct data {int x;};
struct node {Data d;Node* m;};
void set_num(Data d, int x) {d->x = x;}
int get_num(Data d) {return d->x;}
Node new_node(int x) {
	Data d = (Data) malloc(sizeof(struct data));
	Node n = (Node) malloc(sizeof(struct node));
	n->d = d;
	n->m = NULL;
}
void set_data(Node n, int x) {set_num(n->d, x);}
int get_data(Node n) {return get_num(n->d);}
