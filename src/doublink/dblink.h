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
void free_dbnode(DBList s);
void free_dblist(DBList s);
DBList remove_node(DBList s);
DBList insert_left(DBList a, DBList b);
DBList insert_right(DBList a, DBList b);
DBList* split_at(DBList s);
#endif
