DATAFILE =
CFLAGS 	+= -Ilib -std=c99
LDFLAGS  = -lm
LIBS 	 = simple_prime
DEPS 	 = solve.o factorial.o pandigital.o
DEPS 	+= $(LIBS:%=lib/%.a)

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

%_test: %_test.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

test: solve_test factorial_test pandigital_test
	@./pandigital_test
	@./factorial_test
	@./solve_test

solve:
	@./main

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
