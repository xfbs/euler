DATAFILE =
CFLAGS 	+= -Ilib -std=c99 -Wall -pedantic
LDFLAGS  = -lm
LIBS 	 =
DEPS 	 = solve.o palindrome.o
DEPS	+= $(LIBS:%=lib/%.a)

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

%_test: %_test.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

test: solve_test palindrome_test
	@./palindrome_test
	@./solve_test

solve:
	@./main

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
