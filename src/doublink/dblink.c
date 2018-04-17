#include "dblink.h"
#include <stdlib.h>
DBList new_dbnode(struct dbdata* dbd) {
	struct dbnode* out = (struct dbnode*)malloc(sizeof(struct dbnode));
	if(out) out->d = dbd;
	return out;
}
int length(DBList s) {
	int n = 0;
	while(s) {
		s = s->r;
		n++;
	}
	return n;
}
DBList index(DBList s, int ind) {
	while(ind--) s=s->r;
	return s;
}
DBList head(DBList s) {
	while(s->l) s = s->l;
	return s;
}
DBList tail(DBList s) {
	while(s->r) s = s->r;
	return s;
}
DBList append(DBList left, DBList right) {
	DBList hr = head(right);
	hr->l = tail(left);
	hr->l->r=hr;
	return head(hr);
}
