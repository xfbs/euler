DATAFILE =
CFLAGS 	+= -Ilib -std=c99
LDFLAGS  = -lm
LIBS 	 =
DEPS 	 = solve.o even_fibonacci.o
DEPS	+= $(LIBS:%=lib/%.a)

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

%_test: %_test.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

test: solve_test even_fibonacci_test
	@./even_fibonacci_test
	@./solve_test

solve:
	@./main

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
