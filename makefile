all: randfile.o
	gcc -o program randfile.o 

randfile.o:
	gcc -c randfile.c

run:
	./program