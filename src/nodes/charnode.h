#ifndef NDATA
#define NDATA
struct data {char c;};
#endif

#include "node.h"

#ifndef CHARNODE_H
#define CHARNODE_H

void set_char(Data d, char c);
char get_char(Data d);
void set_data(Node n, char c);
char get_data(Node n);
#endif
