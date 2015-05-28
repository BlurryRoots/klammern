#include <stdbool.h>
#include <string.h>

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
typedef
	struct nucleus_t
	nucleus_t;

struct cons_t {
	struct nucleus_t head;
	struct cons_t *tail;
};
typedef
	struct cons_t
	cons_t;

#define car(cons)\
	cons->head
#define cdr(cons)\
	cons->tail
#define set_type(n, t)\
	n.type = t
#define set_data(n, f, v)\
	n.data.f = v

cons_t*
cons_new (void);

nucleus_t
str (const char * v);

nucleus_t
num (float v);

nucleus_t
boolean (bool v);

cons_t*
cons (nucleus_t n, cons_t *tail);

void
print_cons (cons_t *c);

void
display (nucleus_t nucleus);
