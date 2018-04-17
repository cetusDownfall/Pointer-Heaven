#include "node.h"
#ifndef CHARNODE_H
#define CHARNODE_H

struct data {char c;};
void set_char(Data d, char c);
char get_char(Data d);
Node new_node(char c);
void set_data(Node n, char c);
char get_data(Node n);
#endif
