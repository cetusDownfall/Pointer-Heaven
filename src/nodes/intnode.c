#include "intnode.h"

void set_num(Data d, int x) {d->x = x;}
int get_num(Data d) {return d->x;}
void set_data(Node n, int x) {set_num(n->d, x);}
int get_data(Node n) {return get_num(n->d);}
