#ifndef DBLINK_h
#define DBLINK_H
struct dbdata;
void free_dbdata(struct dbdata* dbd);
struct dbnode { 
	struct dbdata* d; 
	struct dbnode* l;
	struct dbnode* r;
};
typedef struct dbnode* DBList;
DBList new_dbnode(struct dbdata* dbd);
int length(DBList s);
DBList index(DBList s, int ind);
DBList head(DBList s);
DBList tail(DBList s);
DBList append(DBList left, DBList right);
#endif
