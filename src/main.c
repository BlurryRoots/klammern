#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <klammern-core.h>

int
main (int argc, char ** argv) {
	struct cons_t *prog;
	
	prog = cons (num (42), cons (boolean (false), NULL));

	print_cons (prog);
	printf ("\n");

	free (prog->tail);
	free (prog);

	return 0;
}