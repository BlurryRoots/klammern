CC=clang
INC=inc

all: clean build

clean:
	mkdir -p bin
	rm -rf bin/*

build-debug:
	$(CC) --std=c11 -I$(INC) -g -o bin/klammern-core.o -c src/klammern-core.c
	$(CC) --std=c11 -I$(INC) -g -o bin/klammern bin/klammern-core.o src/main.c

build:
	$(CC) --std=c11 -I$(INC) -o bin/klammern-core.o -c src/klammern-core.c
	$(CC) --std=c11 -I$(INC) -o bin/klammern bin/klammern-core.o src/main.c

grind: build
	valgrind --leak-check=full bin/./klammern > log/out 2> log/err

debug: clean build-debug
	gdb bin/klammern

run: build
	bin/./klammern