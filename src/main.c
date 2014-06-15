#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

enum type_e {
	DATA_BOOLEAN,
	DATA_NUMBER,
	DATA_STRING
};

union data_t {
	bool boolean;
	float number;
	char *string;
};

struct nucleus_t {
	enum type_e type;
	union data_t data;
};

struct cons_t {
	struct nucleus_t head;
	struct cons_t *tail;
};

#define car(cons)\
	cons->head
#define cdr(cons)\
	cons->tail
#define set_type(n, t)\
	n.type = t
#define set_data(n, f, v)\
	n.data.f = v

void
display (struct nucleus_t nucleus) {
	switch (nucleus.type) {
		case DATA_BOOLEAN:
			printf ("%s", nucleus.data.boolean ? "true" : "false");
			break;
		case DATA_NUMBER:
			printf ("%f", nucleus.data.number);
			break;
		case DATA_STRING:
			printf ("%s", nucleus.data.string);
			break;
		default:
			printf ("Not yet implemented!\n");
			break;
	}
}

void
print_cons (struct cons_t *c) {
	struct cons_t *runner = c;

	printf ("(");

	while (NULL != runner) {
		display (runner->head);

		runner = runner->tail;
		if (NULL != runner) {
			printf (" . ");
		}
	}

	printf (")");
}

struct cons_t*
cons_new () {
	struct cons_t *c = malloc (sizeof (struct cons_t));
	assert (c);

	c->tail = NULL;

	return c;
}

struct nucleus_t
num (float v) {
	struct nucleus_t n;

	n.type = DATA_NUMBER;
	n.data.number = v;

	return n;
}
struct nucleus_t
boolean (bool v) {
	struct nucleus_t n;

	n.type = DATA_BOOLEAN;
	n.data.boolean = v;

	return n;
}

struct cons_t*
cons (struct nucleus_t n, struct cons_t *tail) {
	struct cons_t *c;

	c = cons_new ();
	assert (c);
	c->head = n;

	c->tail = tail;

	return c;
}

int
main (int argc, char **argv) {
	struct cons_t *prog;
	
	prog = cons (num (42), cons (boolean (false), NULL));

	print_cons (prog);
	printf ("\n");

	free (prog->tail);
	free (prog);

	return 0;
}