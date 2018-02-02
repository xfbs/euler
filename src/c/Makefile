LIBDIR   = ../../lib/c
OPTIMISE = -O3
CFLAGS 	+= -Isrc -I$(LIBDIR)/include -std=c11 -Wall -pedantic $(OPTIMISE)
LDFLAGS  = -L$(LIBDIR)/lib -lm -leuler $(OPTIMISE)
PROBLEMS = $(wildcard ???)

build: $(PROBLEMS:%=%/solve)

check:

test:

%/solve: %/solve.o %/main.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(LIBEULER):
	cd $(LIBDIR) && make

.PHONY: build solve clean test
