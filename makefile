CC=clang
INC=inc

all: clean build

clean:
	mkdir -p bin
	rm -rf bin/*

build:
	$(CC) -I$(INC) -o bin/klammern-core.o -c src/klammern-core.c
	$(CC) -I$(INC) -o bin/klammern bin/klammern-core.o src/main.c