#ifndef NDEFS_H
#include "node_defs.h"
#endif
#ifndef NDATA
#define NDATA
struct data {int x;};
#endif
#ifndef INTNODE_H
#define INTNODE_H
void set_num(Data d, int x);
int get_num(Data d);
void set_data(Node n, int x);
int get_data(Node n);
#endif
