#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <klammern-core.h>

void
display (nucleus_t nucleus) {
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
print_cons (cons_t *c) {
	cons_t *runner = c;

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

cons_t*
cons_new () {
	cons_t *c = malloc (sizeof (cons_t));
	assert (c);

	c->tail = NULL;

	return c;
}

void
cons_free (cons_t* c) {
	if (NULL == c) {
		return;
	}

	cons_t *runner = c;
	while (NULL != runner) {
		if (DATA_STRING == c->head.type) {
			free (c->head.data.string);
		}
		runner = runner->tail;
	}
}

nucleus_t
str (const char * v) {
	nucleus_t n;
	size_t c = strlen (v);

	n.type = DATA_STRING;
	n.data.string = malloc (c * sizeof (char));
	assert (n.data.string);

	strncpy (n.data.string, v, c);

	return n;
}

nucleus_t
num (float v) {
	nucleus_t n;

	n.type = DATA_NUMBER;
	n.data.number = v;

	return n;
}

nucleus_t
boolean (bool v) {
	nucleus_t n;

	n.type = DATA_BOOLEAN;
	n.data.boolean = v;

	return n;
}

cons_t*
cons (nucleus_t n, cons_t *tail) {
	cons_t *c;

	c = cons_new ();
	assert (c);
	c->head = n;

	c->tail = tail;

	return c;
}
