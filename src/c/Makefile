LIBDIR   = ../../lib/c/euler
OPTIMIZE = -O3
CFLAGS 	+= -Iinc -I$(LIBDIR)/include -std=c11 -Wall -pedantic $(OPTIMIZE)
LDFLAGS  = -L$(LIBDIR)/lib -lm -leuler $(OPTIMIZE)
SOURCES  = $(wildcard src/*.c)
TESTS    = $(wildcard test/*.c)

build: bin/solve

test: test/test
	./test/test

test/test: $(SOURCES:%.c=%.o) $(TESTS:%.c=%.o) test/test.o
	$(CC) -o $@ $^ $(LDFLAGS)

test/test.c: $(PROBLEMS:%=%/test.c) test/test.rb
	cd test && ruby test.rb > test.c

bin/%: bin/%.o $(SOURCES:%.c=%.o)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) bin/*.o src/*.o test/*.o bin/solve test/test

#%/solve: %/solve.o %/main.o
#	$(CC) -o $@ $^ $(LDFLAGS)

#$(LIBEULER):
#	cd $(LIBDIR) && make

.PHONY: build solve clean test
