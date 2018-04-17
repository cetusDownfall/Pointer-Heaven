#include "node.h"

#ifndef INTNODE_H
#define INTNODE_H
struct data {int x;};
struct node {Data d;Node* m;};
void set_num(Data d, int x);
int get_num(Data d);
Node new_node(int x);
void set_data(Node n, int x);
int get_data(Node n);
#endif
