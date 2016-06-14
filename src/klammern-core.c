#define _CRT_SECURE_NO_WARNINGS 1 // supresses strncpy_s error (thx ms!)

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

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
			printf ("'%s'", nucleus.data.string);
			break;
		default:
			printf ("Not yet implemented!\n");
			break;
	}
}

void
print_cons (const cons_t* c) {
	assert (NULL != c);

	const cons_t* runner = c;

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
cons_new (void) {
	cons_t* c = malloc (sizeof (cons_t));
	assert (NULL != c);

	c->tail = NULL;

	return c;
}

cons_t*
cons (nucleus_t n, cons_t* tail) {
	cons_t* c;

	c = cons_new ();
	c->head = n;

	c->tail = tail;

	return c;
}

void
cons_free (cons_t* c) {
	if (NULL == c) {
		return;
	}

	// do type specific clean-up
	switch (c->head.type) {
		case DATA_STRING:
			free (c->head.data.string);
			break;
		default:
			// nothing to do here ;)
			break;
	}

	// mark type as disposed
	c->head.type = DATA_DISPOSED;

	// clean up child nodes before deleting this node
	cons_free (c->tail);

	// invalidate child pointer and free node
	c->tail = NULL;
	free (c);
}

nucleus_t
str (const char* v) {
	assert (NULL != v);

	nucleus_t n;
	size_t c = strlen (v);

	n.type = DATA_STRING;
	n.data.string = calloc (c + 1, sizeof (char)); // +1 for null terminator
	assert (NULL != n.data.string);

	strncpy (n.data.string, v, c);
	n.data.string[c] = '\0';

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
