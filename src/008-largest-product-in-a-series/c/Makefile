DATAFILE = ../number.txt
CFLAGS += -Ilib -std=c99
LDFLAGS = -lm
LIBS =
DEPS = $(LIBS:%=lib/%.a) solve.o vec8.o

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

%_test: %_test.o $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)

test: solve_test vec8_test
	@./vec8_test
	@./solve_test

solve:
	@./main $(DATAFILE)

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
