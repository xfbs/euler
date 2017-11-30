main: main.o lib.o
	$(CC) $(CFLAGS) -o $@ $^

test: test.o lib.o
	$(CC) $(CFLAGS) -o $@ $^
	@./test

solve:
	@./main

clean:
	$(RM) *.o test main

build: main

.PHONY: build test clean
