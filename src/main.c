#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <klammern-core.h>

int
main (int argc, char **argv) {
	cons_t *prog =
		(cons (str ("Hans die wurst!"),
			   cons (num (42.1618),
					 cons (boolean (false), NULL))));

	print_cons (prog);
	printf ("\n");

	cons_free (prog);

	return 0;
}
