CFLAGS += -Ilib -std=c99
LDFLAGS = -l
LIBS =
DEPS = $(LIBS:%=lib/%.a) solve.o palindrome.o

lib/%.a: lib/%.h lib/%.c
	cd lib && make $(notdir $@)

main: main.o $(DEPS)
	$(CC) $(LDFLAGS) -o $@ $^

%_test: %_test.o $(DEPS)
	@$(CC) $(LDFLAGS) -o $@ $^

test: solve_test palindrome_test
	@./palindrome_test
	@./solve_test

solve:
	@./main

clean:
	$(RM) *.o *_test main

build: main

.PHONY: build test clean
