CC=clang

all: clean build

clean:
	mkdir -p bin
	rm -rf bin/*

build:
	$(CC) -o bin/klammern src/main.c 