LIBDIR   = ../../lib/c
OPTIMISE = -O3
CFLAGS 	+= -Iinc -I$(LIBDIR)/include -std=c11 -Wall -pedantic $(OPTIMISE)
LDFLAGS  = -L$(LIBDIR)/lib -lm -leuler $(OPTIMISE)
SOURCES  = $(wildcard src/*.c)
TESTS    = $(wildcard test/*.c)

build: $(SOURCES:%.c=%.o)

#check:

test: test/test

test/test: $(SOURCES:%.c=%.o) $(TESTS:%.c=%.o) test/test.o
	$(CC) -o $@ $^ $(LDFLAGS)

test/test.c: $(PROBLEMS:%=%/test.c) test/test.rb
	cd test && ruby test.rb > test.c

#%/solve: %/solve.o %/main.o
#	$(CC) -o $@ $^ $(LDFLAGS)

#$(LIBEULER):
#	cd $(LIBDIR) && make

.PHONY: build solve clean test
