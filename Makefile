SRCS=$(wildcard *.c)

all: abk

abk: $(SRCS)
	gcc -g -o abk $^

clean:
	rm -rf abk
