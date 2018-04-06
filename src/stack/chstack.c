#ifndef LINKS_H
#include "../linked_list/links.c"
#endif
#include "chstack.h"
void free_data(struct data* d) { free(d); }
struct data* new_data(char v) {
	struct data* h = malloc(sizeof(struct data));
	if (h) h->c = v;
	return h;
}
chStack new_stack(void) {
	chStack h = malloc(sizeof(struct ch_lower));
	if (h) h->h = new_node(new_data('\0'));
	return h;
}
char peek(chStack ch) { 
	if (ch&&ch->h) return ch->h->car->c; 
	else return '\0';
}
char pop(chStack ch) {
	char n;
	if (ch&&ch->h) {
		n = ch->h->car->c;
		if (n!='\0') ch->h = free_node(ch->h);
	}
	return n;
}
int push(chStack ch, char v) {
	return (ch->h = cons(new_data(v), ch->h))?1:0;
}
char* to_string(chStack ch) {
	if (ch&&ch->h) {
		struct data** ncs = as_arr(ch->h);
		if (ncs) {
			char *out = malloc(sizeof(char)* (len(ch->h) + 1));
			if (out) {
				struct data** nc;
				char *oind;
				for (oind=out, nc=ncs;(*nc)->c!='\0';*(oind++)=((*(nc++))->c));
				*oind = (*nc)->c;
			}
			free(ncs);
			return out;
		} else return NULL;
	} else return NULL;
}
char* into_string(chStack ch) {
	if(ch&&ch->h) {
		char* out = malloc(sizeof(char) * (len(ch->h) + 1));
		if (out) {
			char *oind=out;
			while ('\0' != (*(oind++) = pop(ch)));
		}
		return out;
	} else return NULL;
}
