CFLAGS += -Ilib
LIBS = simple_prime bitvec
DEPS = $(LIBS:%=lib/%.a) solve.o divisor_sum.o

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) -o $@ $^

%_test: %_test.o $(DEPS)
	@$(CC) $(LDFLAGS) -o $@ $^

test: solve_test divisor_sum_test
	@./solve_test
	@./divisor_sum_test

solve:
	@./main

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
