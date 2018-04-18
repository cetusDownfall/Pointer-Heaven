#include "nlist.h"
#ifndef NODE_H
#include "node.h"
#endif
#include <stdlib.h>
Node new_listnode() {
	Node n = new_node();
	Node *m = (Node*) malloc(sizeof(Node)*2);
	if(m&&n) {
		n->d = NULL; *m = NULL; *(m+1) = NULL;
		n->m = m;
	       	return n;
	} 
	else return NULL;
}
Node parent(Node n) {return *(n->m);}
Node child(Node n) {return *(n->m+1);}
Node* edges(Node n) {return (n->m);}
void make_edge(Node a, Node b) { edges(a)[0] = b; edges(b)[1] = a; }
void next(Node n) {n=child(n);}
void last(Node n) {n=parent(n);}
