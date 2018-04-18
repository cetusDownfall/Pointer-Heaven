#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "intnode.h"
#include "nlist.h"

int main(void) {
	int n;
	Node top, head;
	head = new_listnode();
	set_data(head, 0);
	top = head;
	for(n=1;n<100;n++,next(top)) {
		printf("adding %d\n", n);
		Node t = new_listnode();
		set_data(t, n);
		make_edge(top, t);
	}
	top = head;
	while(top) {
		printf("%d ", get_data(top));
		next(top);
	}
	return 0;
}

Node new_node() {
	Data d = (Data) malloc(sizeof(struct data));
	Node n = (Node) malloc(sizeof(struct node));
	d = NULL;
	if(d&&n) {
		n->d = d;
		n->m = NULL;
		return n;
	}
	else return NULL;
}
