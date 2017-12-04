CFLAGS += -Ilib

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o solve.o simple_prime.o
	$(CC) -o $@ $^

%_test: %.o %_test.o
	@$(CC) $(LDFLAGS) -o $@ $^

solve_test: solve_test.o solve.o simple_prime.o
	$(CC) -o $@ $^

test: simple_prime_test solve_test
	@./simple_prime_test
	@./solve_test

solve:
	@./main

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
