#include "charnode.h"
#include "node.h"
void free_data(Data d) {free(d);}

void set_char(Data d, char c) {d->c = c;}
char get_char(Data d) {return d->c;}
void set_data(Node n, char c) {set_char(n->d, c);}
char get_data(Node n) {return get_char(n->d);}
