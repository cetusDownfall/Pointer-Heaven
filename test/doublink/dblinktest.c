#include "..\..\src\doublink\dblink.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dbdata {char *c;};
void free_dbdata(struct dbdata* dbd) {
	free(dbd->c);
	free(dbd);
}
DBList new_node(char *c);
DBList append_string(DBList lst, char* s);
DBList from_string(char* s);
DBList find_char(DBList lst, char c);
void split_to_words(DBList lst);
char* to_string(DBList lst);
int main(void) {
	DBList hello, *ps, t;
	char st[] = "The quick brown fox did something I really don't care about.";
	hello = from_string(st);
	printf("%s\n", to_string(hello));
	printf("\nString was %d chars long.\n", length(hello));
	ps = split_at(find_char(hello, 's'));
	printf("%s [length: %d]\n%s [length: %d]\n",
		to_string(ps[0]), strlen(to_string(ps[0])),
	    	to_string(ps[1]), strlen(to_string(ps[1])));
	append(ps[0], ps[1]);
	hello = head(ps[0]);
	split_to_words(hello);
	t=tail(hello);
	while(t) { printf("%s\n", t->d->c); t=t->l; }
	return 0;
}
DBList new_node(char *c) {
	struct dbdata* out = malloc(sizeof(struct dbdata));
	if(out) out->c = c;
	return new_dbnode(out);
}
DBList append_string(DBList lst, char *s) {
	if(*s) {
		lst = append(lst, new_node(s));
		append_string(lst, s+1);
	}
	else return lst;
}
DBList from_string(char* s) {
	return append_string(new_node(s), s+1);
}
DBList find_char(DBList lst, char c) {
	DBList t;
	for(t=lst;*(t->d->c)!=c && t;t=t->r);
	return t;
}
char* to_string(DBList lst) {
	char *out, *t;
	DBList l = head(lst);
	out = (char*) malloc(sizeof(char) * (length(lst)+1));
	for(t = out; l; *(t++) = *(l->d->c), l=l->r);
	out[length(lst)] = '\0';
	return out;
}
void split_to_words(DBList lst) {
	char *wd, *curr;
	DBList t;
	wd = to_string(lst);
	t = lst;
	curr=wd;
	for(;;) {
		if(*curr==' ') {
			*curr='\0';
			free(t->d->c);
			t->d->c = wd;
			t = t->r;
			wd=curr+1;
			curr=wd;
		} else if(*curr=='\0') {
			free(t->d->c);
			t->d->c = wd;
			t->r->l = NULL;
			t->r = NULL;
			free_dblist(t->r);
			break;
		} else curr++;
	}
}
