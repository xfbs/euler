DATAFILE =
CFLAGS 	+= -Ilib -std=c99 -Wall -pedantic
LDFLAGS  = -lm
LIBS 	 = bitvec
DEPS 	 = solve.o divisor_sum.o
DEPS	+= $(LIBS:%=lib/%.a)

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

%_test: %_test.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

test: solve_test divisor_sum_test
	@./solve_test
	@./divisor_sum_test

solve:
	@./main

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
