#ifndef CHSTACK_H
#define CHSTACK_H
struct data { char c; };
struct ch_lower { List h; };
typedef struct ch_lower* chStack;
chStack new_stack(void);
char peek(chStack ch);
char pop(chStack ch);
int push(chStack ch, char v);
char* to_string(chStack ch);
char* into_string(chStack ch);
#endif
