#include "dblink.h"
#include <stdlib.h>
DBList new_dbnode(struct dbdata* dbd) {
	struct dbnode* out = (struct dbnode*)malloc(sizeof(struct dbnode));
	if(out) {
		out->d = dbd;
		out->l = NULL;
		out->r = NULL;
	}
	return out;
}
int length(DBList s) { int n = 0; while(s) { s = s->r; n++; } return n; }
DBList index(DBList s, int ind) { while(ind--) s=s->r; return s; }
DBList head(DBList s) { while(s->l) s = s->l; return s; }
DBList tail(DBList s) { while(s->r) s = s->r; return s; }
DBList append(DBList left, DBList right) {
	DBList tl = tail(left);
	tl->r = head(right);
	if(tl->r) tl->r->l=tl;
	return head(tl);
}
void free_dbnode(DBList s) { if(s&&s->d) free_dbdata(s->d); if(s) free(s); }
void free_dblist(DBList s) {
	if(s) {
		if(s->l) free_dblist(head(s)); 
		else { s->r->l = NULL; free_dblist(s->r); free_dbnode(s); }
	}
}
DBList remove_node(DBList s) { s->r->l = s->l; s->l->r = s->r; free_dbnode(s); }
DBList insert_left(DBList a, DBList b) { a->l->r = head(b); head(b)->l = a->l; a->l = tail(b); tail(b)->r = a; }
DBList insert_right(DBList a, DBList b) { a->r->l = tail(b); tail(b)->r = a->r; a->r = head(b); head(b)->l = a->r; }
DBList* split_at(DBList s) {
	DBList *out = (DBList*) malloc(sizeof(DBList) * 2);
	if(out&&s) {
		out[0] = head(s); out[1] = s;
		s->l->r = NULL; s->l = NULL;
	} return out;
}
