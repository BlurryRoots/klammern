#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <klammern-core.h>

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