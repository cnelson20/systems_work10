all: structlist
	

structlist: structlist.o
	gcc -o structlist structlist.o

structy.o: structlist.c
	gcc -c structlist.c

run: 
	./structlist
