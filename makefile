CFLAGS=-Wall g

all:
	gcc -o main main.c ./src/*

clean:
	rm -f main
