LIBDIR   = ../../lib/c
OPTIMISE = -O3
CFLAGS 	+= -Isrc -I$(LIBDIR)/include -std=c11 -Wall -pedantic $(OPTIMISE)
LDFLAGS  = -L$(LIBDIR)/lib -lm -leuler $(OPTIMISE)
SOURCES  = $(wildcard src/*.c)

build: $(SOURCES:%.c=%.o)

src/%.o: src/%.c src/%.h
	$(CC) $(CFLAGS) -c $<

#check:

#test: test/test

#test/test: $(PROBLEMS:%=%/test.o) $(PROBLEMS:%=%/solve.o) test/all.o
#	$(CC) -o $@ $^ $(LDFLAGS)

#test/all.c: $(PROBLEMS:%=%/test.c) test/all.rb
#	cd test && ruby all.rb > all.c

#%/solve: %/solve.o %/main.o
#	$(CC) -o $@ $^ $(LDFLAGS)

#$(LIBEULER):
#	cd $(LIBDIR) && make

.PHONY: build solve clean test
