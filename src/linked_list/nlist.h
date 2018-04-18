#ifndef NDEFS_H
#include "node_defs.h"
#endif
#ifndef NLIST_H
#define NLIST_H
Node new_listnode();
Node parent(Node n);
Node child(Node n);
Node* edges(Node n);
void make_edge(Node a, Node b);
void next(Node n);
void last(Node n);
#endif
