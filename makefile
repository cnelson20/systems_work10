all: structlist

structlist: structlist.o
	gcc -o structlist structlist.o

structlist.o: structlist.c
	gcc -c structlist.c

run: 
	./structlist
