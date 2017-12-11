DATAFILE = ../numbers.txt
CFLAGS 	+= -Ilib -std=c99 -Wall -pedantic
LDFLAGS  = -lm
LIBS 	 =
DEPS 	 =
DEPS	+= $(LIBS:%=lib/%.a)

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

%_test: %_test.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

test:

solve:
	@./main $(DATAFILE)

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
