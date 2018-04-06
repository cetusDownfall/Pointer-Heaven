#include "C:\Users\okada\Documents\GitHub\pointer_heaven\src\linked_list\links.c"
#include <stdio.h>
#include <stdlib.h>

struct data { char c; };
void free_data(struct data *d) { free(d); }
typedef struct data* NodeChar;
NodeChar new_data(char v);
char* as_string(struct node* l);
int main(void) {
	struct node* hList =
	cons(new_data('H'),
	cons(new_data('e'),
	cons(new_data('l'),
	cons(new_data('l'),
	cons(new_data('o'),
	cons(new_data(','),
	cons(new_data(' '),
	cons(new_data('W'),
	cons(new_data('o'),
	cons(new_data('r'),
	cons(new_data('l'),
	cons(new_data('d'), 
	new_node(new_data('!'))))))))))))));
	printf("%s\n", as_string(hList));
	free_list(hList);
	int i;
	printf("%s\n", as_string(hList));
	return 0;
}

NodeChar new_data(char v) {
	NodeChar h = malloc(sizeof(struct data));
	if (h) h->c = v;
	return h;
}
char* as_string(struct node* l) {
	if (l) {
		NodeChar* ncs = as_arr(l);
		if (ncs) {
			char *out = malloc(sizeof(char)* (len(l) + 1));
			if (out) {
				char* oind;
				NodeChar* nc;
				int i;
				for (i=0, nc=ncs ,oind=out;i<len(l);i++,*(oind++)=((*(nc++))->c));
				oind = '\0';
			}
			return out;
		}
		return NULL;
	}
	return NULL;
}
