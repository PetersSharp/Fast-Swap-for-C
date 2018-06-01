CFLAGS = -g -O2 -std=gnu99 -Wall -pedantic -funit-at-a-time

all: clean swap-test

swap-test: \
    swap-test.c

clean:
	rm -f swap-test
	rm -f swap-test.o
