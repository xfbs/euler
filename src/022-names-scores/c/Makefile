DATAFILE = ../names.txt
CFLAGS += -Ilib -std=c99
LIBS =
DEPS = $(LIBS:%=lib/%.a) solve.o vec.o

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) -o $@ $^

%_test: %_test.o $(DEPS)
	@$(CC) $(LDFLAGS) -o $@ $^

test: solve_test vec_test
	@./vec_test
	@./solve_test

solve:
	@./main $(DATAFILE)

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
