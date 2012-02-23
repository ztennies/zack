all: htbl

htbl: main.o linked-list.o hash-table.o
	gcc -o htbl main.o linked-list.o hash-table.o

main.o: main.c linked-list.h hash-table.h
	gcc -c main.c

hash-table.o: hash-table.c hash-table.h linked-list.h
	gcc -c hash-table.c

linked-list.o: linked-list.c linked-list.h
	gcc -c linked-list.c

.PHONY : clean
clean:
	rm -rf *.o htbl *~ *.core *core