#include <stdio.h>
#include "../../src/stack/chstack.c"

int main(void) {
	chStack ch = new_stack();
	push(ch, '!');
	push(ch, 'd'); 
	push(ch, 'l');
	push(ch, 'r');
	push(ch, 'o');
	push(ch, 'W');
	push(ch, ' ');
	push(ch, ',');
	push(ch, 'o');
	push(ch, 'l');
	push(ch, 'l');
	push(ch, 'e');
	push(ch, 'H');
	printf("Using to_string:\n%s\n", to_string(ch));
	printf("Using into_string:\n%s\n", into_string(ch));
	printf("Using to_string:\n%s\n", to_string(ch));
	return 0;
}
