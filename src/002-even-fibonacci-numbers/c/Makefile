CFLAGS += -Ilib -std=c99
LIBS =
DEPS = $(LIBS:%=lib/%.a) solve.o even_fibonacci.o

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) -o $@ $^

%_test: %_test.o $(DEPS)
	@$(CC) $(LDFLAGS) -o $@ $^

test: solve_test even_fibonacci_test
	@./even_fibonacci_test
	@./solve_test

solve:
	@./main

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
