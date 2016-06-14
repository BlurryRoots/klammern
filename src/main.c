#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <klammern-core.h>



#define STDINBYTES 1024

typedef void (*stdio_callback_t) (const char*, int);

void
read_from_stdio (stdio_callback_t cb, int max_buffer_size) {
	int bytes_read;
	const char stdin_data[max_buffer_size];

	while (0 < (bytes_read = read (fileno (stdin), stdin_data, max_buffer_size))) {
		cb (stdin_data, bytes_read);
	}
}

void
write_stdout (const char *buffer, int length) {
	write (fileno (stdout), buffer, length);
}

void
on_read_from_stdio (const char *buffer, int length) {
	printf ("read %i bytes\n", length);
}

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
