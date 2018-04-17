#include "..\..\src\doublink\dblink.c"
#include <stdio.h>
#include <stdlib.h>

struct dbdata {char *c;};
DBList new_node(char *c);
void append_string(DBList lst, char* s);
DBList from_string(char* s);
int main(void) {
	int n, l;
	char st[14] = "Hello, World!";
	printf("we are about to append string\n");
	printf("%s\n", st);
	DBList hello = from_string(st);
	printf("we got past append string\n");
	l = length(hello);
	for (n=0; n < l; n++) printf("%c", *(index(hello, n)->d->c));
	printf("\n");
	return 0;
}
void free_dbdata(struct dbdata* dbd) {
	free(dbd->c);
	free(dbd);
}
DBList new_node(char *c) {
	struct dbdata* out = malloc(sizeof(struct dbdata));
	if(out) out->c = c;
	return new_dbnode(out);
}
void append_string(DBList lst, char *s) {
	char* i = s;
	while(*i) lst = append(lst, new_node(i++));
}
DBList from_string(char* s) {
	DBList out = new_node(s);
	append_string(out, s+1);
	return out;
}
