DATAFILE =
CFLAGS += -Ilib -std=c99
LDFLAGS = -lm
LIBS =
DEPS = $(LIBS:%=lib/%.a) solve.o gcd_lcm.o

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

%_test: %_test.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

test: gcd_lcm_test solve_test
	@./gcd_lcm_test
	@./solve_test

solve:
	@./main

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
