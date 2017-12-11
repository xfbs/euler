DATAFILE =
CFLAGS += -Ilib -std=c99
LDFLAGS = -lm
LIBS =
DEPS = $(LIBS:%=lib/%.a) solve.o simple_prime.o

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

%_test: %_test.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

test: simple_prime_test solve_test
	@./simple_prime_test
	@./solve_test

solve:
	@./main

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
