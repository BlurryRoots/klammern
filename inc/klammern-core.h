#include <stdbool.h>

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
	struct cons_t * tail;
};

#define car(cons)\
	cons->head
#define cdr(cons)\
	cons->tail
#define set_type(n, t)\
	n.type = t
#define set_data(n, f, v)\
	n.data.f = v

struct cons_t *
cons_new ();

struct nucleus_t
num (float v);

struct nucleus_t
boolean (bool v);

struct cons_t *
cons (struct nucleus_t n, struct cons_t * tail);

void
print_cons (struct cons_t * c);

void
display (struct nucleus_t nucleus);