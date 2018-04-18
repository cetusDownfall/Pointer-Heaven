#ifndef NDEFS_H
#define NDEFS_H
struct data;
struct node;
typedef struct data* Data;
typedef struct node* Node;
struct node {Data d; Node* m;};
#endif
